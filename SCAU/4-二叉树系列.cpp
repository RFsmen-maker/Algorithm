/*
 * SCAU 二叉树系列
*/
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstdlib>

#define TRUE 1
#define FALSE 0
#define OK  1
#define ERROR  0
#define INFEASIBLE -1
#define OVERFLOW -2

using namespace std;

typedef int  Status;

typedef char  ElemType;
typedef struct BiTNode{
        ElemType data;
        BiTNode *lchild,*rchild;//左右孩子指针
} BiTNode,*BiTree;

Status CreateBiTree(BiTree &T) {  // 算法6.4
  // 按先序次序输入二叉树中结点的值（一个字符），’#’字符表示空树，
  // 构造二叉链表表示的二叉树T。
  char ch;
  scanf("%c",&ch);
  if (ch=='#') T = NULL;
  else {
    if (!(T = (BiTNode *)malloc(sizeof(BiTNode)))) return ERROR;
    T->data = ch;// 生成根结点
    T->lchild = T->rchild = nullptr;
    CreateBiTree(T->lchild);// 构造左子树
    CreateBiTree(T->rchild);// 构造右子树
  }
  return OK;
} // CreateBiTree

Status PreOrderTraverse( BiTree T) {
   // 前序遍历二叉树T的递归算法
  if (T == nullptr) return FALSE;
  char ch = T->data;
  cout << T->data;
  PreOrderTraverse(T->lchild);
  PreOrderTraverse(T->rchild);

  return OK;
} // PreOrderTraverse

Status InOrderTraverse( BiTree T) {
     // 中序遍历二叉树T的递归算法
  if (T == nullptr) return FALSE;
  InOrderTraverse(T->lchild);
  char ch = T->data;
  cout << T->data;
  InOrderTraverse(T->rchild);

  return OK;
} // InOrderTraverse

Status PostOrderTraverse( BiTree T) {
     // 后序遍历二叉树T的递归算法
  if (T == nullptr) return FALSE;
  PostOrderTraverse(T->lchild);
  PostOrderTraverse(T->rchild);
  char ch = T->data;
  cout << T->data;

  return OK;
} // PostOrderTraverse

// 1. 二叉树构建，错例：ABC####
void buildBiTree(void)
{
        BiTree btree;
        CreateBiTree(btree);
        PreOrderTraverse(btree);
        cout << endl;
        InOrderTraverse(btree);
        cout << endl;
        PostOrderTraverse(btree);
}

// 2. 二叉树各种节点数
void outCount_DFS(BiTree T, vector<int> &dest)
{
        if (T == nullptr) return;
        int count = 0;
        if (T->lchild != nullptr) count++;
        if (T->rchild != nullptr) count++;
        dest[count]++;

        outCount_DFS(T->lchild, dest);
        outCount_DFS(T->rchild, dest);
}
void nodeTypes(void)
{
        BiTree T;
        vector<int> dest(3, 0);
        CreateBiTree(T);
        outCount_DFS(T, dest);
        for (int i = 2; i >= 0; --i) cout << dest[i] << endl;
}

// 3. 求二叉树的宽，快速建树，使用 BFS
struct Node3 {
        int left, right;
};
void getBreadth(void)
{
        int n;
        cin >> n;
        vector<Node3> T(n+1, {0, 0});
        int x, y;
        for (int i = 1; i < n; ++i) {
                cin >> x >> y;
                if (T[x].left == 0) T[x].left = y;
                else T[x].right = y;
        }

        const int dummy = -1;
        int count, breadth = 0;
        queue<int> q;
        q.push(1);
        q.push(dummy);
        while (q.front() != dummy)
        {
                count = 0;
                while (q.front() != dummy)
                {
                        int l = T[q.front()].left;
                        if (l != 0) q.push(l);
                        int r = T[q.front()].right;
                        if (r != 0) q.push(r);
                        q.pop();
                        count++;
                        breadth = max(count, breadth);
                }
                q.push(dummy); // 加入分割点
                q.pop(); // 清除头 dummy
        }

        cout << breadth << endl;
}

// 4. 由先序和中序得到后序
struct Node4 {
        char data;
        Node4 *lchild, *rchild;
};
Node4* postDFS(string pre, int &cur, string in, int left, int right) { // 总是在 in[left, right] 中找 pre[cur]
        if (left > right) return nullptr;
        else {
                int index = left;
                while (index < right && pre[cur] != in[index]) index++; // 找到 pre[cur] 元素在中序遍历的位置
                Node4 *node = new Node4{pre[cur++], nullptr, nullptr};
                node->lchild = postDFS(pre, cur, in, left, index-1); // 往左边找
                node->rchild = postDFS(pre, cur, in, index+1, right); // 往右边找
                cout << node->data;
                return node;
        }
}
void getPostOrder(void)
{
        string pre, in;
        cin >> pre >> in;
        int len = pre.size();
        int cur = 0;
        postDFS(pre, cur, in, 0, len - 1);
}

