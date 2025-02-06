#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void main()
{
    int num;
    double AWT = 0, ATAT = 0;
    printf("Enter number of processes: ");
    scanf("%d", &num);

    // Arrays to store process details
    int ID[num], AT[num], BT[num], CT[num], WT[num], TAT[num];

    // Input process details
    for (int i = 0; i < num; i++)
    {
        printf("Enter ID, BT, AT for process %d: ", i + 1);
        scanf("%d %d %d", &ID[i], &BT[i], &AT[i]);
    }

    // Sort processes based on Arrival Time (AT) and, if equal, by ID
    for (int i = 0; i < num - 1; i++)
    {
        for (int j = 0; j < num - i - 1; j++)
        {
            if (AT[j] > AT[j + 1])
            {
                swap(&ID[j], &ID[j + 1]);
                swap(&AT[j], &AT[j + 1]);
                swap(&BT[j], &BT[j + 1]);
            }
            else if (AT[j] == AT[j + 1])
            {
                if (ID[j] > ID[j + 1])
                {
                    swap(&ID[j], &ID[j + 1]);
                    swap(&AT[j], &AT[j + 1]);
                    swap(&BT[j], &BT[j + 1]);
                }
            }
        }
    }

    // Calculate Completion Time (CT), Turnaround Time (TAT), and Waiting Time (WT)
    CT[0] = AT[0] + BT[0];
    TAT[0] = CT[0] - AT[0];
    WT[0] = TAT[0] - BT[0];

    for (int i = 1; i < num; i++)
    {
        CT[i] = CT[i - 1] + BT[i];
        TAT[i] = CT[i] - AT[i];
        WT[i] = TAT[i] - BT[i];
    }

    // Calculate Average Waiting Time (AWT) and Average Turnaround Time (ATAT)
    for (int i = 0; i < num; i++)
    {
        AWT += WT[i];
        ATAT += TAT[i];
    }
    AWT /= num;
    ATAT /= num;

    // Sort processes based on ID
    for (int i = 0; i < num - 1; i++)
    {
        for (int j = 0; j < num - i - 1; j++)
        {
            if (ID[j] > ID[j + 1])
            {
                swap(&ID[j], &ID[j + 1]);
                swap(&AT[j], &AT[j + 1]);
                swap(&BT[j], &BT[j + 1]);
                swap(&CT[j], &CT[j + 1]);
                swap(&WT[j], &WT[j + 1]);
                swap(&TAT[j], &TAT[j + 1]);
            }
        }
    }

    // Print the results
    printf("\nID\tAT\tBT\tWT\tTAT\n");
    for (int i = 0; i < num; i++)
    {
        printf("%d\t%d\t%d\t%d\t%d\n", ID[i], AT[i], BT[i], WT[i], TAT[i]);
    }
    printf("AWT : %f\n", AWT);
    printf("ATAT : %f\n", ATAT);
}