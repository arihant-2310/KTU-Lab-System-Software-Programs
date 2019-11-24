//Program to simulate Banker's Safety algorithm for deadlock avoidance
#include<stdio.h>
int main()
{
	int max[10][10],allocation[10][10],need[10][10],available[10],work[10],finish[10];
	int m,n,i,j,flag=1,count=0,done=1;
	printf("\nEnter the number of resources:");
	scanf("%d",&m);
	printf("\nEnter the number of processes");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{ finish[i]=-1; }
	printf("\nEnter the resources allocated\n");
	for(i=0;i<m;i++)
	{
		printf("   r%d  ",i+1);		
	}
	for(i=0;i<n;i++)
	{
		printf("\n P%d\t",i);
		for(j=0;j<m;j++)
		{
			
			scanf("%d",&allocation[i][j]);
		}
	}
	printf("\nEnter the maximum need\n");
	for(i=0;i<m;i++)
	{
		printf("   r[%d]  ",i+1);		
	}
	for(i=0;i<n;i++)
	{	printf("\n P%d\t",i);
		for(j=0;j<m;j++)
		{
			
			scanf("%d",&max[i][j]);
		}
	}
	printf("\nEnter the available resources:\n");
	for(i=0;i<m;i++)
	{
		printf("  r%d",i+1);
		
	}
	printf("\n");
	for(i=0;i<m;i++)
	{
		scanf("   %d",&available[i]);	
		
	}
	for(i=0;i<m;i++)
	{
		work[i]=available[i];
	}
	
	
	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
		{
			need[i][j]= max[i][j]- allocation[i][j];
		}
	}
	printf("\nThe need matrix is:");
	for(i=0;i<n;i++)
	{
		printf("\n");
		for(j=0;j<m;j++)
		{
			printf("%d\t",need[i][j]);
		}
	}
	
	printf("\nThe sequence is:");
	while(count<n) //loop till number of processes
	{
		for(i=0;i<n;i++)
		{   	if(finish[i]==-1) //if the process need is not satisfied
					{
						flag=1;
						for(int k=0;k<m;k++) 
						{
							if(need[i][k]>work[k]) //check if need is not greater than available resources
								{flag= 0; break;}
						}
						if(flag==1 ) //if need is less than available resources
						{	for(j=0;j<m;j++)
							{
								work[j]= work[j]+allocation[i][j]; 
								
							} 
							finish[i]=0; //process need is satisfied
							printf("%d  ",i); //print the sequence in which process executes
						}
					}
			
		}count ++;
	}
	for(i=0;i<n;i++)
	{
		if(finish[i]==-1) //check if all process request is satisfied
			done=0;
	}
	if(done=0)
		printf("\nThe system is not is safe state!!");
	else
		printf("\nThe system is in safe state");
	return 0;
}
