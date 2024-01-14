#include <stdio.h>

int main(int argc, char *argv[]) {
    FILE *ptr = fopen("testdata.in", "r");

    int a, b;
    fscanf(ptr, "%d %d\n", &a, &b);

    fclose(ptr);

    printf("%d\n", a + b);
    
    return 0;
}