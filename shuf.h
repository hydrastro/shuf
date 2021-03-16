#ifndef SHUF_H
#define SHUF_H

int countFileRows(FILE *stream);
int getRandomInt(int min, int max);
void printFileRow(FILE *stream, int row);
void printRandomRow(FILE *stream);

#endif //SHUF_H
