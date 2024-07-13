#include <stdio.h>

void dup(int a[],int n){
    int flag = 0;
    for(int i=0;i<n;i++){
        int key=a[i];
        for(int j=i+1;j<n;j++){
            if(a[j] == key){
                printf("YES %d",key);
                flag = 1;
            }
        }
    }
    if(flag == 0){
        printf("NO");
    }
}

int main(){
    int n = 5;
    int a[5]= {5,8,1,2,9};
    dup(a,n);
    
    return 0;
}
