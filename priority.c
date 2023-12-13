#include <stdio.h>
#include <string.h>

struct process {
    char name[20];
    int at, bt, pr, ct, wt, tat;
    int status;
} p[20], temp;

void main(){
   int n,flag;
   printf("ENTER THE NUMBER OF PROCESSES: ");
    scanf("%d", &n);
    
    for (int i = 0; i < n; i++) {
        printf("\nENTER DETAILS OF PROCESS %d\n", i + 1);
        printf("PROCESS NAME: ");
        scanf("%s", p[i].name);
        printf("ARRIVAL TIME: ");
        scanf("%d", &p[i].at);
        printf("BURST TIME: ");
        scanf("%d", &p[i].bt);
        printf("PRIORITY: ");
        scanf("%d", &p[i].pr);
        p[i].status = 0;
    }
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n-1-i; j++) {
            if (p[j].at > p[j+1].at) {
                temp = p[j];
                p[j] = p[j+1];
                p[j+1] = temp;
            }
        }
    }
    int currentT= 0, num= 0;
    struct process scheduled[20];
    
    while (num < n) {
        int high = -1;
        int index = -1;
        flag=0;
        for (int i = 0; i < n; i++) {
            if (p[i].at <= currentT && p[i].status==0) {
                if (high== -1 || p[i].pr < high) {
                    high = p[i].pr;
                    index = i; //flag here and modify else statement current++
                    flag=1;
                }
            }
        }
        if (index != -1) {
            p[index].ct = currentT+ p[index].bt;
            p[index].tat = p[index].ct - p[index].at;
            p[index].wt = p[index].tat - p[index].bt;
            currentT = p[index].ct;
            p[index].status = 1;
            scheduled[num++] = p[index];
        } 
        if (flag==0) {
            currentT++;
        }
    }
    printf("\nPROCESS NAME\tCOMPLETION TIME\tWAITING TIME\tTURNAROUND TIME\n\n");
    float totalWT = 0, totalTAT = 0;
    for (int i = 0; i < n; i++) {
        printf("%-15s\t%6d\t\t%6d\t\t%6d\n", p[i].name, p[i].ct, p[i].wt, p[i].tat);
        totalWT += p[i].wt;
        totalTAT += p[i].tat;
    }
    
    printf("\nAVERAGE WAITING TIME: %.2f", totalWT / n);
    printf("\nAVERAGE TURNAROUND TIME: %.2f\n", totalTAT / n);
    
    printf("\nGANTT CHART\n");
    printf("-------------------------------------------------------------\n");
    printf("|");
    for (int i = 0; i < num; i++) {
        printf(" %-10s |", scheduled[i].name);
    }
    printf("\n-------------------------------------------------------------\n");
    printf("0");
    for (int i = 0; i < num; i++) {
        printf("          %2d", scheduled[i].ct);
    }
 }
         
   
