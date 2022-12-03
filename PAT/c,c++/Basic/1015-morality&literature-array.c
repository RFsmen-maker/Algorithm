#include <stdio.h>
#include <stdlib.h>

#define MAX 100010

typedef struct student {
        int sequence, de ,cai;
}Student;

int main(void)
{
        Student list[4][MAX];
        int rk[4];
        rk[0] = rk[1] = rk[2] = rk[3] = 0;
        int N, L, H;
        scanf("%d%d%d", &N, &L, &H);
        int pass = N;
        for(int i = 0; i < N; i++)
        {
                Student temp;
                scanf("%d%d%d", &temp.sequence, &temp.de, &temp.cai);
                if(temp.de >= L && temp.cai >= L) {
                        int select = (temp.de >= H && temp.cai >= H) ? 0 : (temp.de >= H ? 1 : (temp.de >= temp.cai ? 2 : 3) );
                        //printf("select = %d\n", select);
                        list[select][rk[select]++] = temp;
                }
                else
                        pass--;
        }

        printf("%d\n", pass);

        for(int i = 0; i < 4; i++)
        {
                for(int j = 0; j < rk[i] - 1; j++)
                {
                        for(int k = 0; k < rk[i] - j - 1; k++)
                        {
                                if(list[i][k].cai + list[i][k].de < list[i][k+1].cai + list[i][k+1].de)
                                {
                                        Student temp = list[i][k];
                                        list[i][k] = list[i][k+1];
                                        list[i][k+1] = temp;
                                }
                                if(list[i][k].cai + list[i][k].de == list[i][k+1].cai + list[i][k+1].de)
                                {
                                        if(list[i][k].de < list[i][k+1].de)
                                        {
                                                Student temp = list[i][k];
                                                list[i][k] = list[i][k+1];
                                                list[i][k+1] = temp;
                                        }
                                        if(list[i][k].de == list[i][k+1].de)
                                        {
                                                if(list[i][k].sequence > list[i][k+1].sequence)
                                                {
                                                        Student temp = list[i][k];
                                                        list[i][k] = list[i][k+1];
                                                        list[i][k+1] = temp;
                                                }
                                        }
                                }
                        }
                }
        }

        for(int i = 0; i < 4; i++)
                for(int j = 0; j < rk[i]; j++)
                        printf("%d %d %d\n", list[i][j].sequence, list[i][j].de, list[i][j].cai);

        return 0;
}
