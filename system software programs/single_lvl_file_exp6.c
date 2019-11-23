#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void create();
void delete();
void display();
void search();
struct file1
{
	int fcount;
	char dname[20],fname[20][20];
}dir;
int main()
{
	int ch;
	dir.fcount=0;
	printf("\nEnter the directory name:");
	scanf("%s",dir.dname);
	do{
		printf("\nMENU");
		printf("\n1.Create File");
		printf("\n2.Delete File");
		printf("\n3.Display File");
		printf("\n4.Search File");
		printf("\n0:EXIT");
		printf("\nEnter your choice:");
		scanf("%d",&ch);
		switch(ch)
		{
			case 0: exit(1);
			case 1: create();  break;
			case 2:	delete();  break;
			case 3: display(); break;
			case 4: search();  break;
			default: printf("\nInvalid Choice!");
		}
	}while(ch!=0);
	return 0;
}
void create()
{
	int i,flag=0;
	char name[20];
	printf("\nEnter file name:");
	scanf("%s",name);
	for(i=0;i<dir.fcount;i++)
	{
		if(strcmp(name,dir.fname[i])==0)
			flag=1;
	}
	if(flag==0)
	{
		strcpy(dir.fname[dir.fcount],name);
		dir.fcount+=1;
		printf("\nFile created succssfully");
	}
	else
	{
		printf("\nFile already exists!!\n");
	}
}
void delete()
{
	int i,flag=0;
	char name[20];
	printf("\nEnter the file name to be deleted:");
	scanf("%s",name);
	for(i=0;i<dir.fcount;i++)
	{
		if(strcmp(name,dir.fname[i])==0)
			{ strcpy(dir.fname[i],dir.fname[dir.fcount-1]);
			  dir.fcount-=1;
			  flag=1;
			}
	}
	if(flag==0)
		printf("\nFile does not exists!!");
	else
		printf("\nFile deleted successfully");
}	
void display()
{
	printf("\n\tDirectory name:%s",dir.dname);
	printf("\n\tFiles");
	printf("\n\t*****"); 
	for(int i=0;i<dir.fcount;i++)
	{
		printf("\n\t %s",dir.fname[i]);	
	}
}
void search()
{
	char name[10];
	int flag=0;
	printf("\nEnter file name to be searched:");
	scanf("%s",name);
	for(int i=0;i<dir.fcount;i++)
	{
		if(strcmp(name,dir.fname[i])==0)
		     {
			printf("\nFile Found");
			flag=1; break;
		     }	
	}
	if(flag==0)
		printf("\nFile Not found!!");
}


