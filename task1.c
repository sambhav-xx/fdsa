#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct{
    char c;
    int f;
}pair;

bool compare(pair *a, pair *b){
    if(a->f==b->f){
        return a->c <= b->c;
    }
    return a->f <= b->f;
}

void merge(pair *arr,int l,int m,int r){
    int n1=(m-l);
    int n2=(r-m);
    pair L[n1], R[n2];
    for(int i=0;i<n1;i++){
        L[i]=arr[l+i];
    }
    for(int j=0;j<n2;j++){
        R[j]=arr[m+j];
    }
    int i=0, j=0, k=l;
    while(i<n1 && j<n2){
        if(compare(&L[i],&R[j])){
            arr[k]=L[i];
            i++;
            k++;
        }else{
            arr[k]=R[j];
            j++;
            k++;
        }
    }
    while(i<n1){
        arr[k]=L[i];
        i++;
        k++;
    }
    while(j<n2){
        arr[k]=R[j];
        j++;
        k++;
    }
}

void merge_sort(pair *arr,int l,int r){
    if (r - l <= 1) {
        return;
    }
    int m=l+(r-l)/2;
    merge_sort(arr,l,m);
    merge_sort(arr,m,r);
    merge(arr,l,m,r);
}

void task1(char*s,int n){
    pair arr[n];
    for(int i=0;i<n;i++){
        arr[i].c = s[i];
        arr[i].f = 0;
        for(int j=0;j<n;j++){
            if(s[i]==s[j]){
                arr[i].f++;
            }
        }
    }
    merge_sort(arr,0,n);
    
    for(int i=0;i<n;i++){
        s[i]=arr[i].c;
    }
}

int main(){
    printf("n:");
    int n;
    scanf("%d",&n);
    printf("s[n]:");
    char s[n];
    scanf("%s",s);
    
    printf("1\nbefore: %s\n",s);
    task1(s,n);
    printf("after:%s\n",s);
    
    printf("2\nbefore\n: %s",s);
    //task2(s);
    printf("after:%s\n",s);
    
    return 0;
}