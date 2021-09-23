#include <stdio.h>

int is_in_frame(int page_ref, int frame[][2], int f){
    for(int i=0;i<f;i++){
        if(page_ref==frame[i][0])
            return i;
    }
    return -1;
}

int min(int arr[][2], int size){
    int ind = -1;
    int MIN = 10000;
    for(int i=0;i<size;i++){
        if(arr[i][1]<MIN ){
            MIN = arr[i][1];
            ind = i;
        }
    }
    return ind;
}

void lru(){
    int n,f,fault;
    int page[101], frame[25][2], lru[25]; // page[][0] stores the reference and [][1] stores the recency number
    printf("Enter the number of pages: ");
    scanf("%d",&n);
    printf("Enter the page reference string: ");
    for(int i=0;i<n;i++){
        scanf("%d",&page[i]);
    }
    printf("Enter the number frame: ");
    scanf("%d",&f);
    fault=0;
    for(int i=0;i<f;i++)
    {
        frame[i][1]=-1;
	frame[i][0]=-1;
    }
    for(int i=0;i<n;i++){
        if(is_in_frame(page[i],frame,f)==-1){
            int ind = min(frame,f);
            frame[ind][0]=page[i];
            fault++;
            frame[ind][1]=i;
	    for(int k=0;k<f;k++)
	    {
		if(frame[k][0]==-1)
			printf(" \t");
		else
			printf("%d\t",frame[k][0]);
		
	    }
	    printf("\n");
        }
        else{
            int ind = is_in_frame(page[i],frame,f);
            frame[ind][1] = i;
        }
    }
    printf("number of page faults is %d\n",fault);
}

int main(){
    lru();
    return 0;
}
