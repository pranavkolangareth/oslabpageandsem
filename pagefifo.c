#include <stdio.h>
#include <stdlib.h>

int is_in_frame(int page_ref, int frame[], int f){
    for(int i=0;i<f;i++){
        if(page_ref==frame[i])
            return 1;
    }
    return -1;
}

void fifo(){
    int n,f,fault,first;
    int page[101], frame[25];
    printf("Enter the number of pages: ");
    scanf("%d",&n);
    printf("Enter the page reference string: ");
    for(int i=0;i<n;i++){
        scanf("%d",&page[i]);
    }
    printf("Enter the number frame: ");
    scanf("%d",&f);
    for(int i=0;i<f;i++)
	{
	  frame[i]=-1;
	}	
    
    fault=0;
    first=0;
    for(int i=0;i<n;i++){
        if(is_in_frame(page[i],frame,f)==-1){
            fault++;
            frame[first]=page[i];
            first=(first+1)%f;
	    for(int k=0;k<f;k++)
	    {
		if(frame[k]==-1)
			printf(" \t");
		else
			printf("%d\t",frame[k]);
		
	    }
	    printf("\n");
        }
    }
    printf("The number of page faults is %d\n",fault);
}

int main(){
    fifo();
    return 0;
}
