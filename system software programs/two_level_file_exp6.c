#include<stdio.h>
#include<string.h>
#include<stdlib.h>
void create_dir();
void create_file();
void delete();
void display();
void search();
struct file2
{
	int fcount;
	char dname[20],fname[20][20];
}d[10];
int dcount=0;
int main()
{
	int ch;
	do{
		printf("\nMENU");
		printf("\n1.Create directory");
		printf("\n2.Create File");
		printf("\n3.Delete File");
		printf("\n4.Display File");
		printf("\n5.Search File");
		printf("\n0:EXIT");
		printf("\nEnter your choice:");
		scanf("%d",&ch);
		switch(ch)
		{
			case 0: exit(1);
			case 1: create_dir();  break;
			case 2: create_file(); break;
			case 3: delete();      break;
			case 4: display();     break;
			case 5: search();      break;
			default: printf("\nInvalid Choice!");
		}
	}while(ch!=0);
	return 0;
}
void create_dir()
{	char name[20];
	int flag=0;
	printf("\nEnter the directory name:");
	scanf("%s",name);
	for(int i=0;i<dcount;i++)
	{
		if(strcmp(d[i].dname,name)==0)
		{ printf("\nDirectory already exists!!");
			flag=1; break;
		}
	}
	if(flag==0)
	{
			strcpy(d[dcount++].dname,name);
			printf("\nDirectory Created successfully!!");
			printf("\nNo. Of Directories:%d",dcount);
	}
}
void create_file()
{	int i,flag=0,done=0,dnum=0;
	char dnm[20],fnm[20];
	printf("\nEnter the directory name:");
	scanf("%s",dnm);
	for(i=0;i<dcount;i++)
	{
		if(strcmp(d[i].dname,dnm)==0)
		{ printf("\nDirectory Okay");
			flag=1; dnum=i;break;
		}
	}
	if(flag==1)
	{
		printf("\nEnter the file name:");
		scanf("%s",fnm);
		for(i=0;i<d[dnum].fcount;i++)
		{
			if(strcmp(d[dnum].fname[i],fnm)==0)
			{
				printf("\nFile already Exists!!"); done=1; break;		
			}
		}
		if(done==0)
		{
			strcpy(d[dnum].fname[d[dnum].fcount++],fnm);
			printf("\nFile Created Successfully.\n");
		}

	}
}
void delete()
{
	char dnm[20],fnm[20];
	int i,dnum=0,flag=0,done=0;
	printf("\nEnter the directory name:");
	scanf("%s",dnm);
	for(i=0;i<dcount;i++)
	{
		if(strcmp(d[i].dname,dnm)==0)
		{ printf("\nDirectory Okay");
			flag=1; dnum=i;break;
		}
	}
	if(flag==1)
	{
		printf("\nEnter the file name to be deleted:");
		scanf("%s",fnm);
		for(i=0;i<d[dnum].fcount;i++)
		{
			if(strcmp(d[dnum].fname[i],fnm)==0)
			{
				printf("\nFile Exists"); done=1; break;		
			}
		}
		if(done==1)
		{
			strcpy(d[dnum].fname[d[dnum].fcount--],d[dnum].fname[d[dnum].fcount-1]);
			printf("\nFile Deleted Successfully.\n");
		}
		else
			printf("\nFile does not exists!!");
	}
	else
		printf("\nDirectory Does Not Exists!!");
}
void display()
{	for(int i=0;i<dcount;i++)
	{
		printf("\n\tDirectory name:%s",d[i].dname);
		printf("\n\tFiles");
		printf("\n\t*****"); 
		for(int j=0;j<d[i].fcount;j++)
		{
			printf("\n\t %s",d[i].fname[j]);	
		}
	}
}
void search()
{
	char dnm[20],fnm[20];
	int i,dnum=0,flag=0,done=0;
	printf("\nEnter the directory name:");
	scanf("%s",dnm);
	for(i=0;i<dcount;i++)
	{
		if(strcmp(d[i].dname,dnm)==0)
		{ printf("\nDirectory Okay");
			flag=1; dnum=i;break;
		}
	}
	if(flag==1)
	{
		printf("\nEnter the file name to be searched:");
		scanf("%s",fnm);
		for(i=0;i<d[dnum].fcount;i++)
		{
			if(strcmp(d[dnum].fname[i],fnm)==0)
			{
				printf("\nFile Found"); done=1; break;		
			}
		}
		if(done==0)
		{
			printf("\nFile Not Found!!.\n");
		}
	}
	else
		printf("\nDirectory Does Not Exists!!");
}






