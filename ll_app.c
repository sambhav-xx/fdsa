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

void print(struct lL* head){
    struct lL* p = head;
    
    while(p->next != NULL){
        printf("%d->",p->data);
        p=p->next;
    }
    printf("%d\n",p->data);
}

void middle_node(struct lL *Head){
    struct lL *p1,*p2;
    p1=Head,p2=Head;
    while(p1->next!=NULL && p1->next->next!=NULL){
        p2=p2->next;
        p1=p1->next->next;
    }
    printf("middle_node: %d\n",p2->data);
}

void reverse(struct lL **head){
    struct lL *p1,*new;
    new=NULL;
    p1=*head;
    while(p1!=NULL){
        insert(&new,p1->data);
        p1=p1->next;
    }
    print(new);
}

int main(){
    struct lL* h =NULL;
    insert(&h,1);
    insert(&h,2);
    insert(&h,3);
    insert(&h,4);
    insert(&h,5);
    print(h);
    
    middle_node(h);
    reverse(&h);
    
    
    
    
    return 0;
}