#include <stdio.h>

void dup(int a[],int n){
    int b[100];
    for(int j=0;j<100;j++){
        b[j]=0;
    }
    for(int i=0;i<n;i++){
        int index = a[i];
        if(b[index] == 0){
            b[index] = 1;
        }else{
            printf("YES %d\n",a[i]);
        }
        
    }
}

int main(){
    int n = 5;
    int a[5]= {5,8,8,2,2};
    dup(a,n);
    
    return 0;
}