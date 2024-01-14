#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void convertToChar(char *digit) {
    char result[9] = {'O', 'I', ' ', 'E', 'A', 'S', 'G', 'T', 'B'};

    (*digit) = result[(*digit) - '0'];
}

int main(int argc, char *argv[]) {
    FILE *ptr = fopen("testdata.in", "r");

    int tc;
    fscanf(ptr, "%d\n", &tc);

    for (int i = 1; i <= tc; i++) {
        int k;
        fscanf(ptr, "%d\n", &k);

        char string[1005];
        fscanf(ptr, "%[^\n]\n", string);

        int length = strlen(string);
        for (int j = 0; j < length; j++) {
            if ((string[j] - '0' >= 0) && (string[j] - '0' <= 9)) {
                convertToChar(&string[j]);
            }

            if (string[j] != ' ') {
                string[j] -= k;

                if (string[j] < 'A') {
                    string[j] += 26;
                }
            }
        }

        printf("Case #%d: %s\n", i, string);
    }

    return 0;
}