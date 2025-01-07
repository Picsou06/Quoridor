#include <stdlib.h>
#include "queue.h"
#include "quoridor.h"

Queue* createQueue() {
    /*
    Fonction: createQueue
    Auteur:Evan
    Paramètres: void
    Traitement : Crée une file vide
    Retour: q
    */
    Queue* q = (Queue*)malloc(sizeof(Queue));
    q->front = q->rear = NULL;
    return q;
}

void enqueue(Queue* q, Point p) {
    /*
    Fonction: enqueue
    Auteur:Evan
    Paramètres: Queue* q, Point p
    Traitement : Ajoute un élément à la file
    Retour: void
    */
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
    /*
    Fonction: dequeue
    Auteur:Evan
    Paramètres: Queue* q
    Traitement : Retire un élément de la file
    Retour: p
    */
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
    /*
    Fonction: isQueueEmpty
    Auteur:Evan
    Paramètres: Queue* q
    Traitement : Vérifie si la file est vide
    Retour: bool
    */
    return q->front == NULL;
}

void freeQueue(Queue* q) {
    /*
    Fonction: freeQueue
    Auteur:Evan
    Paramètres: Queue* q
    Traitement : Libère la mémoire allouée à la file
    Retour: void
    */
    while (!isQueueEmpty(q)) {
        dequeue(q);
    }
    free(q);
}