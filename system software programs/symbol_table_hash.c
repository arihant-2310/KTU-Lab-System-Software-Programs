#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct symbol
{
char name[20];
int value;
}symbol[10];
int n1;
void clear(struct symbol symbol[])
{
int i;
for(i=0;i<10;i++)
{
strcpy(symbol[i].name,"NULL");
symbol[i].value=0;
}
}
void create(struct symbol symbol[],int n)
{
int i,value,hash,flag=0;
char name[20];
clear(symbol);
for(i=0;i<n;i++)
{
printf("\n enter the symbol and value:");
scanf("%s%d",name,&value);
hash=value%10;
if(strcmp(symbol[hash].name,"NULL")==0)
{
strcpy(symbol[hash].name,name);
symbol[hash].value=value;
}
else
{
hash=value%10+1;
while(strcmp(symbol[hash].name,"NULL")!=0&&hash<=10)
{
hash=hash+1;
if(hash>=9)
{
if(flag==1)
break;
hash=0;
flag=1;
}
}
if(strcmp(symbol[hash].name,"NULL")==0)
{
strcpy(symbol[hash].name,name);
symbol[hash].value=value;
}
else
{
printf("Can't Insert the value");
}

}
}
n1=n;
}
void insert(struct symbol symbol[],char *name,int value)
{
int i=0,flag=0,hash,flag1=0,k;
while(strcmp(symbol[i].name,"NULL")!=0)
{
if(strcmp(symbol[i].name,name)==0)
{
flag=1;
break;
}
i++;
}

if(flag==1)
printf("\n Cannot insert.");
else
{
hash=value%10;
if(strcmp(symbol[hash].name,"NULL")==0)
{
strcpy(symbol[hash].name,name);
symbol[hash].value=value;
}
else
{
hash=value%10+1;
while(strcmp(symbol[hash].name,"NULL")!=0&&hash<=10)
{
hash=hash+1;
if(hash>=9)
{
if(flag1==1)
break;
hash=0;
flag1=1;
}
}
if(strcmp(symbol[hash].name,"NULL")==0)
{
strcpy(symbol[hash].name,name);
symbol[hash].value=value;
}
else
{
printf("Can't Insert the value");
}
}
}
n1=n1+1;
}
int search(struct symbol symbol[],char *name)
{
int i=0;
while(strcmp(symbol[i].name,name)!=0 && i<10)
i++;
if(strcmp(symbol[i].name,name)==0)
{
printf("\n Symbol found");
printf("\nSymbol:%s \t value:%d",symbol[i].name,symbol[i].value);
return i;
}
else
return -1;
}
void modify(struct symbol symbol[],int loc,int value)
{
symbol[loc].value=value;
}
void display(struct symbol symbol[])
{
int i=0;
while(i<10)
{
printf("\nHash:%d \t Symbol:%s \t value:%d",i,symbol[i].name,symbol[i].value);
i=i+1;
}
}
int main()
{
int value,loc,ch,n;
char name[30];
while(1)
{
printf("\nMENU:\n1.Create\n2.Insert\n3.Modify\n4.Search\n5.Display\nAny other number to exit\nEnter your choice: ");
scanf("%d",&ch);
switch(ch)
{
case 1: printf("\nEnter the number of instances: ");
scanf("%d",&n);
if(n<=10)
create(symbol,n);
else
printf("\nArray index out of bound.");
break;
case 2: if(n1==10)
printf("cannot insert!! array full");
else
{
scanf("%s %d",name,&value);
insert(symbol,name,value);
}
break;
case 3: printf("enter the symbol to be modified: ");
scanf("%s",name);
loc=search(symbol,name);
if(loc!=-1)
{
printf("\n enter the value to be modified");
scanf("%d",&value);
modify(symbol,loc,value);
display(symbol);
}
else
printf("Symbol not found");
break;
case 4: printf("\n Enter the symbol to be searched");
scanf("%s",name);
loc=search(symbol,name);
if(loc==-1)
printf("\nSymbol not found");
break;
case 5: display(symbol);
break;
default: exit(0);
}
}
return 0;
}
