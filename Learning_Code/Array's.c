#include <stdio.h>

int main(){
    //array = a data structure that can stor many values of the same data type.

    double prices[] = {5.0, 10.0, 15.0, 25.0, 20.0}; //you have a variable named price and the price of one item, by using an array you can store more than one value 
                        // You can turn price into an array by adding straight brackets and any values you want to add to the array you add curly braces
                        // to access any of these values you must use an index number
    printf("$%.2lf", prices[0]);
    return 0; 
}