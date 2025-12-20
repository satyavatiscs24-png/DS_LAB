#include <stdio.h>

#define MAX 5   // Size of circular queue

int cq[MAX];
int front = -1, rear = -1;

/* Insert operation */
void insert() {
    int item;
    if ((rear + 1) % MAX == front) {
        printf("Queue Overflow! Cannot insert element.\n");
        return;
    }

    printf("Enter element to insert: ");
    scanf("%d", &item);

    if (front == -1) {   // First element
        front = 0;
        rear = 0;
    } else {
        rear = (rear + 1) % MAX;
    }

    cq[rear] = item;
    printf("Element inserted successfully.\n");
}

/* Delete operation */
void delete() {
    if (front == -1) {
        printf("Queue Empty! Cannot delete element.\n");
        return;
    }

    printf("Deleted element: %d\n", cq[front]);

    if (front == rear) {   // Only one element
        front = -1;
        rear = -1;
    } else {
        front = (front + 1) % MAX;
    }
}

/* Display operation */
void display() {
    int i;

    if (front == -1) {
        printf("Queue Empty! Nothing to display.\n");
        return;
    }

    printf("Queue elements: ");
    i = front;
    while (1) {
        printf("%d ", cq[i]);
        if (i == rear)
            break;
        i = (i + 1) % MAX;
    }
    printf("\n");
}

/* Main function */
int main() {
    int choice;

    do {
        printf("\n--- Circular Queue Menu ---\n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                insert();
                break;
            case 2:
                delete();
                break;
            case 3:
                display();
                break;
            case 4:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice! Try again.\n");
        }
    } while (choice != 4);

    return 0;
}
