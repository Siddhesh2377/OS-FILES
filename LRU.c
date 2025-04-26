// LRU Page Replacement Algorithm Implementation in C

#include <stdio.h>

int main() {
    int frames, pages, i, j, k, page_faults = 0, min, index;
    int page[50], frame[10], counter[10] = {0};

    printf("Enter number of frames: ");
    scanf("%d", &frames);

    printf("Enter number of pages: ");
    scanf("%d", &pages);

    printf("Enter page reference string: ");
    for(i = 0; i < pages; i++) {
        scanf("%d", &page[i]);
    }

    for(i = 0; i < frames; i++) {
        frame[i] = -1; // Initialize all frames as empty
    }

    printf("\nPage\tFrames\n");

    for(i = 0; i < pages; i++) {
        int found = 0;

        // Check if page is already in frame
        for(j = 0; j < frames; j++) {
            if(frame[j] == page[i]) {
                found = 1;
                counter[j] = i + 1; // Update recent use
                break;
            }
        }

        // If not found, need to replace
        if(found == 0) {
            int empty = -1;
            for(j = 0; j < frames; j++) {
                if(frame[j] == -1) {
                    empty = j;
                    break;
                }
            }

            if(empty != -1) {
                frame[empty] = page[i];
                counter[empty] = i + 1;
            } else {
                min = counter[0];
                index = 0;
                for(j = 1; j < frames; j++) {
                    if(counter[j] < min) {
                        min = counter[j];
                        index = j;
                    }
                }
                frame[index] = page[i];
                counter[index] = i + 1;
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
