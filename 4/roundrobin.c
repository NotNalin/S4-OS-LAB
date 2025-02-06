#include <stdio.h>

int main() {
    int n, i, time = 0, completed = 0, quantum, executed;
    float AWT = 0, ATAT = 0;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    int BT[n], AT[n], RT[n], WT[n], TAT[n];

    for (i = 0; i < n; i++) {
        printf("Enter arrival time and burst time for process %d: ", i + 1);
        scanf("%d %d", &AT[i], &BT[i]);
        RT[i] = BT[i];
    }

    printf("Enter time quantum: ");
    scanf("%d", &quantum);

    while (completed < n) {
        executed = 0;

        for (i = 0; i < n; i++) {
            if (RT[i] > 0 && AT[i] <= time) {
                int exec_time = (RT[i] > quantum) ? quantum : RT[i];
                RT[i] -= exec_time;
                time += exec_time;

                if (RT[i] == 0) {
                    completed++;
                    TAT[i] = time - AT[i];
                    WT[i] = TAT[i] - BT[i];

                    AWT += WT[i];
                    ATAT += TAT[i];
                }
                executed = 1;
            }
        }
        if (!executed) time++;
    }

    printf("\nRound Robin Scheduling:\nPID\tWT\tTAT\n");
    for (i = 0; i < n; i++) printf("%d\t%d\t%d\n", i + 1, WT[i], TAT[i]);

    printf("Average Waiting Time: %.2f\n", AWT / n);
    printf("Average Turnaround Time: %.2f\n", ATAT / n);

    return 0;
}
