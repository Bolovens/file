#include <stdio.h>
#include <string.h>

typedef struct Name {
    char name[45];
    char plant[45];
} List;

List dict[105];

int main(int argc, char *argv[]) {
    FILE *ptr = fopen("testdata.in", "r");

    int length;
    fscanf(ptr, "%d\n", &length);

    for (int i = 0; i < length; i++) {
        fscanf(ptr, "%[^#]#%[^\n]\n", dict[i].name, dict[i].plant);
    }

    int tc;
    fscanf(ptr, "%d\n", &tc);

    for (int i = 1; i <= tc; i++) {
        char string[45];
        fscanf(ptr, "%s\n", string);

        printf("Case #%d: ", i);

        int check = 0;
        for (int j = 0; j < length; j++) {
            if (!strcmp(string, dict[j].name)) {
                printf("%s\n", dict[j].plant);
                check = 1;
                break;
            }
        }

        if (!check) {
            printf("N/A\n");
        }
    }

    fclose(ptr);
    
    return 0;
}