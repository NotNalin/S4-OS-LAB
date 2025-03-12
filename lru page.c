#include <stdio.h>

int main() {
    int frames, pages[100], n;
    int frame[10], time[10];
    int i, j, k, pos, counter = 0;
    int flag1 = 0, flag2 = 0, faults = 0, min;

    // Input section
    printf("Enter number of frames: ");
    scanf("%d", &frames);

    printf("Enter number of pages: ");
    scanf("%d", &n);

    printf("Enter the page reference string: ");
    for (i = 0; i < n; ++i) {
        scanf("%d", &pages[i]);
    }

    // Initialize frames as empty
    for (i = 0; i < frames; ++i) {
        frame[i] = -1;
    }

    // Start page replacement
    for (i = 0; i < n; ++i) {
        flag1 = flag2 = 0;

        // Check if page is already in frame (Page Hit)
        for (j = 0; j < frames; ++j) {
            if (frame[j] == pages[i]) {
                counter++;
                time[j] = counter;
                flag1 = flag2 = 1;
                break;
            }
        }

        // If page is not in frame (Page Fault) and empty frame is available
        if (flag1 == 0) {
            for (j = 0; j < frames; ++j) {
                if (frame[j] == -1) {
                    counter++;
                    faults++;
                    frame[j] = pages[i];
                    time[j] = counter;
                    flag2 = 1;
                    break;
                }
            }
        }

        // If no empty frame → find LRU and replace
        if (flag2 == 0) {
            min = time[0];
            pos = 0;
            for (j = 1; j < frames; ++j) {
                if (time[j] < min) {
                    min = time[j];
                    pos = j;
                }
            }

            counter++;
            faults++;
            frame[pos] = pages[i];
            time[pos] = counter;
        }

        // Print current frame status
        printf("\nFrame state after page %d: ", pages[i]);
        for (k = 0; k < frames; ++k) {
            if (frame[k] != -1)
                printf("%d ", frame[k]);
            else
                printf("- ");
        }
    }

    // Total page faults
    printf("\n\nTotal Page Faults = %d\n", faults);

    return 0;
}