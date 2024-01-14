#include <stdio.h>

int main(int argc, char *argv[]) {
    FILE *ptr = fopen("testdata.in", "r");

    int tc;
    fscanf(ptr, "%d\n", &tc);

    for (int i = 1; i <= tc; i++) {
        int length;
        fscanf(ptr, "%d\n", &length);

        int array[length];
        int total = 0;
        for (int j = 0; j < length; j++) {
            fscanf(ptr, "%d\n", &array[j]);
            total += array[j];
        }

        long long int perimeter = 0;
        long long int area = 0;

        perimeter += length * 4;
        for (int j = 0; j < length; j++) {
            if (j == 0 || j == length - 1) {
                perimeter += array[j] * 2;
            }

            if (j == 0) {
                if (array[j] > array[j + 1]) {
                    perimeter += (array[j] - array[j + 1]) * 2;
                }
            } else if (j == length - 1) {
                if (array[j] > array[j - 1]) {
                    perimeter += (array[j] - array[j - 1]) * 2;
                }
            } else {
                if (array[j] > array[j - 1]) {
                    perimeter += (array[j] - array[j - 1]) * 2;
                } 

                if (array[j] > array[j + 1]) {
                    perimeter += (array[j] - array[j + 1]) * 2;
                } 
            }
        }

        printf("Case #%d: %lld %lld\n", i, perimeter, total * 4);
    }

    fclose(ptr);
    
    return 0;
}