#include <stdio.h>

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int n;

  
    scanf("%d", &n);

    int arr[n];

  
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int key = arr[n - 1];  
    int i = n - 2;

 
    while (i >= 0 && arr[i] > key) {
        arr[i + 1] = arr[i]; 
        printArray(arr, n);
        i--;
    }

    arr[i + 1] = key; 
    printArray(arr, n);  

    return 0;
}
