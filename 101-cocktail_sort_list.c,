#include <stdio.h>

void printArray(int *array, size_t size) {
    for (size_t i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

void shell_sort(int *array, size_t size) {
    // Generating the Knuth sequence
    int gap = 1;
    while (gap <= (int)size / 3) {
        gap = gap * 3 + 1;
    }

    while (gap > 0) {
        for (size_t i = gap; i < size; i++) {
            int temp = array[i];
            size_t j = i;

            while (j >= gap && array[j - gap] > temp) {
                array[j] = array[j - gap];
                j -= gap;
            }

            array[j] = temp;
        }

        printf("Gap %d: ", gap);
        printArray(array, size);

        gap = (gap - 1) / 3;
    }
}

int main() {
    int array[] = {38, 55, 12, 91, 34, 67, 3, 84};
    size_t size = sizeof(array) / sizeof(array[0]);

    printf("Original array: ");
    printArray(array, size);

    shell_sort(array, size);

    printf("Sorted array: ");
    printArray(array, size);

    return 0;
}
