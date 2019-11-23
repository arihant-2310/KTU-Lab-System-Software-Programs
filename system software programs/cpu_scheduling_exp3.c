#include<stdio.h>
#include<stdlib.h>

void turn_around_time(int n,int wait_time[], int burst_time[],int turn_time[])
{
	for(int i=0;i<n;i++)
	{
		turn_time[i]= wait_time[i]+burst_time[i];
	}
}
void waiting_time(int n,int wait_time[], int burst_time[])
{
	wait_time[0]= 0;
	for(int i=1; i<n;i++)
	{
		wait_time[i]= wait_time[i-1]+ burst_time[i-1];
	}	
}
void avg_wait_time(int n,int burst_time[])
{	float avg_wt=0,avg_tat=0;
	int wait_time[n],turn_time[n];
	waiting_time(n,wait_time,burst_time);
	turn_around_time(n,wait_time,burst_time,turn_time);
	for(int i=0;i<n;i++)
	{	//printf("\n %d",wait_time[i]);
		avg_wt= avg_wt+ wait_time[i];	
		avg_tat= avg_tat+turn_time[i];
	}
	printf("\nAverage waiting time:%.2f",avg_wt/n);
	printf("\nAverage turn around time:%.2f",avg_tat/n);
	
	
}
int main()
{
	int total_burst_time=0,t=0,wait_time_round_robin[10];float tat=0,burst_time_rr[10],flag=1;
	int choice,quantum,process[]={0,1,2,3},rem_burst_time[10];
	int i,n,j,temp,burst_time[10];
	printf("\nEnter no. of processes:");
	scanf("%d",&n);
	printf("\nEnter the burst time of the processes:");
	for(i=0;i<n;i++)
	{
		printf("\nProcess[%d]:",i);
		scanf("%d",&burst_time[i]);	
		burst_time_rr[i]=burst_time[i];
	}
	 
	do
	{
		printf("\nCPU SCHEDULING ALGORITHMS");
		printf("\n1.FCFS");
		printf("\n2.SJF");
		printf("\n3.RR");
		printf("\n4.Priority Scheduling");
		printf("\n0: Exit");
		printf("\nEnter your Choice:");
		scanf("%d",&choice);
		switch(choice)
		{
			case 0: exit(0);
			case 1: avg_wait_time(n,burst_time);
				break;
			case 2: for(i=0;i<n-1;i++)
				{
					for(j=0;j<n-1-i;j++)
					{
						if(burst_time[j]>burst_time[j+1])	
						{
							temp= burst_time[j];
							burst_time[j]= burst_time[j+1];
							burst_time[j+1]=temp; 
						}
						
					}
					
				}
				avg_wait_time(n,burst_time); 
				break;
			case 3: 
				printf("\nEnter The Quantum Value:");
				scanf("%d",&quantum);
				for(i=0;i<n;i++)
				{
					rem_burst_time[i]= burst_time[i];
					total_burst_time= total_burst_time+burst_time[i];
					printf("burst timeL:%d",burst_time[i]);
				}
				printf("\n%d",total_burst_time);
				do
				{printf("\n%d",t);
					for(i=0;i<n;i++)
					{
						if(rem_burst_time[i] > quantum)
						{
							t=t+quantum;
							rem_burst_time[i] -= quantum;
						}
						else
						{
							t += rem_burst_time[i];
							wait_time_round_robin[i] = t- burst_time_rr[i];
							rem_burst_time[i]=0;
						}
					}
				}while(t!=21);
			for(i=0;i<n;i++)
			{
				 tat= tat+wait_time_round_robin[i]+ burst_time[i];
			}
			printf("\nAvergage turn around time %.2f",tat/n);
				
			break;
			default: printf("\nWrong choice!!");
		}
		
		
	}while(choice != 0);
}
