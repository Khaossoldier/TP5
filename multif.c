#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

/*Definition du type pour les fonctions */
typedef int (*func_t) (int);


/* Implementation de la fonction multif */
int
multif
(func_t f[], int args[], int n){
	int k;
    int i;
	pid_t pid;
    
    k = 1;
    
    /*Creation des processus fils*/
	for (i=0; i<n; i++){
	    /* Creation d'un processus fils */
        pid = fork();
        switch (pid){
            /* Cas ou le fork echoue */
            case -1: exit(EXIT_FAILURE);
            /* Cas ou le fork reussit */
            /* Exit permet de recuperer la valeur de la foction */
            case 0: exit(f[i](args[i]));     
	    }
    }
    
    /* Recuperation et traitement des valeures renvoyes par les processus fils */
    for (i=0; i<n; i++){
        wait(&k);
        /* On regarde si le fils s'est termine normalement*/
        if (WIFEXITED(k)){
            /* Recuperation de la valeur de retour du processus fils*/
            k = k && WEXITSTATUS(k);
        }    
    }

    if (k == 1)
        printf("true\n");
    else
        printf("false\n");
    return k;
}

/* Differentes definitions de fonctions */

int f0(int a){
    return a==a;
}

int f1(int a){
    return a==a;
}

int f2(int a){
    return a!=a;
}

int
main
(int argc, char *argv[]){
    int tab_args[3];
    func_t tab_f[3];


    tab_args[0] = 1;
    tab_args[1] = 1;
    tab_args[2] = 1;

    tab_f[0] = f0;
    tab_f[1] = f1;
    tab_f[2] = f2;
    
    printf("Execution de trois fonctions : 2 true, 1 false\n"); 
    multif(tab_f, tab_args, 3);

    printf("Execution de trois fonctions : 3 true\n");
    tab_f[0] = f0;
    tab_f[1] = f1;
    tab_f[2] = f1;

    multif(tab_f, tab_args, 3);
    

    return 0;
}
