#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct directory{
    char dname[50];
    char fname[50][50];
    int fno;
}dir[10];
void main(){
    int dno=0;
    char dirname[50],filename[50];
    while (1)
    {   int ch;
        printf("1 For Directory Creation 2 to insert file 3 to display =");
        scanf("%d",&ch);
        if(ch==1){
            dir[dno].fno=0;
            printf("Enter the name of directory =");
            scanf("%s",dirname);
            for(int j=0;j<=dno;j++){
                if(strcmp(dir[j].dname,dirname)==0){
                    printf("Directory Name already exists \n");
                    break;
                }
                if(j==dno){
                    //dno++;
                    strcpy(dir[dno++].dname,dirname);
                    printf("Directory Created\n");
                    break;
                }
            }
        }
        else if(ch==2){
            printf("Enter the name of directory to insert");
            scanf("%s",dirname);
            for(int j=0;j<=dno;j++){
                if(strcmp(dir[j].dname,dirname)==0){
                    printf("Enter the name of file");
                    scanf("%s",filename);
                    for(int m=0;m<=dir[j].fno;m++){
                        if(strcmp(dir[j].fname[m],filename)==0){
                            printf("\n FILE ALREADY EXISTS \n");
                            break;
                        }
                        if(m==dir[j].fno){
                            printf("\n FILE ALREADY INSERTED");
                            strcpy(dir[j].fname[dir[j].fno++],filename);
                            break;
                        }
                    }
                    break;
                }
                if(j==dno){
                    printf("Directory do not exist");
                    break;
                }
            }
        }
        else if(ch==3){
            printf("Enter the name of directory to display \n");
            scanf("%s",dirname);
            for(int j=0;j<=dno;j++){
                if(strcmp(dir[j].dname,dirname)==0){
                   for(int k=0;k<=dir[j].fno;k++){
                    printf("%s \t->\t",dir[j].fname[k]);
                   }
                   break;
                }
                if(j==dno){
                    printf("Directory do not exist for display \n");
                    break;
                }
            }
        }else{
            break;
        }
    }
}
