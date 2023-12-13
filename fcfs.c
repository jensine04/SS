#include<stdio.h>
#include<stdlib.h>
struct fcfs{
    int pid;
    int atime;
    int btime;
    int ctime;
    int ttime;
    int wtime;
}p[10],temp;
void main(){
    int n,currenttime=0;
    float atat,awt,tat,wt;
    printf("---------FCFS------");
    printf("Enter the number of process");
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        printf("Enter the arrival time");
        scanf("%d",&p[i].atime);
        printf("Enter the burst time");
        scanf("%d",&p[i].btime);
        p[i].pid=i+1;
    }
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-i-1;j++){
            if(p[j].atime>p[j+1].atime){
                temp=p[j];
                p[j]=p[j+1];
                p[j+1]=temp;
            }
        }
    }
    for(int i=0;i<n;i++){
        while(p[i].atime>currenttime){
            currenttime++;
        }
        currenttime+=p[i].btime;
        p[i].ctime=currenttime;
        p[i].ttime=p[i].ctime-p[i].atime;
        p[i].wtime=p[i].ttime-p[i].btime;
        tat=tat+p[i].ttime;
        wt=wt+p[i].wtime;
    }
    for(int i=0;i<n;i++){
    printf("\n  %d \t %d \t %d \t %d \t %d \t %d \t  \n ",p[i].pid,p[i].atime,p[i].btime,p[i].ctime,p[i].ttime,p[i].wtime);
  } 
    printf("\n  TurnAroundTime %f \n  Waiting Time %f\n",tat,wt);
    printf("\n Average TurnAroundTime %f \n Average Waiting Time %f\n",tat/n,wt/n);

}