#include<sys/ipc.h>
#include<sys/shm.h>
#include<stdio.h>
#include<stdlib.h>

int main()
{
    key_t token = ftok("SHAREDMEM",69);
    int shmId = shmget(token, 1024, 0666|IPC_CREAT);
    char* str = (char*) shmat (shmId, (void*)0, 0);
    int choice,size,i=0,j=0;
    printf("Enter the buffer size : ");
    scanf("%d",&size);
    str[0]=size;
    str[1]=size;//empty
    str[2]=0;//full
    while(1)
    {
        printf("\n1.Produce\n2.Consume\n3.Stop\nEnter Choice: ");
        scanf("%d",&choice);
        switch(choice){
            case 1: if(str[2]==size)
            	    {
            	    	printf("Buffer is full\n");
            	    }
            	    else
            	    {
            	    	i++;
            	    	int data= rand()%10;
                   	printf("Produced the item :%d",data);
                    	sprintf(&str[2+i],"%d",data);
                    	str[2]++;
                    	str[1]--;
            	    }
                    break;
            case 2: if(str[1]==size)
            	    {
            	    	printf("Buffer is empty\n");
            	    }
            	    else
            	    {
			j++;
            	    	printf("Consumed the item %c",str[2+j]);
            	    	str[1]++;
            	    	str[2]--;
            	    	
            	    }
                    break;
            case 3: printf("\nDetaching the shared memory\n");
                    shmdt(str);
                    shmctl(shmId, IPC_RMID,NULL); 
                    exit(0);
                    break;
            default: printf("Invalid option!!! \nEnter 1/2/3\n");
        }
    }
    return 0;
}
