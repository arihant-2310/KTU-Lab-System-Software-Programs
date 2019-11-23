#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int position(char str[10],char oprnd[10])
{
	char temp[10];
	char s[10][10]={};
	int i,j,k,m;
	j=0;k=0;
	for(i=0;str[i]!='\0';i++)
	{
		if(str[i]==',')
		{
			j+=1; k=0;
		}
		else
		{
			s[j][k++]= str[i];
		}
	}
	for(j=0;j<10;j++)
	{
		strcpy(temp,s[j]);
		if(strcmp(temp,oprnd)==0)
		{	
			return j+1;
		}
	}

}
int main()
{
	int endp=0,i,j=0,pos,k=0,count=0;
	char label[10],opcode[10],operand[10],macroname[10]="",oprnd[10];
	char pos_notation[10]="?",op_mat[10][10]={};
	char lab[10],opc[10],opr[10],arg_name[10],temp_opr[10];

	FILE *ip,*def,*nam,*op,*arg;
	ip= fopen("input.txt","r");
	nam= fopen("namtab.txt","w");
	def= fopen("deftab.txt","w+"); 		
	arg= fopen("argtab.txt","w");
	op= fopen("output.txt","w"); 
	fscanf(ip,"%s\t%s\t%s",label,opcode,operand);
	while(strcmp(opcode,"END")!=0)
	{	
		if(strcmp(opcode,"MACRO")==0)
		{	endp+=1;
			strcpy(macroname,label);
			strcpy(oprnd,operand);
			fprintf(def,"%s\t%s\n",label,operand);
			fscanf(ip,"%s\t%s\t%s",label,opcode,operand);
			while(strcmp(opcode,"MEND")!=0)
			{	endp+=1;
				pos= position(oprnd,operand); 
				fprintf(def,"%s\t%s\t?%d\n",label,opcode,pos);
				fscanf(ip,"%s\t%s\t%s",label,opcode,operand);
				
			}
			fprintf(def,"%s\t%s\t%s\n",label,opcode,operand);
			fprintf(nam,"%s\t%d\t%d",macroname,1,endp+1);
			fscanf(ip,"%s\t%s\t%s",label,opcode,operand);
		}
		else if(strcmp(opcode,macroname)==0)
		{
			strcpy(temp_opr,operand);
			for(i=0;temp_opr[i]!='\0';i++)
			{
				if(temp_opr[i]==',')
				{
					j+=1; k=0; count++;
				}
				else
				{
					op_mat[j][k++]= temp_opr[i];
				}
			}
			for(i=0;i<=count;i++)
			{
				fprintf(arg,"%d\t%s\n",i+1,op_mat[i]);
			}
			fclose(arg);
			arg=fopen("argtab.txt","a+");
			fseek(def,SEEK_SET,0); fseek(arg,SEEK_SET,0);  
			fscanf(def,"%s\t%s\t%s",lab,opc,opr);
			fscanf(def,"%s\t%s\t%s",lab,opc,opr);
			while(strcmp(lab,"MEND")!=0)
			{	fscanf(arg,"%d\t%s",&j,arg_name);
				fprintf(op,"%s\t%s\t%s\n",lab,arg_name,opr);
				fscanf(def,"%s\t%s\t%s",lab,opc,opr);
			}
			fscanf(ip,"%s\t%s\t%s",label,opcode,operand);
			
		}
		else
		{
			fprintf(op,"%s\t%s\t%s\n",label,opcode,operand);
			fscanf(ip,"%s\t%s\t%s",label,opcode,operand);
		}
	}
	fprintf(op,"**\tEND\t**");
}
