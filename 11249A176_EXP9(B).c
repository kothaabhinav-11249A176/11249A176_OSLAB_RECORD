#include <stdio.h>
int main() {
    int nb, np, i, j;
    int block[20], process[20], allocation[20];
    printf("Enter number of blocks: ");
    scanf("%d", &nb);
    printf("Enter size of each block:\n");
    for (i = 0; i < nb; i++) {
        printf("Block %d: ", i + 1);
        scanf("%d", &block[i]);
    }
    printf("\nEnter number of processes: ");
    scanf("%d", &np);
    printf("Enter size of each process:\n");
    for (i = 0; i < np; i++) {
        printf("Process %d: ", i + 1);
        scanf("%d", &process[i]);
        allocation[i] = -1;
    }
    for (i = 0; i < np; i++) {
        int bestIdx = -1;
        for (j = 0; j < nb; j++) {
            if (block[j] >= process[i]) {
                if (bestIdx == -1 || block[j] < block[bestIdx]) {
                    bestIdx = j;
                }
            }
        }
        if (bestIdx != -1) {
            allocation[i] = bestIdx;
            block[bestIdx] -= process[i];
        }
    }
    printf("\nProcess No.\tProcess Size\tBlock No.\n");
    for (i = 0; i < np; i++) {
        printf(" %d \t\t %d \t\t", i + 1, process[i]);
        if (allocation[i] != -1)
            printf(" %d\n", allocation[i] + 1);
        else
            printf("Not Allocated\n");
    }
    return 0;
}
}
