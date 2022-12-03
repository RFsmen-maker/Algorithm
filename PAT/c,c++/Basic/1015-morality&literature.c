#include <stdio.h>
#include <stdlib.h>

/*
使用链表尾插法进行排序
v0.1 : 编写基本机构体，输入输出、分类，链表链接
v0.2 : 完成插入链表操作，修复了链表链接 bug
v0.2.1 : 回退版本，链表基本结构出现错误，重新开始，先抄下课本进行学习理解
v0.3 : 开始，编写主函数，输入分类函数、输出函数
v0.4 : 继续，插入函数，添加每次插入后的显示测试
v0.5 : 撤销测试，完成插入函数、释放内存函数，留下链接链表
v0.6 : 完成链表链接函数，测试 bug，可输入输出，顺序错误，排序函数逻辑错误
v0.7 : 重写排序函数，完成基本排序，发现只按照了德分排序
v0.8 : 检查发现没有给结构体中的 total 赋值
v0.9 : PTA 中只有部分通过，得分：16
*/
typedef struct student {
        unsigned long sequence; //学号
        int de; //德分
        int cai; //才分
        int total; //总分
        struct student * next;
}Student;

typedef Student *List;

static int input(List *plist);
static void output(List *plist);
static void insert(List *plist, List *temp);
static int linkChain(List *head, List *rear); //成功连接返回0，失败返回1
static void cleanUp(List *list);

static int input(List *rankList)
{
        List list[4];
        list[0] = list[1] = list[2] = list[3] = NULL;
        int N, L, H; //人数、分数线、择优线
        scanf("%d%d%d", &N, &L, &H);
        int pass = N;
        while(N--)
        {
                List temp = (List)malloc(sizeof(Student));
                scanf("%lu%d%d", &temp->sequence, &temp->de, &temp->cai);
                temp->total = temp->de + temp->cai;
                temp->next = NULL;
                if(temp->de >= L && temp->cai >= L) {
                        int select = ( temp->de >= H && temp->cai >= H ) ? 0 : ( temp->de >= H ? 1 : ( temp->de >= temp->cai ? 2 : 3 ) );
                        //printf("select = %d\n", select);
                        insert(&list[select], &temp);
                }
                else
                        pass--;
        }
        linkChain(&list[2], &list[3]);
        linkChain(&list[1], &list[2]);
        linkChain(&list[0], &list[1]);

        *rankList = list[0];
        return pass;
}

static void output(List *plist)
{
        Student *temp = *plist;
        while(temp != NULL)
        {
                printf("%lu %d %d", temp->sequence, temp->de, temp->cai);
                temp = temp->next;
                if(temp != NULL)
                        putchar('\n');
        }
}

static void insert(List *plist, List *temp)
{
        Student *current = *temp;
        Student *scan = *plist;
        Student *prev = scan;
        if(scan == NULL) {
                scan = *plist = *temp;
                (*temp)->next = NULL;
        }
        else {
                int select; //0 : current 在 scan 前; 1 : current 在 scan 后
                while(1)
                {
                        if(scan->total > current->total) {
                                if(scan->next != NULL) {
                                        prev = scan;
                                        scan = scan->next;
                                        continue;
                                }
                                else {
                                        select = 1;
                                        break;
                                }
                        }
                        else if(scan->total == current->total) {
                                while(1)
                                {
                                        if(scan->total == current->total) {
                                                if(scan->de < current->de) {
                                                        select = 0;
                                                        break;
                                                }
                                                else if(scan->de == current->de) {
                                                        if(scan->sequence > current->sequence) {
                                                                select = 0;
                                                                break;
                                                        }
                                                        else {
                                                                if(scan->next == NULL) {
                                                                        select = 1;
                                                                        break;
                                                                }
                                                                else {
                                                                        prev = scan;
                                                                        scan = scan->next;
                                                                        continue;
                                                                }
                                                        }
                                                }
                                                else { //scan->de > current->de
                                                        if(scan->next == NULL) {
                                                                select = 1;
                                                                break;
                                                        }
                                                        else {
                                                                prev = scan;
                                                                scan = scan->next;
                                                                continue;
                                                        }
                                                }
                                        }
                                        else {
                                                select = 1;
                                                break;
                                        }
                                }
                                break;
                        }
                        else { //scan->total < current->total
                                select = 0;
                                break;
                        }
                }

                if(select) { //current 在 scan 后
                        current->next = scan->next;
                        scan->next = current;
                }
                else { //current 在 scan 前
                        if(prev == scan) { //如果 scan 在头
                                current->next = scan;
                                *plist = current;
                        }
                        else {
                                prev->next = current;
                                current->next = scan;
                        }
                }
        }
}

static int linkChain(List *head, List *rear)
{
        Student *scan = *head;
        if(rear == NULL)
                return 1;
        else if(scan == NULL) {
                *head = *rear;
        }
        else if (scan != NULL)
        {
                while(scan->next != NULL)
                       scan = scan->next;
                scan->next = *rear;
        }

        return 0;
}

static void cleanUp(List *list)
{
        Student *scan;
        scan = *list;
        while(scan != NULL)
        {
                (*list) = (*list)->next;
                free(scan);
                scan = *list;
        }
}

int main(void)
{
        List rankList;
        int pass = input(&rankList);

        printf("%d\n", pass);
        output(&rankList);

        cleanUp(&rankList);

        return 0;
}
