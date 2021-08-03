#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "fileHeader.h"
int main() {
    printf("File handling in Action \n");
    FILE *pointFile;
    pointFile = fopen("data.txt","a");
    if (pointFile){
        printf("File berhasil ditulis\n");
    }
    else{
        printf("something wrong");
        exit(1);
    }
    fclose(pointFile);
    /*FILE *book;
    char write;
    book= fopen("book.txt","w");
    if (book){
        printf("Writeb a sentence \t: ");
        while ((write=getche())!='\r'){
            fputc(write,book);
        }
    }
    fclose(book);
    */
    FILE *book;
    char write;
    book= fopen("C:\\Users\\zyrex\\CLionProjects\\untitled\\CMakeLists.txt","r");
    if(book){
        while((write=fgetc(book))!=EOF){
            putchar(write);
        }
    }
    else{
        printf("Eror file not exist");
    }
    fclose(book);
    printf("Another sample\n");
    char namaFile[120]="bookStore2.txt",c,jawab;
    if (openFile(namaFile,"r")==NULL){
        printf("File isn\'t ready, make it ( y or n ) ?");
        jawab=getche();
        printf("\n");
        if(!(jawab=='y'||jawab=='Y')){ exit(0);}
    }
    else{
        printf("Isi file sebelumnya\t: ");
        while((c=getc(anotherSample))!=EOF){
            putchar(c);
        }
        printf("\n");
    }
    fclose(anotherSample);
    if(openFile(namaFile,"a")==NULL){
        printf("something wrong\n");
        exit(1);
    }
    else{
        printf("Masukan data karakter-karakter baru (Enter untuk selesai)\n");
        /*while((c=getche())!='\r'){
            putc(c,anotherSample);
        }*/
        fclose(anotherSample);
    }
    printf("Open file using functioh\n");
    experimentOpen("experiment.txt","r");
    if(experimen==NULL){
        printf("File not exist, make new file\n");
        experimentOpen("experiment.txt","w");
        fclose(experimen);
    }
    else{
        printf("File still exist\n");
    }
    return 0;
}
FILE *openFile(char*namaFile,char mode[]){
    return(anotherSample= fopen(namaFile,mode));
}
FILE *experimentOpen(char*namFile,char modeOpen[]){
    return (experimen= fopen(namFile,modeOpen));
}
