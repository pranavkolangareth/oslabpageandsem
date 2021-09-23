#include<stdio.h>
 
int who_came_first(int a[],int f,int s,int seen,int b[])
{
int f1,s1;
int x=b[f];
int y=b[s];
for(int i=0;i<seen;i++)
{
if(x==a[i])
f1=i;
if(y==a[i])
s1=i;
}

if(s1<f1)
return 1;

}


int findLFU(int frames[],int pages[],int time[], int n,int seen)
{
	int i, min = time[0], pos = 0;

    	for(i = 1; i < n; ++i)
	{
        	if(time[i] < min)
		{
            		min = time[i];
            		pos = i;
        	}
		if(time[i]==min)
		{

		if(who_came_first(pages,pos,i,seen,frames)==1)
		pos=i;	
		}
    	}
    	return pos;
}
 
int main()
{
    int frames[10], pages[30], counter = 0, time[10], flag1, flag2, pos, fault = 0;
    int n,f,i,j;
    printf("Enter number of pages: ");
    scanf("%d", &n);
    printf("Enter number of frames: ");
    scanf("%d", &f);   
    printf("Enter reference string: ");
    for(i = 0; i < n; ++i)
    {
         scanf("%d", &pages[i]);
    }
        
    for(i = 0; i < f; ++i)
    {
         frames[i] = -1;
    }
    for(int i=0;i<f;i++)
	time[i]=0;

    for(i = 0; i < n; ++i)
    {
         flag1 = flag2 = 0;
        
         for(j = 0; j < f; ++j)
	 {
             if(frames[j] == pages[i])
	     {
                 counter++;
                 time[j]++;// = counter;
                 flag1 = flag2 = 1;
                 break;
             }
         }
        
         if(flag1 == 0)
	 {
        	for(j = 0; j < f; ++j)
		{
         		if(frames[j] == -1)
			{
         			counter++;
         			fault++;
         			frames[j] = pages[i];
         			time[j]++;// = counter;
         			flag2 = 1;
         			break;
         		}
         	}
         }
        
         if(flag2 == 0)
	 {
         	pos = findLFU(frames,pages,time, f,i);
         	counter++;
         	fault++;
         	frames[pos] = pages[i];
         	time[pos] = 1;
         }
        
         printf("\n");
        
         for(j = 0; j < f; ++j)
	 {
	     if(frames[j]!=-1)
             	printf("%d\t", frames[j]);
	     else 
		printf(" \t");
         }
    }
    printf("\n\nTotal Page Faults = %d\n", fault);
        
    return 0;
}

