//odkaz na github https://github.com/cernozby/algo2

#include <stdio.h>
#include "math.h"
#include <stdlib.h>

int cmp_search = 0;
int cmp_search_sorted = 0;
int cmp_binary_search_rec = 0;
int cmp_binary_search = 0;


int random_array(int* array) {
    for(int i = 0; i < 1000; i++){
        array[i]=(rand()%1001);
    }
}

int search(int array[], int n, int e) {
    for (int i = 0; i < n; i++) {
        cmp_search++;
        if (array[i] == e) {
            return i;
        }
    }
    return -1;
}

int search_sorted_array(int array[], int n, int e) {
    for (int i = 0; i < n; i++) {
        cmp_search_sorted++;
        if (array[i] == e) {
            return i;
        }
        cmp_search_sorted++;
        if (array[i] > e) {return -1;}
    }
    return -1;
}

int binary_search_index(int array[], int left, int right, int e) {
    if (left > right) {return -1;}
    int index = floor((left + right) /2);
    cmp_binary_search_rec++;
    if (e == array[index]) {return index;}

    cmp_binary_search_rec++;
    if (e < array[index]) {
        return binary_search_index(array, left, index-1, e);
    } else {
        return binary_search_index(array, index+1, right, e);
    }
}

int binary_search_rec(int array[], int n, int e) {
    return binary_search_index(array, 0, n-1, e);
}

int binary_search(int array[], int n, int e) {
    int left = 0;
    int right = n -1;
    while (!(left > right)) {
        int index = floor((left + right) /2);

        cmp_binary_search++;
        if (e == array[index]) {return index;}

        cmp_binary_search++;
        if (e < array[index]) {
            right = index - 1;
        } else {
            left = index + 1;
        }
    }
}

void print_array(int pole[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d, ", pole[i]);
        if (i % 10 == 0) {
            printf("\n");
        }
    }
}

void copyArray(int pole[], int kopie[]) {

    for (int i = 0; i < 1000; i++) {
        kopie[i] = pole[i];
    }
}


int cmpfunc (const void * a, const void * b) {
    return ( *(int*)a - *(int*)b );
}



int task_2() {
    int pole_unsort[1000];
    int pole_sort[1000];

    //vsechna pole jsou stejna
    random_array(pole_unsort);
    copyArray(pole_unsort, pole_sort);

    qsort(pole_sort, 1000, sizeof(int), cmpfunc);

    int random = rand() % 1001;
    binary_search(pole_sort, 1000, random);
    search(pole_unsort, 1000, random);
    binary_search_rec(pole_sort, 1000, random);
    search_sorted_array(pole_sort, 1000, random);

    printf("hledani porovnani unsort: %d\n", cmp_search);
    printf("hledani porovnani sort: %d\n", cmp_search_sorted);
    printf("binarni hledani rekurze: %d\n", cmp_binary_search_rec);
    printf("binarni hledani cyklus: %d\n", cmp_binary_search);

    return 0;
}
