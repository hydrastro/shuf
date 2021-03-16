#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "shuf.h"

int main(int argc, char *argv[]){
    setbuf(stdout, NULL);
    FILE *stream;
    if(argc < 2){
        fprintf(stderr, "error: no file provided");

        return -1;
    }
    stream = fopen(argv[1], "rb");
    if(stream == NULL){
        fprintf(stderr, "an error occured while opening file");

        return -1;
    }
    printRandomRow(stream);
    fclose(stream);

    return 0;
}

int countFileRows(FILE *stream){
    char *readChar;
    int rows;
    rows = 0;
    readChar = malloc(sizeof(char));
    while(fread(readChar, sizeof(char), 1, stream) == 1){
        if(*readChar == '\n'){
            rows++;
        }
    }
    rewind(stream);

    return rows;
}

int getRandomInt(int min, int max){
    srand(time(NULL));

    return (rand() % (max - min)) + min;
}

void printFileRow(FILE *stream, int row){
    char *readChar;
    int currentRow;
    currentRow = 0;
    readChar = malloc(sizeof(char));
    while(row != currentRow && fread(readChar, sizeof(char), 1, stream) == 1){
        if(*readChar == '\n'){
            currentRow++;
        }
    }
    if(row == currentRow){
        while(fread(readChar, sizeof(char), 1, stream) == 1 && *readChar != '\n'){
            printf("%c", *readChar);
        }
    }
    rewind(stream);
}

void printRandomRow(FILE *stream){
    int rows, randomRow;
    rows = countFileRows(stream);
    randomRow = getRandomInt(0, rows - 1);
    printFileRow(stream, randomRow);
}
