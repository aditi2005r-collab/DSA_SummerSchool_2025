#include <stdio.h>
int main()
{
    printf("array: ");
    int n=5;
    int arr[]={5,4,7,8,0};
    for(int i=0;i<n;i++){
        printf("%d",arr[i]);
       
    }
    
 printf("\n");
void bubble(int arr[], int n){
    if (n == 1) {
        return;
    }
for(int j=0;j<n-1;j++){
    
        if(arr[j]>arr[j+1]){
        int temp=arr[j];
        arr[j]=arr[j+1];
        arr[j+1]=temp;
        }
    }
    bubble(arr,n-1);
}
bubble(arr,n);
 for(int i=0;i<n;i++){
        printf("%d",arr[i]);
    }
return 0;
    
}
