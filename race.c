#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

void count()
{

	int j;
	for(j=0;j<100000000;j++)
	{
	}
}


int main(void){
	int i,k;
	for(i=0;i<10;i++)
	{
		switch(fork())
		{
			case -1: exit(EXIT_FAILURE);
			case 0: count();	
			exit(i);
		}
	}
	for(k=0;k<10;k++)
	{
		wait(&i);
		if(WIFEXITED(i))
		{
			printf("%d\n",WEXITSTATUS(i));
		}
	}

}



