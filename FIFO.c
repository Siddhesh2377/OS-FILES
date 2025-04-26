// FIFO Page Replacement Algorithm Implementation in C

#include <stdio.h>

int main() {
    int frames, pages, i, j, k, faults = 0;
    int page[50], frame[10], flag;

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

    j = 0; // Pointer for the frame to be replaced

    printf("\nPage\tFrames\n");
    for(i = 0; i < pages; i++) {
        flag = 0;

        // Check if page is already in a frame
        for(k = 0; k < frames; k++) {
            if(frame[k] == page[i]) {
                flag = 1;
                break;
            }
        }

        // If page not found, replace the oldest page
        if(flag == 0) {
            frame[j] = page[i];
            j = (j + 1) % frames; // Circular increment
            faults++;
        }

        printf("%d\t", page[i]);
        for(k = 0; k < frames; k++) {
            if(frame[k] != -1)
                printf("%d ", frame[k]);
            else
                printf("- ");
        }
        printf("\n");
    }

    printf("\nTotal Page Faults = %d\n", faults);

    return 0;
}
