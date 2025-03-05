#include<stdio.h>

void main()

{
    int n, m, i, j, avl[30], max[30][30], d = 0, alloc[30][30];
    printf("\n Enter no of processes");
    scanf("%d", & n);
    printf("\n Enter no of resources");
    scanf("%d", & m);
    int T[m];
    printf("\n enter imstances of resources");
    for (j = 0; j < m; j++)
        scanf("%d", & T[j]);
    printf("\n Enter the allocation matrix");
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            scanf("%d", & alloc[i][j]);
        }
    }
    printf("\n ENter max matrix\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            scanf("%d", & max[i][j]);
        }
    }
    for (j = 0; j < m; j++) {
        int c = 0;
        for (i = 0; i < n; i++)
            c = c + alloc[i][j];
        avl[j] = T[j] - c;
    }
    int finish[n], safeseq[n], work[n], need[n][m];
    for (i = 0; i < m; i++)
        work[i] = avl[i];
    for (i = 0; i < n; i++)
        finish[i] = 0;
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++)
            need[i][j] = max[i][j] - alloc[i][j];
    }
    printf("\n Need matrix");
    for (i = 0; i < n; i++) {
        printf("\n");
        for (j = 0; j < m; j++)
            printf("%d", need[i][j]);
    }
    for (int k = 0; k < n; k++) {
        for (i = 0; i < n; i++) {
            if (finish[i] == 0) {
                int flag = 0;
                for (j = 0; j < m; j++) {
                    if (need[i][j] > work[j]) {
                        flag = 1;
                        break;
                    }
                }
                if (flag == 0) {
                    safeseq[d++] = i;
                    for (int a = 0; a < m; a++)
                        work[a] = work[a] + alloc[i][a];
                    finish[i] = 1;
                }
            }
        }
    }
    int c = 0;
    for (i = 0; i < n; i++) {
        if (finish[i] == 1)
            c++;
    }
    if (c == n) {
        printf("\n Safe sequence");
        for (i = 0; i < n; i++)
            printf("P%d", safeseq[i]);
        printf("\n");
    } else {
        printf("Not safe");
    }
}