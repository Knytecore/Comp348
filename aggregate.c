//
// Created by Lentzkie Sanon on 2022-05-11.
//
#include <stdio.h>


float minf(float *arr, int size) {
    float *pointer; //pointer that will indicate the targeted value
    if ((size == 0) || (size < 0)) {
        fprintf(stderr, "FATAL ERROR in line %d.\n",
                __LINE__);

    } else {
        pointer = &arr[0]; //assignment the address of the first value to the pointer
        for (int i = 1; i < size; i++) {
            if (*pointer > *(arr+i)) { // checking whether the values of the pointers indicate are small
                pointer = &(arr[i]);
            }
        }
        return (*pointer);

    }

}

float maxf(float *arr, int size) {
    float *pointer; //pointer that will indicate the targeted value
    if ((size == 0) || (size < 0)) {
        fprintf(stderr, "FATAL ERROR in line %d.\n",
                __LINE__);

    } else {
        pointer = &arr[0]; //assignment the address of the first value to the pointer
        for (int i = 1; i < size; i++) {
            if (*pointer < *(arr+i)) { // checking whether the values of the pointers indicate are small
                pointer = &(arr[i]);
            }
        }
        return (*pointer);

    }

}

float sumf(float *arr, int size) {
    float sum = *arr;

    if ((size == 0) || (size < 0)) {
        fprintf(stderr, "FATAL ERROR in line %d.\n",
                __LINE__);

    } else {
        for (int i = 1; i < size; i++) {
            sum += *(arr + i);
        }
        return sum;
    }

}

float avgf(float *arr, int size) {
    if ((size == 0) || (size < 0)) {
        fprintf(stderr, "FATAL ERROR in line %d.\n",
                __LINE__);

    } else {
        return sumf(arr, size) / size;
    }

}

float pseudo_avgf(float *arr, int size) {
    if ((size == 0) || (size < 0)) {
        fprintf(stderr, "FATAL ERROR in line %d.\n",
                __LINE__);

    } else {
        float pseudo_avg = ((minf(arr, size)) + (maxf(arr, size))) / 2;

        return pseudo_avg;
    }


}