#include <stdio.h>
#include <stdbool.h>

#define MAX 7 //The maximum size of the array

// The array of elements to sort
int intArray[MAX] = {4, 6, 3, 2, 1, 9, 7};

/**
 * This method is used to print a line of characters
 * to make the console output more human readable.
 * @param count - the number of characters to print.
 */
void printline(int count) {
    for(int i = 0; i < count - 1; i++) {
        printf("=");
    }
    printf("=\n");
}

/**
 * This method displays the contents of the array
 */
void display() {
    printf("[");
    // navigate through all items
    for (int i = 0; i < MAX; i++) {
        printf("%d ", intArray[i]);
    }
    printf("]\n");
}

/**
 * This method swaps two numbers in the array around.
 * @param num1 - the first number
 * @param num2 - the second number
 */
void swap(int num1, int num2) {
    int temp = intArray[num1];
    intArray[num1] = intArray[num2];
    intArray[num2] = temp;
}

/**
 * This method handles the partitioning part of the quicksort.
 * @param left
 * @param right
 * @param pivot
 * @return
 */
int partition(int left, int right, int pivot) {
    int leftPointer = left - 1;
    int rightPointer = right;

    // This construct is incremented and decrementing the respective pointers and
    // comparing their values with the indicated pivot point for the quicksort.
    // It breaks as soon as a value on the left of the pivot is >= to a value on the right.
    while(true) {
        while(intArray[++leftPointer] < pivot)
        {
            // do nothing
        }
        while(rightPointer > 0 && intArray[--rightPointer] > pivot) {
            // do nothing
        }
        if(leftPointer >= rightPointer) {
            break;
        } else {
            // swaps elements across the pivot point. Something that is smaller than the pivot
            // will then end up on the left side of it. Larger ends up on the right side of it.
            printf("items swapped: %d, %d\n", intArray[leftPointer], intArray[rightPointer]);
            swap(leftPointer, rightPointer);
        }
    }
    // swaps the pivot point to something new after the above happens.
    // in this algorithm, the pivot starts as the far right entry in the array,
    // so the pivot will swap based on the position of the pointers for any given pass.
    printf("pivot swapped: %d, %d\n", intArray[leftPointer], intArray[right]);
    swap(leftPointer, right);
    printf("Updated Array: ");
    display();
    return leftPointer;
}

/**
 * Quick sort is a recursive algorithm that breaks the array into two different sections at the partition point.
 * Each of these is sorted.
 * @param left - the point on the left side of the array to start with
 * @param right - the point on the right side of the array to start with
 */
void quick_sort(int left, int right) {
    if (right - left <= 0) {
        return; // this means we have overlapped, so we need to stop execution.
    } else {
        int pivot = intArray[right]; // pivot begins as the last element in the array for this program
        int partitionPoint = partition(left, right, pivot);
        quick_sort(left, partitionPoint - 1);
        quick_sort(partitionPoint + 1, right);
    }
}

/**
 * The entry point of the program.
 * @return The status code indicating success or failure.
 */
int main() {
    printf("Input Array: ");
    display();
    printline(50);
    quick_sort(0, MAX-1); // start the sort out with the first and last indices of the array
    printf("Ouput Array: ");
    display();
    printline(50);
    return 0;
}