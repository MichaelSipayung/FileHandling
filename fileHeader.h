#ifndef UNTITLED_FILEHEADER_H
#define UNTITLED_FILEHEADER_H
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <ctype.h>
FILE *anotherSample,*experimen,*fileInt,*stringFile,*formatingFile,*writeBl,*stringTest;
FILE *openFile(char*,char[]);
FILE *experimentOpen(char*,char[]);
void storeInt();
void readInt();
void storeStringFile();
void readString();
void storeFormat();
void readFormat();
struct {
    char *kode;
    char *nama;
    float hutang;
}Langganan;
void writeBlock();
void readBlock();
void writeString();

#endif //UNTITLED_FILEHEADER_H
