#include<stdio.h>
int main(){
    int i,n,a[100],f=0;
    printf("Enter number of elements : ");
    scanf("%d",&n);
    printf("Enter elements :\n");
    for(i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    int max=a[0];
    int b;
    for(i=0;i<n;i++){
            if(a[i]>max){
            max=a[i];
             b=i;
            }
    }
    if (b==n-1) b--;
    else b++;
    int max1=a[b];
    for(i=0;i<n;i++){
            if(a[i]>max1 && a[i]<max){
            max1=a[i];
            }
    }
    printf("Second largest element is : %d",max1);
    return 0;
}