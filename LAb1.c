#include <stdio.h>
int maxsize = 5;
int top = -1;
int a[5];
void push(int item) {
    if (top == maxsize - 1) {
        printf("Stack is full\n");
    } else {
        top = top + 1;
        a[top] = item;
    }
}
void pop() {
    if (top == -1) {
        printf("Stack is empty\n");
    } else {
        int item = a[top];
        printf("Popped element: %d\n", item);
        top = top - 1;
    }
}
void display() {
    if (top == -1) {
        printf("Stack is empty\n");
    } else {
        printf("Stack elements are: ");
        for (int i = top; i >= 0; i--) {
            printf("%d ", a[i]);
        }
        printf("\n");
    }
}
int main() {
    int item, n;
    printf("Enter number of elements to insert (max %d): ", maxsize);
    scanf("%d", &n);

    for (int i = 0; i <=n; i++) {
        printf("Enter element: ");
        scanf("%d", &item);
        push(item);
    }
    display();
    // Example of pop
    pop();
    display();
    return 0;
}
