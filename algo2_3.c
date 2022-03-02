#include "stdlib.h"
#include "stdio.h"

typedef struct Node {
    int key;
    struct Node *next ;
} Node;

typedef struct List {
    struct Node *first ;
} List;

Node* node_new(int key) {
    Node *node = malloc(sizeof(Node));
    node->key = key;
    node->next = NULL;
    return node;
}

void add_end (List* list, Node* node) {
    Node *actualNode = list->first;
    if(actualNode == NULL) {list->first = node; return;}
    while(actualNode->next != NULL) {
        actualNode = actualNode->next;
    }
    actualNode->next = node;

}

void print_list (List* list) {
    Node *actualNode = list->first;
    printf("(");
    while(actualNode->next != NULL) {
        printf("%d, ", actualNode->key);
        actualNode = actualNode->next;
    }
    printf("%d)\n", actualNode->key);
}

void add_start (List* list, Node* node) {
    node->next = list->first;
    list->first = node;
}

int length (List* list) {
    Node *actualNode = list->first;
    if(actualNode == NULL) {return 0;}
    int iter = 1;
    while (actualNode->next != NULL) {
        iter++;
        actualNode = actualNode->next;
    }

    return iter;
}

int search (List* list, Node* node) {
    Node *actualNode = list->first;
    int index = 0;
    while (actualNode != NULL) {
        if(node->key == actualNode->key) {
            return index;
        }
        index++;
        actualNode = actualNode->next;
    }

    return -1;
}

void fillList(List *list) {
    Node* node1 = (Node*) malloc(sizeof(Node));
    node1->key = 3;
    node1->next = NULL;

    Node* node2 = (Node*) malloc(sizeof(Node));
    node2->key = 2;
    node2->next = NULL;

    Node* node3 = (Node*) malloc(sizeof(Node));
    node3->key = 10;
    node3->next = NULL;


    add_start(list, node1);
    add_start(list, node2);
    add_end(list, node3);

}

int remove_start (List* list) {
    if(list->first == NULL) {-1;}
    Node *firstItem = list->first;
    list->first = list->first->next;
    free(firstItem);
    return 0;
}

int remove_end (List* list) {
    if(list->first ==NULL) {return -1;}
    Node *actualNode = list->first;
    while(actualNode->next->next != NULL) {
        actualNode = actualNode->next;
    }
    Node *removeItem = actualNode->next;
    actualNode->next = NULL;
    free(removeItem);
    return 0;
}

int remove_node (List* list, Node* node) {
    Node *actualNode = list->first;
    if(actualNode->key == node->key) {
        return remove_start(list);
    }
    //nenajde prvni a posledni
    while (actualNode->next->next != NULL) {
        if (node->key == actualNode->next->key) {
           Node* remove = actualNode->next;
           actualNode->next = actualNode->next->next;
           free(remove);
            return 0;
        }
        actualNode = actualNode->next;
    }

    if(actualNode->next->key == node->key) {
        return remove_end(list);
    }
    return -1;
}


int task_3() {
    List *list = (List*) malloc(sizeof(List));
    list->first = NULL;
    add_end(list, node_new(2));
    add_end(list, node_new(3));
    add_end(list, node_new(4));
    add_start(list, node_new(1));


    //"neco jako testy"
    print_list(list); // (1, 2, 3, 4)
    printf("%d\n", length(list)); //4
    printf("%d\n", search(list, node_new(4))); //3
    printf("%d\n", remove_end(list)); //0
    printf("%d\n", search(list, node_new(4))); //-1
    printf("%d\n", remove_start(list)); // 0
    print_list(list); // (2, 3)
    printf("%d\n", remove_node(list, node_new(4))); // -1;
    printf("%d\n", remove_node(list, node_new(3))); // 0

    return 0;
}
