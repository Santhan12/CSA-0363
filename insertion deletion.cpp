#include <stdio.h>

#define MAX_SIZE 100

void displayArray(int arr[], int size) {
    printf("Array elements: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int insertElement(int arr[], int size, int position, int element) {
    if (size >= MAX_SIZE) {
        printf("Array is full. Cannot insert.\n");
        return size;
    }

    if (position < 0 || position > size) {
        printf("Invalid position for insertion.\n");
        return size;
    }

    for (int i = size; i > position; i--) {
        arr[i] = arr[i - 1];
    }
    arr[position] = element;

    return size + 1;
}

int deleteElement(int arr[], int size, int position) {
    if (size <= 0) {
        printf("Array is empty. Cannot delete.\n");
        return size;
    }

    if (position < 0 || position >= size) {
        printf("Invalid position for deletion.\n");
        return size;
    }

    for (int i = position; i < size - 1; i++) {
        arr[i] = arr[i + 1];
    }

    return size - 1;
}

int main() {
    int arr[MAX_SIZE];
    int size = 0;

    int choice, position, element;

    do {
        printf("\nArray Operations Menu:\n");
        printf("1. Insert an element\n");
        printf("2. Delete an element\n");
        printf("3. Display array\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the position for insertion: ");
                scanf("%d", &position);
                printf("Enter the element to insert: ");
                scanf("%d", &element);
                size = insertElement(arr, size, position, element);
                break;
            case 2:
                printf("Enter the position for deletion: ");
                scanf("%d", &position);
                size = deleteElement(arr, size, position);
                break;
            case 3:
                displayArray(arr, size);
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }

    } while (choice != 4);

    return 0;
}
