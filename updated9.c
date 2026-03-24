#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void SelectionSort(int arr[],int n){
    for(int i=0;i<n-1;++i){
        int minIndex=i;
        for(int j=i+1;j<n;++j){
            if(arr[j]<arr[minIndex]){
                minIndex=j;
            }
        }
int temp = arr[minIndex];
arr[minIndex]=arr[i];
arr[i]=temp;       
    }
}
void generaterandomnumbers(int arr[],int n){
    srand(time(0));
    for(int i=0;i<n;i++){
        arr[i]=rand()%10000;
    }
}
int main(){
    int n;
    printf("Enter the number of elements to sort:");
    scanf("%d",&n);
    if(n<=5000){
        printf("please enter a value greater than 5000.\n");
        return 1;
    }
    int *arr = (int*)malloc(n*sizeof(int));
    if(arr == NULL){
         printf("Memory allocation failed.\n");
         return 1;
    }
    generaterandomnumbers(arr,n);   
    clock_t start = clock();
    SelectionSort(arr,n);
    clock_t end =clock();
    double timetaken=(double)(end-start)/CLOCKS_PER_SEC;
    printf("time taken to sort %d elements %fseconds\n",n,timetaken);
    free(arr);
    return 0; 
}

