//Author Peter Adamson

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

void allocate();
int randInt(int min, int max);

int t;
size_t addr[100000];

int main()
{
	int loop = 1;
	int num;
	int i;
	int j;
	int t = 0;
	int diffSum = 0;
	int diffAvg;
	while(loop == 1)
	{
		printf("how many times would you like to loop? (0 to exit)");
		fscanf(stdin, "%d", &num);
		if(num == 0)
		{
			loop = 0;
		}
		else if(num > 0)
		{
			for(i = 0; i < num; i++)
			{
				allocate();
			}	
		}
		else
		{
			printf("please enter a valid number\n");
		}
		printf("completed looping %d times.  Lets go again.\n",num);
	}
	for(i = 0; i < 99999; i++)
	{
		diffSum = diffSum + (addr[i+1] - addr[i]);
	}
	diffAvg = diffSum / (100000);
	printf("average difference between calls to malloc: %d\n",diffAvg);
	printf("exiting\n");
}

void allocate()
{
	void *p;
	p = malloc(1024 * 1024 * 1024);
	double *big;
	double check = 0.0;
	while(1)
	{
		big = (double*)malloc(sizeof(double) * 100000000);
		memset(big, 1, 100000000);		
		int ind = randInt(0,536870913);
		check += big[ind];
	}
	//int *i = (int*)calloc(1,h);
	//int *i = (int*)malloc(h);
	if(p == NULL)
	{
		printf("%d\n",errno);
		perror("malloc");
		exit(1);
	}
	addr[t] = (size_t)p;
	printf("address of i: %p\n",addr[t]);
	int rando = randInt(0,1);
	/*if(rando == 1)
	{
		printf("freed %p\n",addr[t]);
		free(i);
	}*/
	t = t + 1;
}

//generates a random integer between min and max (inclusively)
int randInt(int min, int max)
{
	return rand() % (max + 1 - min) + min;
}