// 5. 二叉树的直径：最深叶子与最浅叶子层数之和 - 2 + 2 * (-起始点层数)
// 仍然是要快速建树
// 问题在于：两个层数相等的情况，如单链，需要找到并计算起始点层数，直接使用偏移，找到就停止递减
struct Node5 {
        int left, right;
};
int minLeaf(vector<Node5> &T, int cur, int &offset, bool &flag, int &maxDepth, int level) {
        maxDepth = max(level, maxDepth);
        if (T[cur].left == 0 && T[cur].right == 0) return 1; // 没有左右子树的就是叶子
        if (T[cur].left != 0 && T[cur].right != 0) {// 第一次遇到两边都有子节点，即为起始点
                flag = true;
                return min(minLeaf(T, T[cur].left, offset, flag, maxDepth, level + 1) + 1
                           , minLeaf(T, T[cur].right, offset, flag, maxDepth, level + 1) + 1);
        }
        if (!flag) offset--; // 起始点继续深入
        int &left = T[cur].left != 0 ? T[cur].left : T[cur].right; // 其中一边有，还要继续往下
        return minLeaf(T, left, offset, flag, maxDepth, level + 1) + 1;
}
void getDiameter(void)
{
        int n;
        cin >> n;
        vector<Node5> T(n+1, {0, 0});
        int x, y;
        for (int i = 1; i < n; ++i) {
                cin >> x >> y; // 父结点、子结点
                if (T[x].left == 0) T[x].left = y; // 向下扩
                else T[x].right = y;
        }

        // 找最浅叶子结点层数、最深子节点层数，顺便找起始点（有左右子结点）
        bool flag = false;
        int offset = 0;
        int maxDepth = 1;
        int minDepth = minLeaf(T, 1, offset, flag, maxDepth, 1);
        if (!flag) cout << maxDepth - 1 << endl;
        else cout << minDepth + maxDepth + 2 * offset - 2 << endl;
}

// 6. 哈夫曼树，还不如自己重写...辣鸡代码
typedef char **HuffmanCode;
typedef struct{
        unsigned int weight;
        unsigned int parent, lchild, rchild;
}HTNode, *HuffmanTree;

void  Select(HuffmanTree &HT, int n, int &s1, int &s2) //在HT[1..n]中选择parent为0且weight最小的两个结点 s1, s2
{
        int i;
        s1 = -1; s2 = -1;
        for (i = 1; i <= n; ++i) {
                if (HT[i].parent == 0) {
                        if (s1 == -1) s1 = i;
                        else if (s2 == -1) if ()
                }
        }
    for (i=1;i<=n;i++) {
      if (HT[i].parent==0)
		if (s1==-1) s1=i;
		else
		  if (s2==-1 )
			if (HT[i].weight0) // 构造哈夫曼树HT 求出n个字符的哈夫曼编码HC
  int i, j, m, s1, s2, start;
  char *cd;
  unsigned int c, f;
  if (n<=1) return;
  m = 2 * n - 1;
  HT = (HuffmanTree)malloc((m+1) * sizeof(HTNode));  // 0号单元未用
  for (i=1; i<=n; i++) { //初始化
    HT[i].weight=w[i-1];
    HT[i].parent=0;
    HT[i].lchild=0;
    HT[i].rchild=0;
  }
  for (i=n+1; i<=m; i++) { //初始化
    HT[i].weight=0;
    HT[i].parent=0;
    HT[i].lchild=0;
    HT[i].rchild=0;
  }
  printf("\n哈夫曼树的构造过程如下所示：\n");
  printf("HT初态:\n  结点  weight  parent  lchild  rchild");
  for (i=1; i<=m; i++)
    printf("\n%4d%8d%8d%8d%8d",i,HT[i].weight,
            HT[i].parent,HT[i].lchild, HT[i].rchild);
    printf("    按任意键，继续 ...");
  getch();
  for (i=n+1; i<=m; i++) {  // 建哈夫曼树
    // 在HT[1..i-1]中选择parent为0且weight最小的两个结点，
    // 其序号分别为s1和s2。
    Select(HT, i-1, s1, s2);
    HT[s1].parent = i;  HT[s2].parent = i;
    HT[i].lchild = s1;  HT[i].rchild = s2;
    HT[i].weight = HT[s1].weight + HT[s2].weight;
    printf("\nselect: s1=%d   s2=%d\n", s1, s2);
    printf("  结点  weight  parent  lchild  rchild");
    for (j=1; j<=i; j++)
      printf("\n%4d%8d%8d%8d%8d",j,HT[j].weight,HT[j].parent,HT[j].lchild, HT[j].rchild);
    printf("    按任意键，继续 ...");
    getch();
  }
   //--- 从叶子到根逆向求每个字符的哈夫曼编码 ---
  cd = (char *)malloc(n*sizeof(char));    // 分配求编码的工作空间
  cd[n-1] = '\0';                         // 编码结束符。
  for (i=1; i<=n; ++i) {                  // 逐个字符求哈夫曼编码
    start = n-1;                          // 编码结束符位置
    for (c=i, f=HT[i].parent; f!=0; c=f, f=HT[f].parent)
      // 从叶子到根逆向求编码
      if (HT[f].lchild==c) cd[--start] = '0';
      else cd[--start] = '1';
    HC[i] = (char *)malloc((n-start)*sizeof(char));
         // 为第i个字符编码分配空间
    strcpy(HC[i], &cd[start]);    // 从cd复制编码(串)到HC

  }
  free(cd);   //释放工作空间
} //HuffmanCoding

void getHuffmanCode(void)
{
   int i,n;
   int *w;
   HuffmanTree HT;
   HuffmanCode HC;
   printf("Node Number:");
   scanf("%d",&n);  //权值个数
   w=(int *)malloc(n*sizeof(int));
   printf("Input weights:");
   for ( i=0;i<n;i++)  //录入权值
	 scanf("%d",&w[i]);

   HC=(char **)malloc((n+1)*sizeof(char*)); //0空间未用
   HT=(HuffmanTree)malloc((2*n+1+1)*sizeof(HTNode));//0空间未用
   HuffmanCoding(HT, HC, w, n);
   printf("\n");
   for (i = 1; i<n+1; i++){
	 puts(HC[i]);  //输出哈夫曼编码
	 free(HC[i]);  //释放空间
   }
   free(HC);
   free(HT);
}//main

int main(void)
{
        getHuffmanCode();

        return 0;
}
