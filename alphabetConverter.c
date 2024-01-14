#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]) {
    FILE *ptr = fopen("testdata.in", "r");

    int tc;
    fscanf(ptr, "%d\n", &tc);

    for (int i = 1; i <= tc; i++) {
        char string[105];
        fscanf(ptr, "%[^\n]\n", string);

        int length;
        fscanf(ptr, "%d\n", &length);

        int check[130] = {0};
        for (int j = 0; j < length; j++) {
            char prev, after;
            fscanf(ptr, "%c %c\n", &prev, &after);

            for (int k = 0; k < strlen(string); k++) {
                if ((string[k] == prev) && (check[string[k]] == 0)) {
                    string[k] = after;
                }
            }
            check[prev] = 1;
        }


        int frequency[130] = {0};
        for (int j = 0; j < strlen(string); j++) {
            frequency[string[j]]++;
        }

        for (int j = 0; j < 130; j++) {
            if (frequency[j] > 0) {
                printf("%c %d\n", j, frequency[j]);
            }
        }
    }

    fclose(ptr);

    return 0;
}