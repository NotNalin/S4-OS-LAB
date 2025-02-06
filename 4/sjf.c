#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Function to swap two integers
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main() {
    int num;
    double AWT = 0, ATAT = 0;

    printf("Enter number of processes: ");
    scanf("%d", &num);

    // Arrays for process details
    int ID[num], AT[num], BT[num], CT[num], WT[num], TAT[num];

    // Taking input
    for (int i = 0; i < num; i++) {
        printf("Enter ID, BT, AT for process %d: ", i + 1);
        scanf("%d %d %d", &ID[i], &BT[i], &AT[i]);
    }

    // Initial sorting based on Arrival Time (AT)
    for (int i = 0; i < num - 1; i++) {
        for (int j = 0; j < num - i - 1; j++) {
            if (AT[j] > AT[j + 1]) {
                swap(&AT[j], &AT[j + 1]);
                swap(&BT[j], &BT[j + 1]);
                swap(&ID[j], &ID[j + 1]);
            }
        }
    }

    int time = 0, completed = 0, over = 0;

    while (completed < num) {
        int count = 0;

        // Count how many processes have arrived
        for (int i = over; i < num; i++) {
            if (AT[i] <= time) {
                count++;
            }
        }

        // If more than one process is ready, sort the ready ones by BT (Shortest Job First)
        if (count > 1) {
            for (int i = over; i < over + count - 1; i++) {
                for (int j = over; j < over + count - 1 - (i - over); j++) {
                    if (BT[j] > BT[j + 1]) {
                        swap(&BT[j], &BT[j + 1]);
                        swap(&AT[j], &AT[j + 1]);
                        swap(&ID[j], &ID[j + 1]);
                    }
                }
            }
        }

        // If no process has arrived yet, jump to the next available process
        if (AT[over] > time) {
            time = AT[over];
        }

        // Schedule process at index `over`
        int start = time;
        CT[over] = time + BT[over];
        TAT[over] = CT[over] - AT[over];
        WT[over] = TAT[over] - BT[over];

        // Move to next process and update time
        printf("Scheduled Process: ID=%d, BT=%d, Start=%d, Completion=%d\n", ID[over], BT[over], start, CT[over]);
        time = CT[over];
        over++;
        completed++;
    }

    // Calculate Averages
    for (int i = 0; i < num; i++) {
        AWT += WT[i];
        ATAT += TAT[i];
    }
    AWT /= num;
    ATAT /= num;

    // Final Table Output
    printf("\nID\tAT\tBT\tCT\tWT\tTAT\n");
    for (int i = 0; i < num; i++) {
        printf("%d\t%d\t%d\t%d\t%d\t%d\n", ID[i], AT[i], BT[i], CT[i], WT[i], TAT[i]);
    }
    printf("Average Waiting Time: %.2f\n", AWT);
    printf("Average Turnaround Time: %.2f\n", ATAT);

    return 0;
}
