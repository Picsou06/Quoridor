#ifndef QUEUE_H
#define QUEUE_H

#include <stdbool.h>

typedef struct {
    int x;
    int y;
} Point;

typedef struct Node {
    Point point;
    struct Node* next;
} Node;

typedef struct {
    Node* front;
    Node* rear;
} Queue;

Queue* createQueue();
void enqueue(Queue* q, Point p);
Point dequeue(Queue* q);
bool isQueueEmpty(Queue* q);
void freeQueue(Queue* q);

#endif