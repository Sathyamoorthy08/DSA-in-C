#include<stdio.h>

void swap(int *a,int *b){
    int t=*a;
    *a=*b;
    *b=t;
}

int partition(int a[],int left,int right){
    int pivot = a[left];
      int i=left;
        for(int j=left+1;j<=right;j++){
            if(a[j]<=pivot){
                i++;
                swap(&a[i],&a[j]);
            }
        }
        swap(&a[left],&a[i]);
        return i;
}

void QuickSort(int a[],int left,int right){
    if(left<right){
        int k = partition(a,left,right);
        QuickSort(a,left,k-1);
        QuickSort(a,k+1,right);
    }
}

void print(int n,int a[]){
    for(int i=0;i<n;i++){
        printf("%3d",a[i]);
    }
    printf("\n");
}

int main(){
    int n=9;
    int a[9] = {5,3,7,4,2,9,8,1,6};
    QuickSort(a,0,n-1);
    printf("Bubble sort: ");
    print(n,a);
  return 0;
}