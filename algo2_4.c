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

void add_end (List* list, int key) {
    Node *actualNode = list->first;
    Node *node = node_new(key);
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

void add_start (List* list, int key) {
    Node *node = node_new(key);
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

int search (List* list, int key) {
    Node *node = node_new(key);
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

    for(int i = 2; i < 10; i++) {
        add_end(list, i);
    }
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

int remove_node (List* list, int key) {
    Node *node = node_new(key);
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


int task_4() {
    List *list = (List*) malloc(sizeof(List));
    list->first = NULL;

    fillList(list);
    //"neco jako testy"

    add_end(list, 10);
    add_end(list, 11);
    add_end(list, 4);
    add_start(list, 1);
    print_list(list);
    printf("delka - %d\n", length(list));
    printf("prvek 4 na pozici: %d\n", search(list, 4));
    printf("%d\n", remove_end(list));
    printf("%d\n", remove_node(list, 12));
    printf("%d\n", remove_node(list, 3));
    printf("%d\n", remove_node(list, 4));
    printf("%d\n", search(list, 4));
    printf("%d\n", remove_start(list));
    print_list(list);

    return 0;
}
