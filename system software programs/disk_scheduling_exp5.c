#include <stdlib.h>
#include <stdio.h>

void sort(int a[],int n)
{
    int i,temp=0,j;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n-i-1;j++)
        {
            if(a[j]>a[j+1])
            {
                temp=a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
            }
        }
    }
}

void fcfs(int m,int q_size,int h,int queue[])
{
    int i,thm=0,diff=0,head;
    head=h;

    for(i=0;i<q_size;i++)
    {
     	  diff=abs(queue[i]-head);
     	  thm+=diff;
     	  head=queue[i];
    }
    printf("\nTotal head movement : %d\n",thm);          
}

void scan(int m,int q_size,int h,int queue[])
{
    int i,array[20],thm=0,prehead=0,max,head;
    max=m;head=h;

    printf("\nEnter the previous position of head :");
    scanf("%d",&prehead);

    for (i=0;i<q_size;i++) array[i]=queue[i];
    sort(array,q_size);

    

    if(head>prehead)
    {
        thm=abs(max-head+max-array[0]);
    }
    else
    {
        thm=abs(head+array[q_size-1]);
    }
    printf("\nTotal head movement : %d\n",thm);
}

void cscan(int m, int q_size,int h,int queue[])
{
  int i,j,array[20],thm=0,prehead=0,head=0,max=0;
  head=h;max=m;

  for (i=0;i<q_size;i++) array[i]=queue[i];
  sort(array,q_size);

  printf("\nEnter the previous position of head :");
  scanf("%d",&prehead);

    if(head>prehead)
    {
        thm=abs(head-max)+abs(max-0);
        for(i=0;i<q_size;i++)
        {
            if(array[i]>head)
            {
                thm+=abs(0-array[i-1]);
                break;
            }
        }
    }
    else
    {
        thm=abs(head-0)+abs(max-0);
        for(i=q_size-1;i>=0;i--)
        {
            if(array[i]<head)
            {
                thm+=abs(max-array[i+1]);
                break;
            }
        }
    }

    printf("\nTotal head movement : %d\n",thm);
}


int main(){
int ans,max,n,head,queue[20];

printf("Enter the max range of disk\n");
scanf("%d",&max);
max=max-1;
printf("Enter the size of queue request\n");
scanf("%d",&n);
printf("Enter the queue of disk positions to be read\n");
    for(int i=0;i<n;i++)
    scanf("%d",&queue[i]);
printf("Enter initial head position\n");
scanf("%d",&head);

do{
    printf("----------------\n");
    printf("1\t FCFS\n");
    printf("2\t SCAN\n");
    printf("3\t CSCAN\n");
    printf("4\t EXIT\n");
    printf("----------------\n");
    scanf("%d",&ans);

    switch (ans)
    {
     case 1: fcfs(max,n,head,queue);
        break;

     case 2: scan(max,n,head,queue);
        break;

     case 3: cscan(max,n,head,queue);
        break;

    case 4: exit(0);
        break;

    default:
        break;
    }
}while(1);
return 0;}




