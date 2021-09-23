#include<stdio.h>
#include<stdlib.h>
int full=0,count=0;
int value,empty;
int mutex=1;
int wait(int s)
{
	s--;
	return s;
}
int signal(int s)
{
	s++;
	return s;
}
void produce(int n,int buffer[])
{
	if(full==n)
		printf("\n\nBUFFER IS FULL!!!\n");
	else if(mutex!=1)
		printf("\nCAN'T ACCESS THE RESOURCE!!!");
	else
	{
		mutex=wait(mutex);
		empty=wait(empty);
		buffer[count]=++value;
		printf("produced the item : %d",buffer[count]);
		count++;
		full=signal(full);
		mutex=signal(mutex);
	}
}

void consume(int n,int buffer[])
{
	if(empty==n)
		printf("\n\nBUFFER IS EMPTY!!!\n");
	else if(mutex!=1)
		printf("\n\nCAN'T ACCESS THE RESOURCE!!!");
	else
	{
		mutex=wait(mutex);
		full=wait(full);
		count--;
		int consumed=buffer[count];
		printf("consumed item : %d",consumed);
		empty=signal(empty);
		mutex=signal(mutex);
	}
}

int main()
{
	int n,choice;
	printf("\nENTER THE BUFFER SIZE :");
	scanf("%d",&n);
	empty=n;
	int buffer[n];
	while(1)
	{
		printf("\n\nENTER AN OPTION !!\n1.PRODUCE\n2.CONSUME\n3.EXIT\n\n");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
				produce(n,buffer);
				break;
			case 2:
				consume(n,buffer);
				break;
			case 3:
				exit(0);
			default:
				printf("\nINVALID NUMBER!!!");
		}
	}
	return 0;
}
