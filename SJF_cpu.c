#include <stdio.h>
struct fcfs{
    int pid;
    int atime;
    int btime;
    int ctime;
    int ttime;
    int wtime;
    int doneflag;
}p[10],tempr;
void main()
{
  int i,j,n,current_time=0,temp,flag,count=0;
  float total_tat=0,total_wt=0;
  int id1[n],ctime[n];
  printf("Enter the number of process");
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        printf("Enter the arrival time");
        scanf("%d",&p[i].atime);
        printf("Enter the burst time");
        scanf("%d",&p[i].btime);
        p[i].pid=i+1;
        p[i].doneflag=0;
    }
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-i-1;j++){
            if(p[j].btime>p[j+1].btime){
                tempr=p[j];
                p[j]=p[j+1];
                p[j+1]=tempr;
            }
        }
    }
    printf("Process AT BT CT TAT WT\n");
    while(count<n)
       {
        flag=0;
       for(i=0;i<n;i++)
         {   
         if(current_time>=p[i].atime&&p[i].doneflag==0)
              {
                flag=1;
                break;
              }
         }
        if(flag==0)
          {
            current_time++;
          }
        if(flag==1)
          {
            current_time=current_time+p[i].btime;
            p[i].ctime=current_time;
            p[i].ttime=p[i].ctime-p[i].atime;
            p[i].wtime=p[i].ttime-p[i].btime;
            printf("%d   %d  %d  %d  %d  %d \n ",p[i].pid,p[i].atime,p[i].btime,p[i].ctime,p[i].ttime,p[i].wtime);
            id1[count]=p[i].pid;
            ctime[count]=current_time;
            p[i].doneflag=1;
            count++;
          }
       }
    for(i=0;i<n;i++)
      {
     total_tat=total_tat+p[i].ttime;
     total_wt=total_wt+p[i].wtime;
      }
  printf("Average TAT is %.2f\n",total_tat/n);
  printf("Average WT is %.2f",total_wt/n);

  printf("Gantt Chart\n");
  for(i=0;i<n;i++)
  {
   printf("|");
   printf("\t%d\t",id1[i]);
  }
  printf("\n0\t \t");
  for(i=0;i<n;i++){
    printf("%d\t \t",ctime[i]);
  }
}