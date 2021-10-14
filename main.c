#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

struct cat {
    int age;
    char *name;
};
void print_cat(struct cat *c);
struct cat * spawn_cat(char *name, int age);

void populate_random_arr(char *arr, int len);

int main() {
    srand(time(NULL));
    
    int rand_age = rand() % 100;
    
    int len = (rand() % 50) + 1;
    char rand_name[len];
    populate_random_arr(rand_name, len);
    
    struct cat *kitty = spawn_cat(rand_name, rand_age);
    print_cat(kitty);
}

void print_cat(struct cat *c) {
    printf("Cat:\n\tName: %s\n\tAge: %d\n", c->name, c->age);
}

struct cat * spawn_cat(char *name, int age) {
    struct cat *c;
    c = malloc(sizeof(struct cat));
    
    c->name = name;
    c->age = age;
    
    return c;
}

void populate_random_arr(char *arr, int len) {
    char name_chars[] = "abcdefghijklmnopqrstuvwxyz";
    
    int i;
    for (i = 0; i < len; i++) {
        arr[i] = (rand() % 24) + 65;
    }
    
    arr[len - 1] = '\0';
}
