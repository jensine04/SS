#include<stdio.h>
struct rr{
    int pid;
    int atime;
    int btime;
    int ctime;
    int tat;
    int wtime;  
}p[10],temp;
int ready[50];
int front=-1;
int rear=-1;
void insert(int n){
    if (front==-1)
        front++;
    rear++;
    ready[rear]=n;
}
int delete(){
    int n;
    n=ready[front];
    front++;
    return n;
}
void main(){
    int n,i=0,ts,rt[10],time=0,flag=0,k,j;
    int exist[20]={0};
    float ttat=0,twt=0;
    printf("Enter the number of process: ");
    scanf("%d",&n);
    printf("Enter the time slice process: ");
    scanf("%d",&ts);
    for( j=0;j<n;j++){
        p[j].pid=j;
        printf("Enter the arival time of P%d",j);
        scanf("%d",&p[j].atime);
        printf("Enter the burst time of P%d",j);
        scanf("%d",&p[j].btime);
        rt[j]=p[j].btime;
    } 
    for( k=0;k<n-1;k++){
        for(int j=0;j<n-i-1;j++){
            if(p[j].atime>p[j+1].atime){
                temp=p[j];
                p[j]=p[j+1];
                p[j+1]=temp;
            }
        }
    }   
    if (p[0].atime!=0) {
        time=p[0].atime;
    }  
    insert(0); 
    exist[0]=1;
    while(front<=rear){  
    flag=0;
    i=delete();
        if(rt[i]<=ts && rt[i]>0){  //no need to check arrival time always, only starting 1st process
            time=time+rt[i];
            rt[i]=0;
            flag=1;
        }else if(rt[i]>0){
            rt[i]=rt[i]-ts;
            time=time+ts;
        }
        for(j=0;j<n;j++){
            if(exist[j]==0 && p[j].atime<=time){
                    insert(j);
                    exist[j]=1;
            }
        }
        if(flag==0){
            insert(i);
        }
        if(rt[i]==0 && flag==1){
            p[i].ctime=time;
            p[i].tat=time-p[i].atime;
            ttat=ttat+p[i].tat;
            p[i].wtime=p[i].tat-p[i].btime;
            twt=twt+p[i].wtime;
            }
    }
    printf("\n --------------------Table is ---------------------\n ");
  printf("\n pid \t atime \t Btime \t ctime \t tat \t wating \t \n");
  for(int i=0;i<n;i++){
    printf("\n  %d \t %d \t %d \t %d \t %d \t %d \t  \n ",p[i].pid,p[i].atime,p[i].btime,p[i].ctime,p[i].tat,p[i].wtime);
  } 
  printf("\n  TurnAroundTime %f \n  Waiting Time %f\n",ttat,twt);
    printf("\n Average TurnAroundTime %f \n Average Waiting Time %f\n",ttat/n,twt/n);
}