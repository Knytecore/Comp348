#include <stdio.h>
#include "AGGREGATE.h"

int main() {
    float arr[] = { 1, 4, 5, 6, -1 }; //Static array. Cannot realloc.
    printf("----------------------------------------------------Assignment Q3--------------------------------------------------------------------\n");
    printf("----------------------------------------------\n");
    printf("Calling min function on { 1, 4, 5, 6, -1 }\n");
    float minVal = min(arr, 5);
    printf("Min function returned %f\n", minVal);
    printf("----------------------------------------------\n");
    printf("Calling max function on { 1, 4, 5, 6, -1 }\n");
    float maxVal = max(arr, 5);
    printf("Max function returned %f\n", maxVal);
    printf("----------------------------------------------\n");
    printf("Calling sum function on { 1, 4, 5, 6, -1 }\n");
    float sumVal = sum(arr, 5);
    printf("Sum function returned %f\n", sumVal);
    printf("----------------------------------------------\n");
    printf("Calling Avg function on { 1, 4, 5, 6, -1 }\n");
    float avgVal = avg(arr, 5);
    printf("Avg function returned %f\n", avgVal);
    printf("----------------------------------------------\n");
    printf("Calling pseudo_avg function on { 1, 4, 5, 6, -1 }\n");
    float pseudoVal = pseudo_avg(arr, 5);
    printf("pseudo_avg function returned %f\n", pseudoVal);
    printf("\n\n\n");


    printf("----------------------------------------------------Assignment Q4--------------------------------------------------------------------\n");
    float arr3[] = { 1, 5, 10, 12, -21 , 21, 25, 19, 20, 21 };
    float (*fctPointers[5]) (float* x, int y) = { &min,&max,&sum,&avg,&pseudo_avg };
    for (int i = 0; i < 5; i++) {
        printf("-----------------------------------------------------------------------------------------------------------------------------------\n");
        printf("Calling function %d of array of function pointers {&min,&max,&sum,&avg,&pseudo_avg} with { 1, 4, 5, 6, -1 } as array parameter\n", i);
        float returnVal = (*fctPointers[i])(arr, 5);
        printf("Function returned value %f\n", returnVal);
    }

    printf("\n\n");

    for (int i = 0; i < 5; i++) {
        printf("-----------------------------------------------------------------------------------------------------------------------------------\n");
        printf("Calling function %d of array of function pointers {&min,&max,&sum,&avg,&pseudo_avg} with { 1, 5, 10, 12, -21 , 21, 25, 19, 20, 21 } as array parameter\n", i);
        float returnVal = (*fctPointers[i])(arr3, 10);
        printf("Function returned value %f\n", returnVal);
    }
}