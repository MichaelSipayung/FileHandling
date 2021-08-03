//
// Created by zyrex on 8/3/2021.
//

#ifndef UNTITLED_FILEHEADER_H
#define UNTITLED_FILEHEADER_H
#include <stdio.h>
FILE *anotherSample,*experimen,*fileInt,*stringFile,*formatingFile,*writeBl;
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
#endif //UNTITLED_FILEHEADER_H
