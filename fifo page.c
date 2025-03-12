#include <stdio.h>

void main() { 
    int ref[25], fr[5], n, i, k, f, fi = 0, faults = 0, miss;

    printf("Enter the length of reference string:\n");
    scanf("%d", &n);

    printf("Enter the reference string:\n");
    for (i = 0; i < n; i++)
        scanf("%d", &ref[i]);

    printf("Enter the number of page frames:\n");
    scanf("%d", &f);

    // Initialize frames to -1 (empty)
    for (i = 0; i < f; i++)
        fr[i] = -1;

    // Page replacement process
    for (i = 0; i < n; i++) {
        miss = 1; // Page not found

        // Check if page is already in frame
        for (k = 0; k < f; k++) { 
            if (ref[i] == fr[k]) {
                miss = 0; // Page hit
                break;
            }
        } 

        // If page is not found, replace using FIFO
        if (miss) { 
            fr[fi] = ref[i]; // Replace oldest page
            faults++;         // Increment page fault count
            fi = (fi + 1) % f; // FIFO index update
        }

        // Print the frame state
        printf("\nFrame state after page %d: ", ref[i]);
        for (k = 0; k < f; k++) { 
            if (fr[k] != -1)
                printf("%d ", fr[k]);
            else
                printf("- ");
        }  
    }

    // Print total page faults
    printf("\nNumber of page faults is %d\n", faults);
}