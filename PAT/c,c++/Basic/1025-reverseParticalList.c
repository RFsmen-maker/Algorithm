#include <stdio.h>
#include <string.h>

#define STLEN 7

struct list
{
        char address[STLEN];
        char nextAddress[STLEN];
        int number;
        struct list *previous;
        struct list *next;
};

int main(void)
{
        char headAddress[STLEN];
        int N, K;
        scanf("%s%d%d", headAddress, &N, &K);
        struct list List[N];
        struct list *head;
        struct list *tempNode;
        //input data
        for(int i = 0; i < N; i++)
        {
                scanf("%s%d%s", List[i].address,
                       &(List[i].number), List[i].nextAddress);
        }
        //find the head
        for(int i = 0; i < N; i++)
        {
                if(!strcmp(List[i].address, headAddress)) {
                        head = &List[i];
                        break;
                }
        }
        //link the list
        tempNode = head;
        for(int i = 0; i < N; i++)
        {
                for(int j = N-1; j >= 0; j--)
                {       //not the same place
                        if(!strcmp(tempNode->nextAddress, List[j].address)) {
                                tempNode->next = &List[j];
                                List[j].previous = tempNode;
                                tempNode = tempNode->next;
                                break;
                        }
                }
        }
        //reverse and output the list
        for(int i = 0; i < K-1; i++)
                head = head->next;
        tempNode = head;
        for(int i = 0; i < K-1; i++)
        {
                printf("%s %d %s\n", tempNode->address,
                       tempNode->number, tempNode->previous->address);
                if(i != K-1)
                        tempNode = tempNode->previous;
        }
        printf("%s %d %s\n", tempNode->address,
               tempNode->number, head->nextAddress);
        tempNode = head->next;
        for(int i = 0; i < N - K; i++)
        {
                printf("%s %d %s", tempNode->address,
                       tempNode->number, tempNode->nextAddress);
                if(i != N - K) {
                        putchar('\n');
                        tempNode = tempNode->next;
                }
        }

        return 0;
}
