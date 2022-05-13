#ifndef _AGGREGATE_H //Include guard (avoid double inclusion - file will only be included once even if called twice)
#define _AGGREGATE_H

inline float min(float* arr, int size) {
    if (!(size > 0)) {
        printf("FATAL ERROR in line 6 of AGGREGATE.h");
        exit();
    }   
    float min = arr[0];
    for (int i = 1; i < size; i++) {
        if (min > arr[i]) {
            min = arr[i];
        }
    }
    return min;

}

inline float max(float* arr, int size) {
    if (!(size > 0)) {
        printf("FATAL ERROR in line 21 of AGGREGATE.h");
        exit();
    }
    float max = arr[0];
    for (int i = 1; i < size; i++) {
        if (max < arr[i]) {
            max = arr[i];
        }
    }
    return max;

}

inline float sum(float* arr, int size) {
    if (!(size > 0)) {
        printf("FATAL ERROR in line 36 of AGGREGATE.h");
        exit();
    }
    float sum = 0;
    for (int i = 0; i < size; i++) {
            sum += arr[i];
    }
    return sum;

}

inline float avg(float* arr, int size) {
    float average = sum(arr, size);
    average = average / size;
    return average;
}

inline float pseudo_avg(float* arr, int size) {
    float minVal = min(arr, size);
    float maxVal = max(arr, size);

    return (minVal +maxVal) / 2;
}

#endif
