#include <assert.h>
#include <stddef.h>
#include <stdio.h>

#define HEAP_LEFT(i) (2*i)
#define HEAP_RIGHT(i) ((2*i) + 1)
#define HEAP_PARENT(i) (i/2)

#define ARRAY_POSITION(arr, i) arr[(i-1)]

#define SWAP_ARRAY(type, a, b) do { \
    type temp = (a);        \
    (a) = (b);              \
    (b) = temp;             \
} while (0)

#define ARRAY_LENGTH(x) (sizeof(x) / sizeof((x)[0]))

#define PRINT_INT_ARRAY(array, length) \
    do { \
        for (int i = 0; i < (length); i++) { \
            printf("%d ", (array)[i]); \
        } \
        printf("\n"); \
    } while(0)


void max_heapify(int arr[], int pos, int heap_size) {
    int largest = pos;
    int left = HEAP_LEFT(pos);
    int right = HEAP_RIGHT(pos);

    if (left <= heap_size && ARRAY_POSITION(arr, left) > ARRAY_POSITION(arr, pos)) {
        largest = left;
    }
    if (right <= heap_size && ARRAY_POSITION(arr, right) > ARRAY_POSITION(arr, largest)) {
        largest = right;
    }

    if (largest != pos) {
        SWAP_ARRAY(int, ARRAY_POSITION(arr, pos), ARRAY_POSITION(arr, largest));
        max_heapify(arr, largest, heap_size);
    }
}

void build_max_heap(int arr[], size_t len, size_t heap_size) {
    for (int i = (len/2); i >= 1; i--) {
        max_heapify(arr, i, heap_size);
    }
}


void heap_sort(int arr[], size_t len) {
    size_t heap_size = len;
    // Modify the array to apply Max Heap properties
    build_max_heap(arr, len, heap_size);

    for (int i = len; i >= 2; i--) {
        // Swap root heap node because is the largest value.
        SWAP_ARRAY(int, arr[0], ARRAY_POSITION(arr, i));

        // Decrement heap size to not look for the swapped value that is already in the correct place.
        heap_size--;
        // preserve heap properties after value swap
        max_heapify(arr, 1, heap_size);
    }
}

int main(int argc, char **argv) {
    int arr[] = {4, 1, 3, 2, 16, 9, 10, 14, 8, 7};
    /**
     *                  16
     *               /      \
     *              /        \
     *             14         10
     *          /     \     /   \
     *         8       7   9     3
     *       /   \    /
     *      2     4  1
     */
    PRINT_INT_ARRAY(arr, ARRAY_LENGTH(arr));

    //build_max_heap(arr, ARRAY_LENGTH(arr));
    heap_sort(arr, ARRAY_LENGTH(arr));

    PRINT_INT_ARRAY(arr, ARRAY_LENGTH(arr));
    return 0;
}
