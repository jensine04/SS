//bubble sort 1st loop i<n or n-1
//last cylinder not needed for total head?
#include <stdio.h>
#include <stdlib.h>
void main(){
    int a[10],totalhead=0,i,j,initial,n,size,temp,mode,index;
    printf("Enter number of requests: ");
    scanf("%d",&n);
    printf("\nEnter requests: ");
    for(i=0;i<n;i++){
        scanf("%d",&a[i]);

    }
    printf("\nEnter intial head position: ");
    scanf("%d",&initial);
    printf("\nEnter total disk size: ");
    scanf("%d",&size);

    for(i=0;i<n-1;i++){
        for(j=0;j<n-i-1;j++){
            if(a[j]>a[j+1]){
                temp=a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
            }
        }
    }

    printf("\n1. Right\n2.Left\nEnter mode: ");
    scanf("%d",&mode);
    for(i=0;i<n;i++){
        if(a[i]>initial){
            index=i;
            break;
        }
    }
    // printf("\n");
    // for(i=0;i<n;i++){
    //     printf("%d ",a[i]);
    // }
    printf("\nSeek Sequence\n");
    if (mode==1){
        for(i=index;i<n;i++){
            printf("%d -> ",a[i]);
            totalhead+=abs(a[i]-initial);
            initial=a[i];        
        }
        totalhead+=abs(size-initial);
        initial=size;
        for(i=index-1;i>=0;i--){
            printf("%d",a[i]);
            totalhead+=abs(a[i]-initial);
            initial=a[i];
            if(i!=0)
                printf(" -> ");
        }
        //totalhead+=abs(initial-0);
    }

    if (mode==2){
        for(i=index-1;i>=0;i--){
            printf("%d -> ",a[i]);
            totalhead+=abs(a[i]-initial);
            initial=a[i];        
        }
        totalhead+=abs(initial-0);
        initial=0;
        for(i=index;i<n;i++){
            printf("%d",a[i]);
            totalhead+=abs(a[i]-initial);
            initial=a[i];
            if(i!=n)
                printf(" -> ");
        }
        //totalhead+=abs(size-initial);
    }
    printf("\nTotal head movement: %d",totalhead);
}