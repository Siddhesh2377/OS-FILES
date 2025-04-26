// Optimal Page Replacement Algorithm Implementation in C

#include <stdio.h>

int main() {
    int frames, pages, i, j, k, page_faults = 0, max, index, found, next_use;
    int page[50], frame[10];

    printf("Enter number of frames: ");
    scanf("%d", &frames);

    printf("Enter number of pages: ");
    scanf("%d", &pages);

    printf("Enter page reference string: ");
    for(i = 0; i < pages; i++) {
        scanf("%d", &page[i]);
    }

    for(i = 0; i < frames; i++) {
        frame[i] = -1; // Initialize frames
    }

    printf("\nPage\tFrames\n");

    for(i = 0; i < pages; i++) {
        found = 0;

        // Check if page already in frame
        for(j = 0; j < frames; j++) {
            if(frame[j] == page[i]) {
                found = 1;
                break;
            }
        }

        // If page not found, need replacement
        if(found == 0) {
            // Check for empty frame
            int empty = -1;
            for(j = 0; j < frames; j++) {
                if(frame[j] == -1) {
                    empty = j;
                    break;
                }
            }

            if(empty != -1) {
                frame[empty] = page[i];
            } else {
                // Find the page not used for the longest future time
                max = -1;
                index = -1;
                for(j = 0; j < frames; j++) {
                    next_use = -1;
                    for(k = i+1; k < pages; k++) {
                        if(frame[j] == page[k]) {
                            next_use = k;
                            break;
                        }
                    }
                    if(next_use == -1) {
                        index = j;
                        break;
                    }
                    if(next_use > max) {
                        max = next_use;
                        index = j;
                    }
                }
                frame[index] = page[i];
            }

            page_faults++;
        }

        printf("%d\t", page[i]);
        for(j = 0; j < frames; j++) {
            if(frame[j] != -1)
                printf("%d ", frame[j]);
            else
                printf("- ");
        }
        printf("\n");
    }

    printf("\nTotal Page Faults = %d\n", page_faults);

    return 0;
}
