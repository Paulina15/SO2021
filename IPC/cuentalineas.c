#include <unistd.h>
#include <ctype.h>
#include <stdio.h>

//0=stdin
//1=stdout

int main(){
    char minC;
    int cont=0;
    while(read(0,&minC,1)){
         if(minC=='\n'){
            cont++;
        }
        
    }
    if(minC!='\n'){
        cont++;
    }
    printf("contador: %d\n",cont);
    return 0;
}

