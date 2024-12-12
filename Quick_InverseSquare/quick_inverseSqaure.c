#include <stdio.h>
#include <math.h>
#include <time.h>


// Function to take user input and ignore whitespace

float Q_rsqrt(float);

int main() {
    clock_t start, end; 
    double cpu_time_used;
    float number = 4.5;
    start = clock();
    printf("normal: %f\n", 1/sqrt(number));
    end = clock();
    cpu_time_used = ((double)(end-start))/CLOCKS_PER_SEC;
    printf("time used: %f\n", cpu_time_used);

    start = clock();
    printf("fast: %f\n", Q_rsqrt(number));
    end = clock();
    cpu_time_used = ((double)(end-start))/CLOCKS_PER_SEC;
    printf("time used: %f\n", cpu_time_used);
}

float Q_rsqrt(float number)
{
    long i; 
    float x2, y;
    const float threehalf = 1.5F;

    x2 = number * 0.5F;
    y = number; 
    i = * (long *)&y;
    i = 0x5f3759df - (i >> 1);
    y = * (float *)&i;
    y = y * (threehalf - (x2*y*y));
    y = y * (threehalf - (x2*y*y));

    return y;
}