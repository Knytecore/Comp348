//
// Created by Lentzkie Sanon on 2022-05-11.
//
#include "aggregate.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int main() {
    float (*aggregates[5])(float *, int) = {&minf, &maxf, &sumf, &avgf, &pseudo_avgf};
    srand(time(0));

    printf("%s", "Array containing 5 random numbers \n");
    float array[5]; // will store numbers generated in array


    for (int i = 0; i < 5; i++) {
        array[i] = (float) (rand() % 100);
    }
    int arraysize = sizeof(array) / sizeof(array[0]);//helps me find the amount of element in the array +
    // since c doesn't have a length function
    for (int i = 0; i < 5; i++) {
        printf("%f \n", (*aggregates[i])(array, arraysize));
    }

    printf("%s", "Array containing 10 random numbers \n");

    float array2[10];
    for (int i=0; i<10;i++){
        array2[i]= (float) (rand()%200);
    }

    float arraysize2 =sizeof(array2) / sizeof(array2[0]);
    for (int i = 0; i < 5; i++) {
        printf("%f \n", (*aggregates[i])(array2, arraysize2));
    }




    return 0;
}