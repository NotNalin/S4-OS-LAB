#include <stdio.h>
#include <stdlib.h>
struct process
{
    int ID;
    int AT;
    int BT;
    int CT;
    int WT;
    int TAT;
    int f;
};
void main()
{
    int Q[20];
    int l, num, k, m, tq, c = 0;
    double AWT = 0, ATAT = 0;
    printf("Enter the number of processes: ");
    scanf("%d", &num);
    struct process pl[num];
    printf("Enter time quantum: ");
    scanf("%d", &tq);
    for (int i = 0; i < num; i++)
    {
        printf("Enter the process ID, AT, BT: ");
        scanf("%d%d%d", &pl[i].ID, &pl[i].AT, &pl[i].BT);
        pl[i].f = pl[i].BT;
        Q[i] = i;
        l = i;
    }
    k = 0;
    m = 0;
    while (k <= l)
    {
        m = Q[k];
        if (pl[m].f > tq)
        {
            c = c + tq;
            pl[m].f = pl[m].f - tq;
            pl[m].CT = c;
            l++;
            Q[l] = m;
        }
        else
        {
            c = c + pl[m].f;
            pl[m].CT = c;
        }
        k++;
    }
    for (int i = 0; i < num; i++)
    {
        pl[i].TAT = pl[i].CT - pl[i].AT;
        pl[i].WT = pl[i].TAT - pl[i].BT;
    }
    for (int i = 0; i < num; i++)
    {
        AWT = AWT + pl[i].WT;
        ATAT = ATAT + pl[i].TAT;
    }
    AWT = AWT / num;
    ATAT = ATAT / num;
    for (int i = 0; i < num - 1; i++)
    {
        for (int j = 0; j < num - i - 1; j++)
        {
            if (pl[j].ID > pl[j + 1].ID)
            {
                struct process temp = pl[j];
                pl[j] = pl[j + 1];
                pl[j + 1] = temp;
            }
        }
    }
    printf("\nID\tAT\tBT\tCT\tWT\tTAT\n");
    for (int i = 0; i < num; i++)
        printf("%d\t%d\t%d\t%d\t%d\t%d\n", pl[i].ID, pl[i].AT, pl[i].BT, pl[i].CT, pl[i].WT, pl[i].TAT);
    printf("AWT : %f\n", AWT);
    printf("ATAT : %f\n", ATAT);
}