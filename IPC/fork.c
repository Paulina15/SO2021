#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <sys/wait.h>

//int varGlobal;

void signalHandler(int sig){
    int pidHijoTermino=wait(NULL);
    printf("Mi hijo termino %d\n", pidHijoTermino);
    //varGlobal=0;
}
int main(){
    
    signal(17,signalHandler);
    int pid=fork();
    int pidHijoTermino;
    if(pid==0){
        printf("Soy el proceso hijo\n");
    }else{
        printf("Soy el proceso padre y mi hijo es %d\n", pid);
        //pidHijoTermino=wait(NULL);
       //varGlobal=1;
        //signal(15,signalHandler);
        while(1){
            printf("Trabajando\n");
            sleep(1);
        }
        printf("Mi hijo termino\n");
        
    }
    printf("Terminado\n");
    return 0;
}