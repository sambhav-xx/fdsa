#include <stdio.h> 
#include <stdlib.h>

struct lL{
    int data;
    struct lL*next;
};

void insert(struct lL** head,int data){
    struct lL*nN = (struct lL*)malloc(sizeof(struct lL));
    nN->data=data;
    nN->next=*head;
    *head=nN;
}

void palindrome(struct lL **head){
    struct lL *p1,*p2;
    p1=*head,p2=*head;
    while(p1->next!=NULL && p1->next->next!=NULL){
        p2=p2->next;
        p1=p1->next->next;
    }
    
    struct lL *p3, *new;
    new =NULL;
    p3 = p2->next;
    while(p3!=NULL){
        insert(&new,p3->data);
        p3=p3->next;
    }
    
    struct lL *p4,*p5;
    p4=*head;
    p5=new;
    int flag = 0;
    while(p5!=NULL){
        if(p4->data != p5->data){
            flag = 1;
            break;
        }
        p4=p4->next;
        p5=p5->next;
    }
    if(flag == 0){
        printf("plindrome");
    }else{
        printf("not plindrome");
    }
}

int main(){
    struct lL* h =NULL;
    insert(&h,1);
    insert(&h,2);
    insert(&h,3);
    insert(&h,2);
    insert(&h,1);
    
    palindrome(&h);
    
    return 0;
}