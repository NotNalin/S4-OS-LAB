#include <stdio.h>

struct process
{
    int id;
    int size;
};

struct memory
{
    int id;
    int size;
};

void main()
{
    int pno, bno;
    printf("Enter No of processes : ");
    scanf("%d", &pno);
    struct process pl[pno];
    printf("Enter No of Memory locations : ");
    scanf("%d", &bno);
    struct memory bl[bno];
    printf("\nEnter processes :\n");
    for (int i = 0; i < pno; i++)
    {
        printf("Enter process ID and size : ");
        scanf("%d%d", &pl[i].id, &pl[i].size);
    }
    printf("\nEnter Memory locations :\n");
    for (int i = 0; i < bno; i++)
    {
        printf("Enter memory ID and size : ");
        scanf("%d%d", &bl[i].id, &bl[i].size);
    }
    printf("\nProcess id\tSize\tBlock id");
    for (int i = 0; i < pno; i++)
    {
        int max = -1;
        for (int j = 0; j < bno; j++)
        {
            if (pl[i].size <= bl[j].size)
            {
                if (max == -1 || bl[j].size > bl[max].size)
                {
                    max = j;
                }
            }
        }
        if (max != -1)
        {
            bl[max].size = bl[max].size - pl[i].size;
            printf("P%d\t\t%d\tB%d\n", pl[i].id, pl[i].size, bl[max].id);
        }
        else
        {
            printf("P%d\t\t%d\tNot Allocated\n", pl[i].id, pl[i].size);
        }
    }
}
