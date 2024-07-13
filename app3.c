#include <stdio.h>

void bubble_sort(int a[],int n){
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-i-1;j++){
            if(a[j+1]<a[j]){
                int swap = a[j+1];
                a[j+1]=a[j];
                a[j]=swap;
            }
        }
    }
}

void dup(int a[],int n){
    for(int i=0;i<n-1;i++){
        if(a[i] == a[i+1]){
            printf("YES %d\n",a[i]);
        }
    }
}

int main(){
    int n = 5;
    int a[5]= {5,8,8,2,2};
    bubble_sort(a,n);
    dup(a,n);
    
    return 0;
}