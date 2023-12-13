#include<stdio.h>
#include<stdlib.h>
#include<string.h>


FILE *fp1,*fp2,*fp3,*fp4,*fp5;
int o=-1,operand,locctr,start,s=-1,flag,len,i,size;
char label[10],opcode[10],t1[10],t2[10],t3[10],operand1[10];

struct SYMTAB{
 char label[10];
 int addr;
 }ST[30];

struct OPTAB{
 char opcode[10];
 char hexcode[10];
 }OT[30];
 
 
void read_OPTAB(){
 while(1)
 {
  o++;
  fscanf(fp2,"%s%s",OT[o].opcode,OT[o].hexcode);
  if(getc(fp2)==EOF)
   break;
 }
}


void read_Line()
{
 strcpy(t1,"");
 strcpy(t2,"");
 strcpy(t3,"");
 fscanf(fp1,"%s",t1);
 if(fgetc(fp1)!='\n')
 {
  fscanf(fp1,"%s",t2);
   if(fgetc(fp1)!='\n')
   {
    fscanf(fp1,"%s",t3);
   }
 }
 
 if(strcmp(t1,"")!=0 && strcmp(t2,"")!=0 && strcmp(t3,"")!=0)
 {
  strcpy(label,t1);
  strcpy(opcode,t2);
  strcpy(operand1,t3);
  
 }
 if(strcmp(t1,"")!=0 && strcmp(t2,"")!=0 && strcmp(t3,"")==0)
 {
  strcpy(label,"");
  strcpy(opcode,t1);
  strcpy(operand1,t2);
  
 }
 if(strcmp(t1,"")!=0 && strcmp(t2,"")==0 && strcmp(t3,"")==0)
 {
  strcpy(label,"");
  strcpy(opcode,t1);
  strcpy(operand1,"");
  
 }
}


void main(){
 fp1=fopen("input.txt","r");
 fp2=fopen("optab.txt","r");
 fp3=fopen("intermediate.txt","w");
 fp4=fopen("symtab.txt","w");
 fp5=fopen("lenght.txt","w");
 
 
 read_OPTAB();
 
 fscanf(fp1,"%s%s%x",label,opcode,&operand);
 if(strcmp(opcode,"START")==0)
 {
  start=operand;
  locctr=start;
  fprintf(fp3,"\t%s\t%s\t%x\n",label,opcode,operand);
  read_Line();
 }
 else
  locctr=0;
  
while(strcmp(opcode,"END")!=0)
{
 fprintf(fp3,"\t%x\t%s\t%s\t%s\n",locctr,label,opcode,operand1);
 if(strcmp(label,"")!=0)
 {
  for(i=0;i<=s;i++)
  {
   if(strcmp(label,ST[i].label)==0)
   {
    printf("Error");
    exit(0);
   }
   }
   s++;
   strcpy(ST[s].label,label);
   ST[s].addr=locctr;
  }
  
  flag=0;
  
  for(i=0;i<=o;i++)
  {
   if(strcmp(opcode,OT[i].opcode)==0)
   {
    locctr=locctr+3;
    size=size+3;//size for object code construction
    flag=1;
    break;
   }
  }
  
 if(flag==0)
 {
  if(strcmp(opcode,"WORD")==0)
   {
    locctr=locctr+3;
    size=size+3;
   }
 else  if(strcmp(opcode,"RESW")==0)
   {
    locctr=locctr+(0x3*(atoi(operand1)));

   }
  else if(strcmp(opcode,"RESB")==0)
   {
    locctr=locctr+(atoi(operand1));

   }
    if(strcmp(opcode,"BYTE")==0)
   {
    
     len=strlen(operand1);
     if(operand1[0]=='c' || operand1[0]=='C')
    {
     len=len-3;
     locctr=locctr+len;
     size=size+len;
    }
    else
     {
      len=(len-3)/2;
      locctr=locctr+len;
      size=size+len;
      }
     
    //size=size+3;
   }
  
   
   }
   read_Line();
}
  
  
  fprintf(fp3,"\t%s\t%s\t%s\n",label,opcode,operand1);
  
  for(i=0;i<=s;i++)
  {
   fprintf(fp4,"%s\t%x",ST[i].label,ST[i].addr);
  if(i!=s)
   fprintf(fp4,"\n");
  }
  
  fprintf(fp5,"%x\n%x",locctr-start,size);
  fclose(fp1);
  fclose(fp2);
  fclose(fp3);
  fclose(fp4);
  fclose(fp5);
  
  }
  
