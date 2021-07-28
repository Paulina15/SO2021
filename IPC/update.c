#include "student.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char **argv) {
  char *filename = argv[1];
  char *atributo = argv[2];
  char *palabra = argv[3];
  int cuantos= atoi(argv[2]);
  int result;

  FILE *forigen;
  forigen = fopen(filename,"rb");
  STUDENT newstudent;
  
  while(fread(&newstudent,sizeof(newstudent),1,forigen)){
      
     if(strcmp(atributo,"name")==0){
        strcmp(palabra,newstudent.name);
      }

      if(strcmp(atributo,"lastname")==0){
        if(strcmp(palabra,newstudent.lastname)==0){
          printf("%s %s %d %d \n",newstudent.name,newstudent.lastname,newstudent.id,newstudent.semestre);
        }
      }
       
      if(strstr(atributo,"id")==NULL){
          strstr(palabra,"id");
      }
      if(strstr(atributo,"semestre")==NULL){
          strstr(palabra,"semestre");
      }
  }
    fclose(forigen);
}
