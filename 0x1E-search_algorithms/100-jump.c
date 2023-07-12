#include <stdio.h>
#include <math.h>

int jump_search(int *array, size_t size, int value) {
    if (array == NULL || size == 0) {
        return -1;  // Invalid input, return -1
    }

    size_t jump_step = sqrt(size);  // Calculate the jump step

    size_t prev = 0;
    size_t step = jump_step;

    // Find the block where the value may exist
    while (step < size && array[step] <= value) {
        prev = step;
        step += jump_step;
    }

    // Perform linear search in the identified block
    while (prev < size && array[prev] <= value) {
        printf("Comparing value: %d\n", array[prev]);  // Print the compared value
        if (array[prev] == value) {
            return prev;  // Found the value, return the index
        }
        prev++;
    }

    return -1;  // Value not found in the array
}

int main() {
    int arr[] = {1, 3, 5, 7, 9, 11, 13, 15, 17, 19, 21, 23, 25};
    size_t size = sizeof(arr) / sizeof(arr[0]);

    int value = 11;
    int result = jump_search(arr, size, value);
    if (result != -1) {
        printf("Value %d found at index %d\n", value, result);
    } else {
        printf("Value %d not found in the array\n", value);
    }

    return 0;
}
 
