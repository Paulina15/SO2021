#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argnum, char **argv){
    char *original = argv[1];
    char *destino = argv[2];
    char buffer;
    char *linea;
    int size=0;
    FILE *foriginal, *fdestino;
    foriginal = fopen(original,"rb");
    fdestino = fopen(destino,"wb");
    int var=fread(&buffer,sizeof(char),1,foriginal); ;
    while(var){
        size += 1;
        if(buffer == '\n'){
            fseek(foriginal, -size, SEEK_CUR);
            linea = (char *) calloc(size, sizeof(char));
            fread(linea,sizeof(char),size,foriginal);
            if(strstr(linea,"hola") == NULL){
                fwrite(linea,sizeof(char),size,fdestino);
            }
            size = 0;
        }
        var=fread(&buffer,sizeof(char),1,foriginal); 
        if(!var){
            fseek(foriginal, -size, SEEK_CUR);
            linea = (char *) calloc(size, sizeof(char)); 
            fread(linea,sizeof(char),size,foriginal);
            if(strstr(linea,"hola") == NULL){
                fwrite(linea,sizeof(char),size,fdestino);
            }
        }
    }
    
    fclose(foriginal);
    fclose(fdestino);

    return 0;
}