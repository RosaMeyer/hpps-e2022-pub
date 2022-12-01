#include <stdio.h>
#include <assert.h>

// Converting binary integers to ASCII integers
int read_int(FILE *f, int *out) {
    int read = fread(out, sizeof(out), 1, f);
    if (read == 1) {
        return 0;
    }
    else {
        return 1;
    }
}

int main(int argc, char** argv) {
    assert(argc == 2);
 
    FILE *f = fopen(argv[1], "r");
    assert(f != NULL);

    while (fread(&argc, sizeof(argc), 1, f) == 1) {
        printf("%d\n", argc);
    } 

    fclose(f);
} 
