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
    //storeInt();
    readInt();
    //storeStringFile();
    readString();
    //storeFormat();
    readFormat();
    return 0;
}
FILE *openFile(char*namaFile,char mode[]){
    return(anotherSample= fopen(namaFile,mode));
}
FILE *experimentOpen(char*namFile,char modeOpen[]){
    return (experimen= fopen(namFile,modeOpen));
}
void storeInt(){
    int x[]={1,2,3,4,5,6,7};
    fileInt=experimentOpen("intRead.bin","wb");
    printf("File the data\n");
    if(fileInt){
        for (size_t i=0;i<(sizeof(x)/sizeof(*x));++i){
            putw(x[i],fileInt);
        }
    }
    else{
        printf("error occur\n");
    }
    fclose(fileInt);
}
void readInt(){
    int x;
    fileInt=experimentOpen("intRead.bin","rb");
    printf("File the data\n");
    if(fileInt){
        for (; ;) {
            x=getw(fileInt);
            if (feof(fileInt)){break;}
            printf("%d| ",x);
        }
    }
    else{
        printf("error occur\n");
    }
    fclose(fileInt);
}
void storeStringFile(){
    printf("Input string to file\n");
    stringFile= openFile("string.txt","w");
    char name[]="michael 1";
    char lastName[]="Sipayung ";
    if(stringFile){
        fputs(name,stringFile);
        fputs(lastName,stringFile);
    }
    else{
        printf("Error occur");
        exit(1);
    }
    fclose(stringFile);
}
void readString(){
    printf("Read string to buffer\n");
    stringFile= openFile("string.txt","r");
    char nama[50];
    if(stringFile){
        while(fgets(nama,100,stringFile)){
            printf("%s\n",nama);
        }
    }
    else{
        printf("Error occur");
        exit(1);
    }
    fclose(stringFile);
}
void storeFormat(){
    printf("Store data .. with formating all data ..\n");
    formatingFile=openFile("formating.txt","w");
    int umur=12;
    char name[]="Michael";
    if(formatingFile){
        fprintf(formatingFile,"%s %d \n",name,umur);
    }
    else{
        printf("Eror occur ..");
        exit(1);
    }
    fclose(formatingFile);
}
void readFormat(){
    printf("Reading formatting data\n");
    formatingFile= openFile("formating.txt","r");
    char nama[45];
    int umur;
    if (formatingFile){
        while (fscanf(formatingFile,"%s %d",nama,&umur)!=EOF){
            printf("Nama pelanggan %s\n",nama);
            printf("Umur pelanggan %d tahun\n",umur);
        }
    }
    else{
        printf("Eror occur ..\n");
        exit(1);
    }
    fclose(formatingFile);
}
