#include <stdio.h>
#include <stdlib.h>

#define MAX 5


void createQueue(int *queue, int *front, int *rear);
void enqueue(int *queue, int *front, int *rear, int value);
int dequeue(int *queue, int *front, int *rear);
void display(int *queue, int front, int rear);

int main() {
    int queue[MAX];
    int front, rear;
    int choice, value;

    createQueue(queue, &front, &rear);

    do {
        printf("\nCircular Queue Operations:\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter a value to enqueue: ");
                scanf("%d", &value);
                enqueue(queue, &front, &rear, value);
                break;
            case 2:
                dequeue(queue, &front, &rear);
                break;
            case 3:
                display(queue, front, rear);
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice! Please enter again.\n");
        }
    } while (choice != 4);

    return 0;
}

void createQueue(int *queue, int *front, int *rear) {
    *front = -1;
    *rear = -1;
}

void enqueue(int *queue, int *front, int *rear, int value) {

    if ((*rear + 1) % MAX == *front) {
        printf("Queue is full!\n");
        return;
    }

    if (*front == -1) {
        *front = 0;
    }
    *rear = (*rear + 1) % MAX;
    queue[*rear] = value;
    printf("Inserted %d\n", value);
}


int dequeue(int *queue, int *front, int *rear) {

    if (*front == -1) {
        printf("Queue is empty!\n");
        return -1;
    }
    int value = queue[*front];
    if (*front == *rear) {
        *front = -1;
        *rear = -1;
    } else {
        *front = (*front + 1) % MAX;
    }
    printf("Removed %d\n", value);
    return value;
}


void display(int *queue, int front, int rear) {

    if (front == -1) {
        printf("Queue is empty!\n");
        return;
    }
    printf("Queue elements: ");
    int i = front;
    while (1) {
        printf("%d ", queue[i]);
        if (i == rear) break;
        i = (i + 1) % MAX;
    }
    printf("\n");
}

