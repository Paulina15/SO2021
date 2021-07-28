#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>

int main(int argvnum, char **argv){
    char *arch1 = argv[1]; 
    char *arch2 = argv[2];
    struct stat sb1;
    struct stat sb2;
    if(stat(arch1, &sb1) == -1){
        printf("Error el archivo no existe \n");
        return -1;
    }
    else{
         if(stat(arch2, &sb2) == -1){
              char buffer[200];
                sprintf(buffer,"%s/%s",arch2,arch1);
                link(arch1, buffer);
                unlink(arch1);
         }
         
         else{
            if(S_ISREG(sb2.st_mode)){
                printf("Error el archivo 2 ya existe \n");
                return -1;
            }
            if(S_ISDIR(sb2.st_mode)){
                printf("Archivo 2 es un directorio \n");
                char buffer[200];
                sprintf(buffer,"%s/%s",arch2,arch1);
                link(arch1, buffer);
                unlink(arch1);
                
            } 
         }
    }
      
    return 1;
}

