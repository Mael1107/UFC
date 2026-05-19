#include <stdio.h>

float calculateAverage(float total, int length) {
    return total / length;
}

int main() {
    float notes[5], sum = 0, average;
    int above_average;
    int length = sizeof(notes) / sizeof(notes[0]);
    for(int i = 0; i < 5; i++) {
        printf("Enter the %dº note:\n", i + 1);
        scanf("%f", &notes[i]);
        sum += notes[i];

        if (notes[i] >= 7) {
            above_average += 1;
        }
    }

    average = calculateAverage(sum, length);
    printf("Average is: %.1f\n", average);
    printf("Students with above average grades: %d\n", above_average);
    
    return 0;
}