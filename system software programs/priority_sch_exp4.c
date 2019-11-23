#include<stdio.h>
int main()
{
	int n,i,j,bt[20],pr[20],wt[20],p[20],tat[i],temp,pos;
	float avg_tat=0,avg_wt=0;
	printf("\nEnter the number of processes:");
	scanf("%d",&n);
	printf("\nEnter the burst time & priority ");
	for(i=0;i<n;i++)
	{
		printf("\np%d,\tburst time:",i);
		scanf("%d",&bt[i]);
		printf("\tpriority:");
		scanf("%d",&pr[i]);
		p[i]=i;
	}
	for(i=0;i<n;i++)
	{
		pos=i;
		for(j=i+1;j<n;j++)
		{
			if(pr[j]<pr[pos])
			{
				pos=j;
			}
		}
		temp=pr[i];
		pr[i]=pr[pos];
		pr[pos]=temp;
		
		temp=bt[i];
		bt[i]=bt[pos];
		bt[pos]=temp;
		
		temp=p[i];
		p[i]=p[pos];
		p[pos]=temp;
		
	}
	
	for(i=0;i<n;i++)
	{		
			if(i==0)
			{	
			wt[i]=0;
			tat[i]=wt[i]+bt[i];
			printf("\nprocess:%d\t waiting time:%d\t turn around time:%d",p[i],wt[i],tat[i]);
			}
			else
			{
			wt[i]= bt[i-1]+wt[i-1];
			tat[i]=bt[i]+wt[i];
			printf("\nprocess:%d\t waiting time:%d\t turn around time:%d",p[i],wt[i],tat[i]);
			}
			avg_tat+=tat[i];
			avg_wt+=wt[i];
	}
	printf("\nAverage Waiting Time \t Average Turn Around Time");
	printf("\n\t%.2f \t\t\t %.2f\n",avg_wt/4,avg_tat/4);

}
