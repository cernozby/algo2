//
// Created by Zbysa on 23.02.2022.
//
#include <stdio.h>
#include <stdlib.h>
#include "string.h"

//nepochopil jsem enum pro *. Klasické funguje jen pro "klasická písmena", kam symbol * nepatri

typedef struct Movie Movie;

struct Movie {
    char name[100];
    int year;
    int budget;
    int rating;
};


void print_movie_data(Movie m) {
    char stars[6];
    int i;

    for (i = 0; i < m.rating; i++) {
        stars[i] = '*';
    }
    stars[i] = '\0';
    printf("%s (%d), budget $%d, rating: %s\n", m.name, m.year, m.budget, stars);
}

void print_database (Movie database[]) {
    for (int i = 0; i < 5; i++) {
        print_movie_data(database[i]);
    }
}

int search_database_by_name(Movie database[], char s[]) {
    for (int i = 0; i < 5; i++) {
        if (strcmp(database[i].name, s) == 0) {
            return i;
        }
    }
    return -1;
}

int decrease_rating (Movie database[], unsigned int index, short value) {
    int ratingAfterDecrease = database[value].rating - value;
    if (ratingAfterDecrease > 5 || ratingAfterDecrease < 1) {return -1;}
    database[value].rating = ratingAfterDecrease;
    return 0;
}


int compare (const void * a, const void * b)
{
    Movie *movie_a = (Movie *)a;
    Movie *movie_b = (Movie *)b;
    return ( movie_b->budget - movie_a->budget );
}


Movie nth_highest_budget_movie (Movie database[], unsigned n) {
    qsort(database, 5, sizeof(Movie), compare);
    return database[n-1];

}

int task_1() {
    Movie m1 = {"Shrek", 2001, 60, 2};
    Movie m2 = {"Forrest Gump", 1994, 55, 4};
    Movie m3 = {"The Matrix", 1999, 63, 5};
    Movie m4 = {"Kill Bill", 2004, 30, 3};
    Movie m5 = {"Leon", 1994, 16, 4};
    Movie movies[5]  = {m1, m2, m3, m4, m5};

    //print_database(movies);
    //decrease_rating(movies, 3, 2);
    //print_database(movies);
    //print_movie_data(nth_highest_budget_movie(movies,3));
    //printf("%d\n", search_database_by_name(movies,"Leon"));
    return 0;
}
