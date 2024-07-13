#include <stdio.h>

void bubble_sort(int a[],int n){
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-i-1;j++){
            if(a[j+1]<a[j]){
                int swap = a[j];
                a[j]=a[j+1];
                a[j+1]=swap;
            }
        }
    }
}

int main(){
    int n = 5;
    int a[5]= {5,8,3,2,9};
    bubble_sort(a,n);
    
    for(int k=0;k<n;k++){
        printf("%d ",a[k]);
    }
}
