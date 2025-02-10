#include <stdio.h>

void birthday(char name[], int age){
    printf("\nHappy birthday dear %s!", name); // Functions cant see other functions, so you need arguments
    printf("\nYou are %d years old", age);
}

int main()
{
    char name[] = "Bro"; 
    int age = 21; 

    birthday(name, age); 


    return 0; 
}