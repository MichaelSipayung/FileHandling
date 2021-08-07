#include "fileHeader.h"
#include "overview.h"
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
    //readInt();
    //storeStringFile();
    //readString();
    //storeFormat();
    //readFormat();
    //writeBlock();
    //readBlock();
    //writeString();
    //writeBlockData();
    //readBlockStruct();
    //customRead();
    //pointToPos();
    //morePointPos();
    //viewFile();
    //writeCsv();
    //makeCorrection();
    //seekToEnd();
    //alternatifFindPost();
    int *alloc;
    alloc= malloc(4* sizeof(*alloc));
    if(alloc){
        printf("Success to allocated the memory ....\n");
    }
    //alternaError();
    //alteropen();
    //showOut();
    //openTwo();
    //ifInDisk("formating.txt");
    //renameFile("contoh.txt","newContoh.txt");
    //removeFile("intRead.bin");
    //fileNumber();
    //showSize();
    celciusCon();
    reverseOrder();
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
/*
void writeBlock(){
    printf("write block data to stream\n");
    writeBl= openFile("wirteBlock.bin","wb");
    Langganan.nama="michael";
    Langganan.kode="ox-math";
    Langganan.hutang=12;
    if (writeBl){
        fwrite(&Langganan,sizeof(Langganan),1,writeBl);
    }
    else{
        printf("error occur.. can\'t write to stream\n");
        exit(1);
    }
    fclose(writeBl);
}
 */
