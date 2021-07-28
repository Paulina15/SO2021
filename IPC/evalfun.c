#include <unistd.h>
#include <stdio.h>
#include <signal.h>
#include<sys/wait.h>
#include <stdlib.h>

int entrada=1;
void signalHandler(int sig){
	entrada=0;
	printf(" recibi señal %d\n", sig);
    exit(-1);
}
int main(){
    char fun[100];
    float inicio;
    float fin;
    float divisor;
    float promedio;
    float valor;

	int pp2c[2];
    int pc2p[2];
	int pid;
	pipe(pp2c);
    pipe(pc2p);
    signal(2,signalHandler);
	pid = fork();
	
	if (pid == 0){
		//hijo
		close(pp2c[1]);
		close(pc2p[0]);
		dup2(pp2c[0], STDIN_FILENO);
        dup2(pc2p[1], STDOUT_FILENO); 
		execlp("bc", "bc","-l", (char*) NULL);
	}

	if (pid > 0){
		//padre 	
		close(pp2c[0]);
		close(pc2p[1]);
		FILE *out = fdopen(pp2c[1], "w");
		FILE *in = fdopen(pc2p[0], "r");
		while(entrada){
			scanf("%s",fun);
			scanf("%f %f %f", &inicio, &fin, &divisor);
			float suma=0.0;
            float incremento=((fin-inicio)/divisor);
            for(float i=inicio;i<fin;i+=incremento){ 
                fprintf(out,"x=%f\n",i);   
                fprintf(out,"%s\n",fun);
                fflush(out); 
                fscanf(in,"%f",&valor);                                    
                fflush(in);
                suma+=valor;
			}
			 promedio=suma/divisor;
            printf("%f\n",promedio);
           
		}
       
		printf("voy a terminar \n");
        	
	}
	return 0;
}
