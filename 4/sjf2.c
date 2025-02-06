#include <stdio.h>
#include <limits.h>

int main()
{
    int n, i, min_bt, min_idx, time = 0, completed = 0;
    float AWT = 0, ATAT = 0;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    int BT[n], AT[n], WT[n], TAT[n], DONE[n];

    for (i = 0; i < n; i++)
    {
        printf("Enter arrival time and burst time for process %d: ", i + 1);
        scanf("%d %d", &AT[i], &BT[i]);
        DONE[i] = 0;
    }

    while (completed < n)
    {
        min_bt = INT_MAX;
        min_idx = -1;

        for (i = 0; i < n; i++)
        {
            if (!DONE[i] && AT[i] <= time && BT[i] < min_bt)
            {
                min_bt = BT[i];
                min_idx = i;
            }
        }

        if (min_idx == -1)
        {
            time++;
            continue;
        }

        time += BT[min_idx];
        TAT[min_idx] = time - AT[min_idx];
        WT[min_idx] = TAT[min_idx] - BT[min_idx];

        AWT += WT[min_idx];
        ATAT += TAT[min_idx];

        DONE[min_idx] = 1;
        completed++;
    }

    printf("\nSJF Scheduling:\nPID\tWT\tTAT\n");
    for (i = 0; i < n; i++)
        printf("%d\t%d\t%d\n", i + 1, WT[i], TAT[i]);

    printf("Average Waiting Time: %.2f\n", AWT / n);
    printf("Average Turnaround Time: %.2f\n", ATAT / n);

    return 0;
}
