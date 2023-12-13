#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void main(){
    int nf=0,ch,flag;
    char dname[10],fname[10][10],name[10];
    printf("Enter the directory name : ");
    scanf("%s",&dname);
    while(1){
        printf("1 For insert 2 for display 3 for exit \n");
        scanf("%d",&ch);
        if(ch==1){
            printf("Enter the name of file : ");
            scanf("%s",&name);
            flag=0;
            for(int i=0;i<=nf;i++){
                if(strcmp(fname[i],name)==0){
                    printf("\n File already exist !!!!\n");
                    flag=1;
                    break;
                }
            }
            if(flag==0){
                strcpy(fname[nf++],name);
            }
        }
        else if(ch==2){
            printf("Contents of directory %s \n",dname);
            for(int i=0;i<nf;i++){
                printf("|| %s ",fname[i]);
            }printf("\n");
        }
        else{
            break;
        }
    }
}
