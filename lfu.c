
#include <stdio.h>
#include <stdlib.h>
void main(){
    int n,f,flag,pgfault=0,rs[20],m[20],i,j,arrival[20]={0},count[20],min;
    printf("Enter number of pages: ");
    scanf("%d",&n);
    printf("\nEnter reference string: ");
    for(i=0;i<n;i++){
        scanf("%d",&rs[i]);

    }
    printf("\nEnter number of frames: ");
    scanf("%d",&f);
    for(i=0;i<f;i++){
        m[i]=-1;
        count[i]=0;
    }
    for(i=0;i<n;i++){
        flag=0;
        for(j=0;j<f;j++){
            if(rs[i]==m[j]){
                flag=1;
                count[j]++;
                break;
            }
        }
        if (flag==0){
            if(i<f){
                m[i]=rs[i];
                count[i]=1;
                arrival[i]=i;
            }
            else{
                min=0;
                for(j=1;j<f;j++){
                    if(count[j]<count[min])
                        min=j;
                    if(count[j]==count[min]){
                        if(arrival[j]<arrival[min]){
                            min=j;
                        }
                    }

                }
                m[min]=rs[i];
                count[min]=1;
                arrival[min]=i;
            }

            pgfault++;
        }  
        printf("\n");
        for(j=0;j<f;j++){
            printf("%d   |   ",m[j]);
        }
        if(flag==0){
            printf("Page fault no. %d\n",pgfault);
        }
        if(flag==1){
            printf("Page Hit\n");
        }
    }
    printf("\nTotal Page faults: %d",pgfault);
}