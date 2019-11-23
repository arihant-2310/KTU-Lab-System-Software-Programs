#include<stdio.h>
int top=1;
int main()
{
	int max[10][10],allocation[10][10],need[10][10],available[10],work[10],finish[10];
	int m,n,i,j,flag=0,count=0,request[10],done=0;
	printf("\nEnter the number of resources:");
	scanf("%d",&m);
	printf("\nEnter the number of processes");
	scanf("%d",&n);
	printf("\nEnter the resources allocated\n");
	for(i=0;i<m;i++)
	{
		printf("   r[%d]  ",i+1);		
	}
	for(i=0;i<n;i++)
	{ finish[i]=0; }
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
		printf(" r%d",i+1);
		
	}
	printf("\n");
	for(i=0;i<m;i++)
	{
		scanf("%d",&available[i]);	
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
	

	while(count<n)
		{
			for(i=0;i<n;i++)
			{
				for(j=0;j<m;j++)
				{	
					if((need[i][j]<= work[j]) && finish[i]==0 )
					{
						request[j]= 1;
					}
					else
						request[j]=0;
				}	
				for(int p=0;p<m;p++)
				{
					if(request[p]==1)
						flag=1;
					else
						 { flag=0; break;}
				}		
					if((flag==1) && (finish[i]==0))
					{for(int k=0;k<m;k++)
						{
							work[k]= work[k]+allocation[i][k];
							finish[i]=count+1; 
							
						} count++;
					}
				
				
			}
			
		
		}
	printf("\n");
	for(i=0;i<n;i++)
	{
		if(finish[i]==0)
			{
			printf("\nNot is safe state!!"); break;
			}
		else
			printf("\t%d",finish[i]);
	}

	
	return 0;
}


