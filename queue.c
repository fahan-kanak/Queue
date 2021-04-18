/* 
 * File:   queue.c
 * Author: farhan
 *
 * Created on April 18, 2021, 4:19 PM
 */

#include <stdio.h>
#include <stdlib.h>

struct link {
    int x;
    struct link *next;
};

typedef struct link Queue;

void enqueue(int num, Queue *front) {
    if (front->next == NULL) {
        front->next = (Queue *)malloc(sizeof(Queue));
        front->next->x = num;
        front->next->next = NULL;
        return;
    }
    enqueue(num, front->next);
}

int isEmpty(Queue *front) {
    if (!front) return 1;
    else return 0;
}

int peek(Queue *front) {
    return front->x;
}

int getSize(Queue *front) {
    int count = 0;
    while (front) {
        count++;
        front = front->next;
    }
    
    return count;
}

void printQueue(Queue *front) {
    if (!front) return;
    printf("%d ", front->x);
    printQueue(front->next);
}

int main(int argc, char** argv) {
    Queue* front = NULL, *tmp;
    int choice, num;
    while (1) {
        printf("\n1 -> Enqueue\n2 -> Dequeue\n3 -> Peek\n4 -> Print Size\n5 -> Print Queue\nAny Other -> Quit\n");
        printf("\nEnter operation: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("\nEnter number: ");
                scanf("%d", &num);
                if (!front) {
                    front = (Queue *)malloc(sizeof(Queue));
                    front->x = num;
                    front->next = NULL;
                } else enqueue(num, front);
                break;
            case 2:
                if (isEmpty(front)) printf("\nEmpty Queue Exception!!!\n");
                else {
                    tmp = front;
                    front = front->next;
                    printf("\n%d retrieved\n", tmp->x);
                    free(tmp);
                }
                break;
            case 3:
                if (isEmpty(front)) printf("\nEmpty Queue Exception!!!\n");
                else printf("\n%d in front\n", peek(front));
                break;
            case 4:
                printf("\nQueue size => %d\n", getSize(front));
                break;
            case 5:
                if (isEmpty(front)) printf("\nEmpty Queue Exception!!!\n");
                else {
                    printf("\nQueue -> ");
                    printQueue(front);
                    printf("\n");
                }
                break;
            default:
                printf("\nBye!!! :)\n");
                goto exit;
        }
    }

    exit: return 0;
}