void readBlock(){
    printf("Read block data from stream\n");
    writeBl=openFile("wirteBlock.bin","rb");
    if (writeBl){
        for (;;){
            fread(&Langganan,sizeof(Langganan),1,writeBl);
            if(feof(writeBl)){
                break;
            }
            printf("Langganan Kode \t: %s\n",Langganan.kode);
            printf("Langganan Nama\t: %s\n",Langganan.nama);
            printf("Langganan hutang \t: %f", Langganan.hutang);
        }
    }
    else{
        printf("error occur ..");
        exit(1);
    }
    fclose(writeBl);
}
void writeString(){
    stringTest= openFile("sample.txt","w+");
    if(stringTest){
        printf("Write and readt text, from set position\n");
        fputs("michael sipayung, address : madison avenue\nstatus: student\n",stringTest);
    }
    else{
        printf("Error occurs\n");
        exit(1);
    }
    fclose(stringTest);
    //reading the current text
    stringTest= openFile("sample.txt","r");
    printf("Read the value from given position\n");
    char readData[250];
    while (fgets(readData,250,stringTest)){
        printf("%s", readData);
    }
    fclose(stringTest);
}
void writeBlockData(){
    printf("Writing a record .....\n");
    blockData= openFile("langganan.bin","wb");
    int i,n=5;
    if (blockData){
        printf("Jumlah dari data\t: ");
        //scanf("%d",n);
        for (int j = 0; j < n; ++j) {
            printf("Data ke \t: %d \n",j+1);
            printf("Kode Langganan \t:");
            fflush(stdin);
            scanf("%s",Langganan.kode);
            printf("Nama Langganan \t:");
            fflush(stdin);
            scanf("%[^\n]",Langganan.nama);
            printf("Langganan Piutang \t:");
            fflush(stdin);
            scanf("%f",&Langganan.hutang);
            printf("\n");
            fwrite(&Langganan,sizeof(Langganan),1,blockData);
        }
    }
    else{
        printf("error occurs ...");
        exit(1);
    }
    fclose(blockData);
}
void readBlockStruct(){
    blockData= openFile("langganan.bin","rb");
    printf("Reading block data\n");
    int i=1;
    if (blockData){
        for (;;){
            fread(&Langganan, sizeof(Langganan),1,blockData);
            if(feof(blockData)){break;}
            printf("Data langganan ke \t: %d\n",++i);
            printf("kode Langganan\t:%s\n",Langganan.kode);
            printf("Nama Langganan\t:%s\n",Langganan.nama);
            printf("Hutang Langganan\t:%f\n",Langganan.hutang);
        }
    }
    else{
        printf("Eror occur .....\n");
        exit(1);
    }
}
void customRead(){
    customFileRead= openFile("book.txt","rb");
    int n;
    char c[128];

    if (customFileRead){
        printf("Ready to read data\n");
    for(;;){
        n= fread(c,1,128,customFileRead);
        for (int i = 0; i < n; ++i) {
            if (c[i]>=30&&c[i]<=126){
                printf("%c",c[i]);
            }
            else{
                printf(".");
            }
        }
        if(feof(customFileRead)){break;}
        }
    }
    else{
        printf("Eror occur ...\n");
        exit(1);
    }
    fclose(customFileRead);
}
void pointToPos(){
    customFileRead= openFile("book.txt","rb");
    int n ;
    char c[128];
    if (customFileRead){
        printf("ready to read the data\n");
        if(fseek(customFileRead,1,SEEK_SET)){//non zero will fail to test the condition
            printf("Error can\'t read given possition\n");
        }
        n= fread(c,1,128,customFileRead);
        for (int i = 0; i < n; ++i) {
            printf("%c", c[i]);
        }
    }
    else{
        printf("Error occur .. can\'t read file \n");
        exit(1);
    }
    fclose(customFileRead);
}
void morePointPos(){
    customFileRead= openFile("contohPos.bin","wb");
    char jawab;
    if (customFileRead){
        do {
            printf("\nkode langganan ?");
            fflush(stdin);
            scanf("%d",&anotherCostumer.kode);
            printf("Langganan nama \t: ");
            fflush(stdin);
            scanf("%[^\n]",anotherCostumer.nama);
            printf("Piutang langganan \t:");
            fflush(stdin);
            scanf("%f",&anotherCostumer.piutang);
            if (fseek(customFileRead,(anotherCostumer.kode-1)* sizeof(anotherCostumer),SEEK_SET)){
                printf("Wrong point ...");
                exit(1);
            }
            fwrite(&anotherCostumer,sizeof(anotherCostumer),1,customFileRead);
            printf("Insert more data ?");
            fflush(stdin);
            scanf("%c",&jawab);
            printf("\n");
        }while(jawab=='y'||jawab=='Y');
    }
    else{
        printf("Eror occurs ....");
        exit(1);
    }
    fclose(customFileRead);
}
void viewFile(){
    customFileRead= openFile("contohPos.bin","rb");
    int kodeLangganan;
    char jawab;
    if (customFileRead){
        printf("Ok read the given position \n");
        do {
            printf("kode langganan ? ");
            scanf("%d",&kodeLangganan);
            if(fseek(customFileRead,(kodeLangganan-1)*sizeof(anotherCostumer),SEEK_SET)){
                printf("Error occurs .. ");
                continue;//continue read another customer code
            }
            fread(&anotherCostumer,sizeof(anotherCostumer),1,customFileRead);
            if(feof(customFileRead)||anotherCostumer.kode!=kodeLangganan){
                printf("Sorry  data not found ...");
            }
            else{
                printf("\n");
                printf("Kode Langganan\t: %d\n", anotherCostumer.kode);
                printf("Nama Langganan\t: %s\n", anotherCostumer.nama);
                printf("Langganan piutang\t: %f\n", anotherCostumer.piutang);
            }
            printf("\n");
            printf("Looking for another customer \t:");
            fflush(stdin);
            scanf("%c",&jawab);
        }while(jawab=='y'||jawab=='Y');
    }
    else{
        printf("Eror occurs ..");
        exit(1);
    }
}
void writeCsv(){
    csvFile= openFile("book.csv","w+");
    if (csvFile){
        printf("\ncsv ready ...");
        fprintf(csvFile,"%s","nama;");
        fprintf(csvFile,"%s","Kota;");
    }
    else{
        printf("Fail to write csv ...");
        exit(1);
    }
}
void makeCorrection(){
    makeCorre= openFile("contohPos.bin","rb");
    int kodeLangganan;
    char jawab;
    long int PosisiSekarang;
    if(makeCorre){
        printf("Make correction to given record ....");
        do{
            printf("kode langganan \t: ");
            scanf("%d",&kodeLangganan);
            if(fseek(makeCorre,(kodeLangganan-1)* sizeof(anotherCostumer),SEEK_SET)){
                printf("sorry error occurs, invalid position ...");
                continue;
            }
            if ((PosisiSekarang= ftell(makeCorre))==-1L){
                printf("miss posistion to read ...");
                exit(1);
            }
            fread(&anotherCostumer,sizeof(anotherCostumer),1,makeCorre);
            if (feof(makeCorre)||anotherCostumer.kode!=kodeLangganan){
                printf("There isn\'t exist this costumer code ..");
            }
            else{
                printf("\n");
                printf("kode langganan \t: %d\n", anotherCostumer.kode);
                printf("Nama langganan \t: %s\n", anotherCostumer.nama);
                printf("hutang langganan \t: %f\n", anotherCostumer.piutang);
                printf("\n");
                printf("Please input for correction \n");
                printf("Nama langganan \t: ");
                fflush(stdin);
                scanf("%[^\n]",anotherCostumer.nama);
                printf("Piutang langganan \t: ");
                fflush(stdin);
                scanf("%f",&anotherCostumer.piutang);
                if (fseek(makeCorre,PosisiSekarang,SEEK_SET)){
                    printf("sorry .. something wrong to take the position");
                    exit(1);
                }
                fwrite(&anotherCostumer,sizeof(anotherCostumer),1,makeCorre);
                fflush(makeCorre);
            }
            printf("\n");
            printf("Akan mengoreksi data langganan yang lain .... ?");
            fflush(stdin);
            scanf("%c",&jawab);
            printf("\n");
        }while(jawab=='y'||jawab=='Y');
    }
    else{
        printf("error occur ....");
        exit(1);
    }
}
void seekToEnd(){
    seekEnd=openFile("contohPos.bin","w+b");
    if(seekEnd){
        printf("Put to the end of word .... ");
        if(fseek(seekEnd,0,SEEK_END)){
            printf("wrong position ....");
            exit(1);
        }
        fwrite(&anotherCostumer,sizeof(anotherCostumer),1,seekEnd);
        anotherCostumer.kode=13;
        anotherCostumer.piutang=90.98;
        //set to first position
        if(fseek(seekEnd,0,SEEK_SET)){
            printf("wrong .. can\'t set to first line ...\n");
        }
        printf("print all with the last input ...");
        for(;;){
            fread(&anotherCostumer, sizeof(anotherCostumer),1,seekEnd);
            if(feof(seekEnd)){
                break;
            }
            printf("Kode langganan\t: %d\n",anotherCostumer.kode);
            printf("nama langganan\t: %s\n",anotherCostumer.nama );
            printf("piutang langganan\t: %f\n",anotherCostumer.piutang);
        }

    }
    else{
        printf("something went wrong ... ");
        exit(1);
    }
    fclose(seekEnd);

}
void alternatifFindPost(){
    costumPost= openFile("contohPos.bin","r+b");
    int kodeLang;
    char jawab;
    fpos_t posisiSekarang;
    if(costumPost){
        printf("file ready to modify ....\n");
        do {
            printf("Kode langganan");
            scanf("%d",&kodeLang);
            if(fseek(costumPost,(kodeLang-1)* sizeof(anotherCostumer),SEEK_SET)){
                printf("something wrong ...");
                continue;
            }
            if(fgetpos(costumPost,&posisiSekarang)!=0){
                printf("Eror occurs ...");
                exit(1);
            }
            fread(&anotherCostumer, sizeof(anotherCostumer),1,costumPost);
            if(feof(costumPost)||anotherCostumer.kode!=kodeLang){
                printf("Eror occurs , can\'t find the given code ...\n");
            }
            else{
                printf("\n");
                printf("langganan kode \t: %d\n",anotherCostumer.kode);
                printf("langgana name \t: %s\n",anotherCostumer.nama);
                printf("\n");
                printf("MAKE CORRECTION \t: .....");
                printf("Nama langganan \t: ");
                fflush(stdin);
                scanf("%[^\n]",anotherCostumer.nama);
                if(fsetpos(costumPost,&posisiSekarang)!=0){
                    printf("Ada kesalahn mengembalikan posisi ....");
                    exit(1);
                }
                fwrite(&anotherCostumer,sizeof(anotherCostumer),1,costumPost);
                fflush(costumPost);
            }
            printf("koreksi data lagi \t: (y/n)");
            fflush(stdin);
            scanf("%c",&jawab);
            printf("\n");
        }while(jawab=='y'||jawab=='Y');
    }
    else{
        printf("error occurs ...");
        exit(1);
    }
    fclose(costumPost);
}
void alternaError(){
    erortest= openFile("book.txt","r+b");
    if(ferror(erortest)==0){
        perror("wrong ...");
        clearerr(erortest);
        exit(1);
    }
    else{
        printf("ready to open ...");

    }
    fclose(erortest);
}
void alteropen(){
    int *array;
    array= malloc(8*sizeof(*array));

    if(freopen("contoh.txt","w",stdout)==NULL){
        printf("Wrong ... ");
        exit(1);
    }
    printf("write to stream not to terminal ....\n");
    printf("write again to stream ....\n");
    for (int i = 0; i < 7; ++i) {
     array[i]=i;
     printf("%d\n",array[i]);
    }
    free(array);
}
void showOut(){
    if(freopen("stdin.txt","w",stdin)==NULL){
        printf("wrong .....");
        exit(1);
    }
    char mode[20];
    printf("mode file in c \t: ");
    fflush(stdin);
    //scanf("%[^\n]",mode);
}
void openTwo(){
    char c[PANJANG_BYTE],jawab;
    unsigned n;
    unsigned long int jumlahByte=0;
    source= fopen("book.txt","rb");
    if(source){
        jawab='T';
        while (jawab=='t'||jawab=='T'){
            if((destination= fopen("destination.txt","r"))==NULL){
                printf("Wrong ....");
                break;
            }
            else{
                printf("Sudah ada ditampungi ... (y | t) ?");
                fflush(stdin);
                scanf("%c",&jawab);//bug
                fclose(destination);
            }
        }
    }
    else{
        printf("sorce not available ...");
        exit(1);
    }
    destination= fopen("destination.txt","wb");
    if(destination==NULL){
        printf("Sorry wrong .. can\'t open file \n");
        exit(1);
    }
    printf("\n");
    do {
        n=fread(c,1,PANJANG_BYTE,source);
        fwrite(c,1,n,destination);
        jumlahByte+=n;
    }while(!feof(source));
    printf("finish ....");
    printf("Jumlah byte yang disalin .... \t: %d\n", jumlahByte);

    //fcloseall();
    fclose(destination);
    fclose(source);
}
void ifInDisk();
void ifInDisk(char *namaFile){
    printf("check if the given file still exist \t:\n");
    if((access(namaFile,0))==0){
        printf("good file is exist   .... \n");
    }
    else{
        printf("Wrong , not exist ...");
        exit(1);
    }
}
void renameFile(char*currentName,char*newName){
    if((rename(currentName,newName))==0){
        printf("success to rename ....\n");
    }
    else{
        printf("wrong, please check the current file ...");
        exit(1);
    }

}
void removeFile(const char*namaFile){
    printf("Try to remove file ...");
    if((unlink(namaFile))==0){
        printf("%s success dihapus ....\n" ,namaFile );
    }
    else{
        printf("Sorry not exist ...\n");
        exit(1);
    }
}
void fileNumber(){
    printf("first check if file exist\n");
    source  = openFile("string.txt","rb");
    if(source){
        printf("nomor pengenal file \t: %d\n", fileno(source));
    }
    else{
        printf("Error occurs ...\n");
        exit(1);
    }
    fclose(source);
}
void showSize(){
    source= openFile("sample.txt","r");
    int handle;
    if (source){
        printf("file exist\n");
        handle= fileno(source);
        printf("size is \t: %d byte\n", filelength(handle));
    }
    else{
        printf("wrong .. file not exist ...");
        exit(1);
    }
    fclose(source);
}
void celciusCon(){
    float fahr,celcius,lower,upper,step;
    lower=0; upper=300;step=20;
    printf("Celcius\tFahrenheit\n");
    fahr=lower;
    while (fahr<=upper){
        celcius=5*(fahr-32)/9;
        printf("%3.0f\t%6.1f\n",fahr,celcius);//three digits wide and si
        fahr+=step;
    }
}
void reverseOrder(){
    float fahr,celcius,step,lower,upper;
    lower =0;
    upper=300;
    step=20;
    fahr =upper;
    printf("-----------------------------\n");
    printf("Celcius\tFahrenheit\n");
    printf("-----------------------------\n");
    while (lower<=fahr){
        celcius=5*(fahr-32)/9;
        printf("%3.0f\t%6.1f\n",fahr,celcius);//three digits wide and
        fahr-=step;
    }
}






