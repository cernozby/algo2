//
// Created by Zbysa on 16.03.2022.
//

#ifndef ALGO2_STRUCT_H
#define ALGO2_STRUCT_H

typedef struct Queue_node {
    struct Tree_Node* data;
    struct Queue_node* next;
} Queue_node;

typedef struct Queue {
    struct Queue_node* first;
    int count;
} Queue;

typedef struct Tree_Node {
    int key;
    struct Tree_Node *left;
    struct Tree_Node *right;
    struct Tree_Node *parent;
} Tree_Node;

typedef struct Tree {
    struct Tree_Node *root ;
} Tree;

#endif //ALGO2_STRUCT_H
