#include <stdio.h>
#include <stdlib.h>

/*
ʹ������β�巨��������
v0.1 : ��д���������壬������������࣬��������
v0.2 : ��ɲ�������������޸����������� bug
v0.2.1 : ���˰汾����������ṹ���ִ������¿�ʼ���ȳ��¿α�����ѧϰ���
v0.3 : ��ʼ����д��������������ຯ�����������
v0.4 : ���������뺯�������ÿ�β�������ʾ����
v0.5 : �������ԣ���ɲ��뺯�����ͷ��ڴ溯����������������
v0.6 : ����������Ӻ��������� bug�������������˳������������߼�����
v0.7 : ��д����������ɻ������򣬷���ֻ�����˵·�����
v0.8 : ��鷢��û�и��ṹ���е� total ��ֵ
v0.9 : PTA ��ֻ�в���ͨ�����÷֣�16
*/
typedef struct student {
        unsigned long sequence; //ѧ��
        int de; //�·�
        int cai; //�ŷ�
        int total; //�ܷ�
        struct student * next;
}Student;

typedef Student *List;

static int input(List *plist);
static void output(List *plist);
static void insert(List *plist, List *temp);
static int linkChain(List *head, List *rear); //�ɹ����ӷ���0��ʧ�ܷ���1
static void cleanUp(List *list);

static int input(List *rankList)
{
        List list[4];
        list[0] = list[1] = list[2] = list[3] = NULL;
        int N, L, H; //�����������ߡ�������
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
                int select; //0 : current �� scan ǰ; 1 : current �� scan ��
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

                if(select) { //current �� scan ��
                        current->next = scan->next;
                        scan->next = current;
                }
                else { //current �� scan ǰ
                        if(prev == scan) { //��� scan ��ͷ
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
