#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct symbol{
	char name[20];
	int value;
}symbol[10];
void create(int );
void display();
void insert(char []);
int modify(char[]);
int search(char []);
int main()
{
	int choice,n,value,result;
	char name[20];
	strcpy(symbol[0].name,"NULL");
	symbol[0].value= -1;
	while(1)
	{
		printf("\n1.CREATE");
		printf("\n2.INSERT");		
		printf("\n3.MODIFY");
		printf("\n4.SEARCH");
		printf("\n5.DISPLAY");
		printf("\n0.EXIT");
		printf("\nEnter Your Choice:");
		scanf("%d",&choice);
		switch(choice)
		{


			case 0: exit(0);
			case 1: printf("\nEnter the number of entries:");
				scanf("%d",&n);
				create(n);
				break;
			case 2: printf("\nEnter the symbol name to be inserted:");
				scanf("%s",name);
				insert(name);
				break;	
			case 3: printf("\nEnter the symbol name:");
				scanf("%s",name);
				result = modify(name);
				if(result== -1)
					printf("\nSymbol name doesn't Exists!!");
				break;
			case 4: printf("\nEnter the symbol name to be searched:");
				scanf("%s",name);
				result = search(name);
				if(result== -1)
					printf("\n\t\tNot Found!!");
				else
					printf("\n\t\tFound!!");
				break;
			case 5: display(); break;
			
		}
	}	
	return 0;
}
void create(int n)
{
	int i=0,result;
	char new_name[20];
	while(i<n)
	{
		printf("\nEnter Symbol NAme[%d]:",i+1);
		scanf("%s",new_name);
		result= search(new_name);		
		if(result != 0)
		{
			printf("\nEnter Symbol Value[%d]:",i+1);
			scanf("%d",&symbol[i].value);
			strcpy(symbol[i].name,new_name); i++;
		}	
		strcpy(symbol[i+1].name,"NULL");
		symbol[i+1].value= -1;
	}
	
	
}
void display()
{	int i=0;
	printf("\n***************");
	printf("\n|NAME|\t|VALUE|");
	printf("\n***************");
	while(strcmp(symbol[i].name,"NULL")!=0)
	{
		printf("\n%s\t%d",symbol[i].name,symbol[i].value);	
		i++;
	}
	printf("\n\n");
}
void insert(char new_name[])
{
	int i=0,flag=0,new_value;
	while(strcmp(symbol[i].name,"NULL")!=0)
	{
		if(strcmp(symbol[i].name,new_name)==0)
		{	printf("\nError!....Duplicate");
			return;
		}
		i++;
	}
	printf("\nEnter the value to be inserted:");
	scanf("%d",&new_value);
	strcpy(symbol[i].name,new_name);
	symbol[i].value= new_value;
	strcpy(symbol[i+1].name,"NULL");
	symbol[i+1].value=0;
	printf("\nInserted ......");
	
}
int modify(char name[])
{
	int i=0,new_value;
	
	while(strcmp(symbol[i].name,"NULL")!=0)
	{
		if(strcmp(symbol[i].name,name)==0)
		{	
			printf("\nEnter the new value:");
			scanf("%d",&new_value);
			symbol[i].value= new_value;
			return 0;
		}
		i++;
	}
	return -1;
}
int search(char search_name[])
{int i=0;
	while(strcmp(symbol[i].name,"NULL")!=0)
	{
		if(strcmp(symbol[i].name,search_name)==0)
		{	
			return 0;
		}
		i++;
	}
	return -1;
	
}









