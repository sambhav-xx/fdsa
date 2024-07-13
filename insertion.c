#include <stdio.h>

void insertion_sort(int a[],int n){
    for(int i=1;i<n-1;i++){
            int key = a[i];
            int j=i-1;
        while(j>=0 && a[j]>key){
            a[j+1]=a[j];
            j--;
        }
        a[j+1]=key;
    }
}

int main(){
    int n = 5;
    int a[5]= {5,8,3,2,9};
    insertion_sort(a,n);
    
    for(int k=0;k<n;k++){
        printf("%d ",a[k]);
    }
}