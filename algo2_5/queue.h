//
// Created by Zbysa on 16.03.2022.
//
#include "struct.h"
#ifndef ALGO2_QUEUE_H
#define ALGO2_QUEUE_H
//
// Created by Zbysa on 16.03.2022.
//

Queue* getEmpthyQueue() {
    Queue* queue = (Queue*)(malloc(sizeof (Queue)));
    queue->first = NULL;
    queue->count = 0;
}

Queue_node* new_queue_node(Tree_Node* treeNode) {
    Queue_node *queue = malloc(sizeof(Queue_node));
    queue->next = NULL;
    queue->data = treeNode;
    return queue;
}

void enqueue(Queue* queue, Tree_Node* treeNode) {
    Queue_node* queueNode = new_queue_node(treeNode);
    if (queue->first == NULL) {queue->first = queueNode; queue->count++; return;}
    Queue_node* first = queue->first;
    while(first->next) {
        first = first->next;
    }

    //first is nov last
    first->next = queueNode;
    queue->count++;
}


Queue_node * dequeue(Queue* queue) {
    if (!queue->first) {return NULL;}
    Queue_node* queueNode = queue->first;
    queue->first = queue->first->next;
    queue->count--;
    return queueNode;
}

int empty(Queue* queue) {
    return (queue->count == 0);
}

void print_queue(Queue* queue) {
    printf("( ");
    while (queue->count > 0) {
        printf("%d, ",dequeue(queue)->data->key);
    }
    printf(")\n");
}

#endif //ALGO2_QUEUE_H
