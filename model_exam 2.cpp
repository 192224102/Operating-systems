#include <stdio.h>
#define MAX_FRAMES 3
#define MAX_PAGES 20
int main() {
    int frames[MAX_FRAMES];
    int pages[MAX_PAGES];
    int pageFaults = 0;
    int used[MAX_FRAMES] = {0};
    int i, j, k;
    for (i = 0; i < MAX_FRAMES; i++) {
        frames[i] = -1;
    }
    printf("Enter the number of pages: ");
    int numPages;
    scanf("%d", &numPages);
    printf("Enter the page reference string: ");
    for (i = 0; i < numPages; i++) {
        scanf("%d", &pages[i]);
    }
    printf("\nPage Reference String: ");
    for (i = 0; i < numPages; i++) {
        printf("%d ", pages[i]);
    }
    printf("\n\n");
    printf("Frames\t\tPage\n");
    for (i = 0; i < numPages; i++) {
        printf(" ");
        int isPageFault = 1;
        for (j = 0; j < MAX_FRAMES; j++) {
            if (frames[j] == pages[i]) {
                isPageFault = 0;
                used[j] = i;
                break;
            }
        }
        if (isPageFault) {
            int leastUsedIndex = 0;
            for (j = 1; j < MAX_FRAMES; j++) {
                if (used[j] < used[leastUsedIndex]) {
                    leastUsedIndex = j;
                }
            }
            frames[leastUsedIndex] = pages[i];
            used[leastUsedIndex] = i;
            printf("  %d ->\t\t%d\n", frames[leastUsedIndex], pages[i]);
            pageFaults++;
        } else {
            printf("   \t\t%d\n", pages[i]);
        }
        for (k = 0; k < MAX_FRAMES; k++) {
            printf("%d ", frames[k]);
        }
        printf("\n");
    }
    printf("\nTotal Page Faults: %d\n", pageFaults);
    return 0;
}
