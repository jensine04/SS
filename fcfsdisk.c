//fabs is for absolute value of float and abs is for int
#include <stdio.h>
#include <stdlib.h>
void main(){
    int a[10],totalhead=0,i,initial,n;
    printf("Enter number of requests: ");
    scanf("%d",&n);
    printf("\nEnter requests: ");
    for(i=0;i<n;i++){
        scanf("%d",&a[i]);

    }
    printf("\nEnter intial head position: ");
    scanf("%d",&initial);
    for(i=0;i<n;i++){
        totalhead+=abs(initial-a[i]);
        initial=a[i];

    }
    printf("\n");
    for(i=0;i<n;i++){
        printf("%d",a[i]);
        if(i!=n-1)
            printf("=>");
    }
    printf("\nTotal head movement: %d",totalhead);
}