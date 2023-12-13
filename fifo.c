
#include <stdio.h>
#include <stdlib.h>
void main(){
    int n,f,flag,pgfault=0,rs[20],m[20],i,j,index=0;
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

    }
    for(i=0;i<n;i++){
        flag=0;
        for(j=0;j<f;j++){
            if(rs[i]==m[j]){
                flag=1;
                break;
            }
        }
        if (flag==0){
            pgfault++;
            m[index++]=rs[i];
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
        if(index==f)
            index=0;
    }
    printf("\nTotal Page faults: %d",pgfault);
}