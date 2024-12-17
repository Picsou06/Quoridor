#include <stdlib.h>
#include "queue.h"
#include "quoridor.h"

Queue* createQueue() {
    Queue* q = (Queue*)malloc(sizeof(Queue));
    q->front = q->rear = NULL;
    return q;
}

void enqueue(Queue* q, Point p) {
    Node* temp = (Node*)malloc(sizeof(Node));
    temp->point = p;
    temp->next = NULL;
    if (q->rear == NULL) {
        q->front = q->rear = temp;
        return;
    }
    q->rear->next = temp;
    q->rear = temp;
}

Point dequeue(Queue* q) {
    if (q->front == NULL) {
        Point p = {-1, -1}; // Valeur spéciale pour indiquer une file vide
        return p;
    }
    Node* temp = q->front;
    Point p = temp->point;
    q->front = q->front->next;
    if (q->front == NULL) {
        q->rear = NULL;
    }
    free(temp);
    return p;
}

bool isQueueEmpty(Queue* q) {
    return q->front == NULL;
}

void freeQueue(Queue* q) {
    while (!isQueueEmpty(q)) {
        dequeue(q);
    }
    free(q);
}