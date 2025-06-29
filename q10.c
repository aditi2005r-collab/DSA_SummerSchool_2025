#include <stdio.h>
int main() {
    int n=5;
    int arr[]={2,9,7,3,6};
    void sort(int arr[], int n){
        for(int j=0; j<n-1; j++){
            int min_idx = j;
            for(int i=j+1; i<n; i++){  
                if(arr[i] < arr[min_idx]){
                    min_idx = i;
                }
            }
           
            if(min_idx != j){
                int temp = arr[j];
                arr[j] = arr[min_idx];
                arr[min_idx] = temp;
            }
        }
        printf("Sorted array: ");
        for(int i=0;i<n;i++){
            printf("%d ",arr[i]);
        }
    }   
    sort(arr,n);
    return 0;
}
