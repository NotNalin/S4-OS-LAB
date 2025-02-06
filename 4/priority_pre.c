#include <stdio.h>
#include <limits.h>

int main()
{
    int n, i, min_priority, min_idx, time = 0, completed = 0;
    float AWT = 0, ATAT = 0;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    int BT[n], AT[n], RT[n], PRIORITY[n], WT[n], TAT[n];

    for (i = 0; i < n; i++)
    {
        printf("Enter arrival time, burst time, and priority for process %d: ", i + 1);
        scanf("%d %d %d", &AT[i], &BT[i], &PRIORITY[i]);
        RT[i] = BT[i]; // Remaining time initialized as burst time
    }

    while (completed < n)
    {
        min_priority = INT_MAX;
        min_idx = -1;

        for (i = 0; i < n; i++)
        {
            if (AT[i] <= time && RT[i] > 0 && PRIORITY[i] < min_priority)
            {
                min_priority = PRIORITY[i];
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
        { // Process completed
            completed++;
            TAT[min_idx] = time - AT[min_idx];
            WT[min_idx] = TAT[min_idx] - BT[min_idx];

            AWT += WT[min_idx];
            ATAT += TAT[min_idx];
        }
    }

    printf("\nPreemptive Priority Scheduling:\nPID\tWT\tTAT\n");
    for (i = 0; i < n; i++)
        printf("%d\t%d\t%d\n", i + 1, WT[i], TAT[i]);

    printf("Average Waiting Time: %.2f\n", AWT / n);
    printf("Average Turnaround Time: %.2f\n", ATAT / n);

    return 0;
}
