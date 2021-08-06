#ifndef UNTITLED_FILEHEADER_H
#define UNTITLED_FILEHEADER_H
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <ctype.h>
#include <io.h> //file tidak berpenyangga protorype
#define PANJANG_BYTE 256
FILE *anotherSample,*experimen,*fileInt,*stringFile,*formatingFile,*writeBl,*stringTest;
FILE *openFile(char*,char[]);
FILE *experimentOpen(char*,char[]);
FILE *blockData,*customFileRead,*csvFile,*makeCorre;
FILE *seekEnd,*costumPost,*erortest;
FILE *source,*destination;
void storeInt();
void readInt();
void storeStringFile();
void readString();
void storeFormat();
void readFormat();
struct {
    char kode[5];
    char nama[20];
    float hutang;
}Langganan;
struct{
    int kode;
    char nama[20];
    float piutang;
}anotherCostumer;
void writeBlock();
void readBlock();
void writeString();
void writeBlockData();
void readBlockStruct();
void customRead();
void pointToPos();
void morePointPos();
void inputBlock();
void viewFile();
void writeCsv();
void makeCorrection();
void seekToEnd();
void alternatifFindPost();
void alternaError();
void alteropen();
void showOut();
void openTwo();
void inBuffer();
void ifInDisk(char*);
void renameFile(char*,char*);
void removeFile(const char*);
void fileNumber();
void showSize();
#endif //UNTITLED_FILEHEADER_H
