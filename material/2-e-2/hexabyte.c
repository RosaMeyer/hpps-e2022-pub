#include <stdio.h>
#include <assert.h>

// A hex dumper (from file "ints.bin")
int main(int argc, char** argv) {
    assert(argc == 2);

    // Open for reading ("r")
    FILE *f = fopen(argv[1], "r");
    assert(f != NULL);

    // Hvis du i stedet skriver: sizeof(argc) får man kun de tal hvor det ikke er nul
    while (fread(&argc, sizeof(char), 1, f) == 1) {
        printf("%.2x\n", argc);
    }

    fclose(f);
}



