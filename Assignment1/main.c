#include "aggregate.h"
#include <stdio.h>

int main() {

    float array[] = {2,3,1,4,5}; // array taken from assignment 1
    int arraysize = sizeof(array)/sizeof(array[0]);
    float arrayEmpty []= {};
    int arraysizeEmpty = sizeof(arrayEmpty)/sizeof(arrayEmpty[0]);
    printf("%s", "Array full \n");
    printf("%s %f \n","Minimum value is ",minf(array, arraysize));
    printf("%s %f \n","Maximum value is ",maxf(array, arraysize));
    printf("%s %f \n","The sum is ",sumf(array, arraysize));
    printf("%s %f \n","The average is ", avgf(array, arraysize));
    printf("%s %f \n", "The pseudo average is",pseudo_avgf(array, arraysize));

    printf("%s", "Array Empty \n");
    minf(arrayEmpty, arraysizeEmpty);
    maxf(arrayEmpty, arraysizeEmpty);
    sumf(arrayEmpty, arraysizeEmpty);
    avgf(arrayEmpty, arraysizeEmpty);
    pseudo_avgf(arrayEmpty, arraysizeEmpty);
    return 0;
}

