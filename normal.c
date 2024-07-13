#include <stdio.h>

int get_max_in(int a[],int n){
    int max_in=0;
    for(int j=0;j<n;j++){
        if(a[j]>a[max_in]){
            max_in = j;
        }
    }
    return max_in;
}

void sort(int a[],int n){
    for(int i=n-1;i>0;i--){
        int max_in = get_max_in(a,i+1);
        int swap = a[i];
        a[i]=a[max_in];
        a[max_in]=swap;
    }
}

int main(){
    int n = 5;
    int a[5]= {5,8,3,2,9};
    sort(a,n);
    
    for(int k=0;k<n;k++){
        printf("%d ",a[k]);
    }
}