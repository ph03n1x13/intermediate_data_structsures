/*
1c4rus ph03n1x 
*/
#include <stdio.h>
#include <stdlib.h>
#include<string.h>

#define SIZE 3




typedef struct book{
    double price;
    char id[10];
    char name[100];
    char author[100];
}book;


typedef struct TREE{
    int age;
    char place[20];
    char name[20];
}TREE;


//a global pointer to an int (or int type pointer)
int* pointer_to_array;

void create_library(book a_book[]); //use a_book[i].members
void library_pointer(book *a_book);
void integer_pointer();
void create_pointer_as_array();
TREE *tree_details(TREE *forest);// use (*tree).members or tree->members also send &library
void initiate_forest(TREE forest[]);
void print_forest(TREE forest[]);


int main() {

    printf("size of a book: %d bytes\n", sizeof(book));
    printf("size of a TREE: %d bytes\n", sizeof(TREE));

    book library[SIZE]; //allocate three spaces library type
    TREE forest[SIZE]; // allocate three spaces forest type
    TREE *fsPtr;
    fsPtr = forest;

    printf("size of a library of %d books: %d bytes\n",SIZE, sizeof(library));
    printf("size of a forest of %d TREES: %d bytes\n",SIZE, sizeof(forest));

    //integer_pointer();
    initiate_forest(forest);
    print_forest(forest);
    printf("------------------\n");
    print_forest(fsPtr);

    return 0;
}



void integer_pointer(){

    int array[10];
    pointer_to_array = array; //pointer to array will point to the location/address of array[0]

    for(int i = 0; i < 10; i++ ){
        pointer_to_array[i] = i;
    }

    for(int i = 0; i < 10; i++ ){
        printf("pointer_to_array[%d] = %d",i, pointer_to_array[i]);
        printf("\n");
    }

    printf("\n");

    return;
}


void create_library(book a_book[]){

    char bName[100], auth[100];

    for(int i = 0; i < SIZE; i++) {
        printf("book name[%d]: ", i);
        //read 20 chars. [%*c] ignore the last character
        scanf("%100[^\n]%*c",bName);
        strcpy(a_book[i].name, bName);

        printf("author[%d]: ", i);
        scanf("%100[^\n]%*c", auth);
        strcpy(a_book[i].author, auth);

        printf("price[%d]: ", i);
        scanf("%lf%*c", &a_book[i].price);
    }


    for(int i = 0; i < SIZE; i++) {

        printf("sl: %d book: %s author: %s price: %lf\n", i, a_book[i].name,a_book[i].author, a_book[i].price);

    }

    return;
}




void initiate_forest(TREE forest[]){

    for(int i= 0; i < SIZE; i++){
        tree_details(&forest[i]);
    }

    return;


}



TREE *tree_details(TREE *forest){
    char tree_name[20];
    char tree_place[20];
    printf("enter name 20 char: ");
    scanf("%20[^\n]%*c", tree_name);
    strcpy(forest->name,tree_name);
    printf("enter place 20 char: ");
    scanf("%5[^\n]%*c", tree_place);
    strcpy(forest->place,tree_place);
    return forest;
}


void print_forest(TREE forest[]){

    for(int i= 0; i < SIZE; i++){
        printf("sl: %d tree name: %s\n\a", i, forest[i].name);
    }
    return;
}
