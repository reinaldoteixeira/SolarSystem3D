#include <fstream>
unsigned char header[54]; // TODO ARQUIVO BMP POSSUI UM CABE�ALHO DE 54 BYTES ANTES DOS DADOS DA MATRIZ DA IMAGEM
unsigned int dataPos;     // POSI��O DO ARQUIVO ONDE COME�AM DOS DADOS DA IMAGEM
unsigned int width, height; //LARGURA E ALTURA DA IMAGEM
unsigned int imageSize;   // TAMANHO = width*height*3 (3 BYTES POR DADO, DEVIDO AO R, G e B PARA CADA PIXEL)
unsigned char * data; //BUFFER QUE CONTER� OS DADOS DA MATRIZ DA IMAGEM
GLuint loadBMP(const char * imagepath){
    FILE * file = fopen(imagepath,"rb");
    if (!file){printf("O ARQUIVO DE IMAGEM NAO EXISTE\n"); return 0;}
    if ( fread(header, 1, 54, file)!=54 ){ // ERRO SE N�O TIVER 54 BYTES PRA SEREM LIDOS
        printf("ARQUIVO BMP INVALIDO!\n");
        return false;
    }
    if ( header[0]!='B' || header[1]!='M' ){
        printf("ARQUIVO BMP INVALIDO!\n");
        return 0;
    }
    // Lendo os inteiros do vetor de bytes do cabe�alho:
    dataPos    = *(int*)&(header[0x0A]);
    imageSize  = *(int*)&(header[0x22]);
    width      = *(int*)&(header[0x12]);
    height     = *(int*)&(header[0x16]);
    //CORRIGINDO ALGUNS PROBLEMINHAS QUE EXISTEM EM ALGUNS ARQUIVOS BMP:
    if (imageSize==0)    imageSize=width*height*3; // 1 byte pra RED, 1 byte pra GREEN, 1 byte pra BLUE
    if (dataPos==0)      dataPos=54; //O cabe�alho dos arquivos BMP funciona assim (ver slides)
    // Criando o buffer "data" contendo os dados da imagem
    data = new unsigned char [imageSize];
    fread(data,1,imageSize,file);
    fclose(file);
}
