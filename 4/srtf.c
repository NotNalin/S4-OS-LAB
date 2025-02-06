#include <stdio.h>
#include <limits.h>

int main()
{
    int n, i, min_rt, min_idx, time = 0, completed = 0;
    float AWT = 0, ATAT = 0;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    int BT[n], AT[n], RT[n], WT[n], TAT[n];

    for (i = 0; i < n; i++)
    {
        printf("Enter arrival time and burst time for process %d: ", i + 1);
        scanf("%d %d", &AT[i], &BT[i]);
        RT[i] = BT[i];
    }

    while (completed < n)
    {
        min_rt = INT_MAX;
        min_idx = -1;

        for (i = 0; i < n; i++)
        {
            if (AT[i] <= time && RT[i] > 0 && RT[i] < min_rt)
            {
                min_rt = RT[i];
                min_idx = i;
            }
        }

        if (min_idx == -1)
        {
            time++;
            continue;
        }

        RT[min_idx]--;
        time++;

        if (RT[min_idx] == 0)
        {
            completed++;
            TAT[min_idx] = time - AT[min_idx];
            WT[min_idx] = TAT[min_idx] - BT[min_idx];

            AWT += WT[min_idx];
            ATAT += TAT[min_idx];
        }
    }

    printf("\nSRTF Scheduling:\nPID\tWT\tTAT\n");
    for (i = 0; i < n; i++)
        printf("%d\t%d\t%d\n", i + 1, WT[i], TAT[i]);

    printf("Average Waiting Time: %.2f\n", AWT / n);
    printf("Average Turnaround Time: %.2f\n", ATAT / n);

    return 0;
}
