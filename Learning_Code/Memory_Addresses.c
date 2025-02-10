#include <stdio.h>

int main(){

    // memory = an array of bytes within RAM (street)
    // memory block = a single unit (byte) wihtin memory, used to hold some value (person)
    // memory address = the address of where a memory block is located (house address)

    char a = 'x'; // Imagine where walking donw the street and looking for someones adress, if you open the front door then you will find x
    char b = 'y'; //abc are all memory blocks
    char c = 'z'; 
    
    printf("%d bytes\n", sizeof(a)); 
    printf("%d bytes\n", sizeof(b)); 
    printf("%d bytes\n", sizeof(c)); 

    printf("%p", &a); 
    printf("%p", &b); 
    printf("%p", &c); 

    return 0; 
}