//
// Created by Zbysa on 09.03.2022.
//

#include "stdlib.h"
#include "stdio.h"

typedef struct Tree_Node {
    int key;
    struct Tree_Node *left;
    struct Tree_Node *right;
    struct Tree_Node *parent;
} Tree_Node;

typedef struct Tree {
    struct Tree_Node *root ;
} Tree;


Tree_Node* node_new(int key) {
    Tree_Node *tree_node = malloc(sizeof(Tree_Node));
    tree_node->key = key;
    tree_node->left = NULL;
    tree_node->right = NULL;
    tree_node->parent = NULL;
    return tree_node;
}

Tree_Node* add_node(Tree_Node* treeNode, int key) {
    Tree_Node* newTreeNode = node_new(key);
    newTreeNode->parent = treeNode;
    return newTreeNode;
}

int add_helper(Tree_Node* treeNode, int key) {
    if(treeNode->key == key) {return -1;}

    if (key < treeNode->key) {
        if (treeNode->left == NULL) {
            treeNode->left = add_node(treeNode, key);
        } else {
            add_helper(treeNode->left, key);
            return 0;
        }
    } else {
        if (treeNode->right == NULL) {
            treeNode->right = add_node(treeNode, key);
        } else {
            add_helper(treeNode->right, key);
            return 0;
        }
    }
}

int add (Tree* tree, int key) {
    //for empty tree set root elemnet
    if(tree->root == NULL) { tree->root = node_new(key); return 0;}
    return add_helper(tree->root, key);

}

void print_tree(Tree_Node* treeNode) {
    if(treeNode == NULL) {return;}
    print_tree(treeNode->left);
    printf("%d, ", treeNode->key);
    print_tree(treeNode->right);

}

void print_in_order (Tree* tree) {
    printf("( ");
    print_tree(tree->root);
    printf(")\n");
}

int depth_treeNode(Tree_Node* treeNode) {
    if (treeNode == NULL) {return -1;}
    int maxL = 1 + depth_treeNode(treeNode->left);
    int maxR = 1 + depth_treeNode(treeNode->right);
    return maxL > maxR ? maxL : maxR;
}

int depth (Tree* tree) {
    if(tree->root == NULL) {return -1;}
    return depth_treeNode(tree->root);
}



int task_5() {
    Tree *tree = (Tree*) malloc(sizeof(Tree));
    tree->root = NULL;


    /*
     *       2
     *     1   4
     *   -1   3 10
     */
    add(tree, 2);
    add(tree, 4);
    add(tree, 3);
    add(tree, 10);
    add(tree, 1);
    add(tree, -1);

    print_in_order(tree);
    printf("hloubka: %d, \n", depth(tree));


    return 0;
}