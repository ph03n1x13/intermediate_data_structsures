#include <stdio.h>
#include <string.h>

/*
Basic experimentation on C/C++ structures.
For a better understanding and strong basic to build up
Efficient C/C++ foundation.
--- ph03n1x

*/

// a simple structure

typedef struct name {

    char *mother;
    char *father; // pointer to the assigned char array
    char *first; 
    char *second;

} name;


typedef struct info {
    int serial;
    char *details;
    char *cell;
} info;


typedef struct person{
    int age;
    name per_name;
    info information;
} person;


typedef struct book{
    int serial;
    double price;
    char name[100];
    char author[]; // instead of direct assignment we'll use strcpy

} book;


void simple_assign(info structure);

void book_assign_gen_error(book owner);

void edit_person(person* buddy);




/*------------------------------------------------------------------------------*/

/*for better understanding on pointer here are two basic examples
of call by value and call by reference
*/


int TEST_VALUE = 13;
char* call_by_value(int value); // return pointer to the char type result statement
char* call_by_reference(int* ref);// referecne to the given integer



/*------------------------------------------------------------------------------*/



int main() {

    info robin;
    book robin_book;
    char *res; // pointer to the return output from functions

    //as robin is not sent as a pointer/ no pointer to robin is sent either
    //the changes won't be count in global scope
    simple_assign(robin);
    printf("[changes are not counted in local]:%s\n", robin.cell);
    printf("%s\n", robin_book.author);

    /*----------------------------------------------------------------------*/
    res = call_by_value(TEST_VALUE);
    printf("%s\n", res);
    res = call_by_reference(&TEST_VALUE);
    printf("%s\n", res);


    /*----------------------------------------------------------------------*/


    person chap;

    edit_person(&chap);

    //now the see the values have changed
    printf("chap information: \n");
    printf("name: %s %s\nage: %d\nfamily: %s + %s\ninterest: %s \ncont:%s\n",
            chap.per_name.first, chap.per_name.second,
            chap.age,
            chap.per_name.mother,
            chap.per_name.father,
            chap.information.details,
            chap.information.cell
            );

    return 0;
}

void simple_assign(info structure){

    structure.serial = 1;
    structure.details = "a good guy lives in Bahrain.";
    structure.cell= "+01-234-567-890";
    printf("serial: %d %s cell: %s\n",structure.serial, structure.details, structure.cell);
    return;

}



void book_assign_gen_error(book owner){

    owner.serial = 10101;
    owner.price = 1500.75;
    /*
    // this will generate flexible array error
    owner.name = "Neuromancer";
    owner.author = "Willium Gibson";

    */
     strcpy(owner.author, "Willium Gibson");

    return;
}



char* call_by_reference(int* ref){

    printf("[before]ref:%d TEST_VALUE: %d\n", *ref, TEST_VALUE);
    *ref = (*ref)*2;
    printf("[after]ref:%d TEST_VALUE: %d\n", *ref, TEST_VALUE);
    return "value assigned to the referenced variable has been changed\n";
}




char* call_by_value(int value){

    printf("[before] value: %d, TEST_VALUE: %d\n", value, TEST_VALUE);
    value = value * 2;
    printf("[after] value: %d, TEST_VALUE: %d\n", value, TEST_VALUE);
    return "local value/copy of value changed only\n";

}




void edit_person(person* buddy){

    //(*pointer).struct1.structn == pointer->struct1.structn

    buddy->per_name.first ="icarus";
    buddy->per_name.second ="phoenix";


    buddy->per_name.father = "daedalus";
    (*buddy).per_name.mother = "naucrate";
    (*buddy).age = 13;
    (*buddy).information.serial = 13;
    (*buddy).information.details = "a geek of arts, music, math and coding.";
    buddy->information.cell = "+012-345-678-901";

    return;

}




















