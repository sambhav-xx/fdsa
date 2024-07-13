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

void insert_end(struct lL** head,int data){
    struct lL* p= *head;
    struct lL*nN = (struct lL*)malloc(sizeof(struct lL));
    nN->data=data;
    while(p->next != NULL){
        p=p->next;
    }
    p->next=nN;
    nN->next=NULL;
}

void insert_k(struct lL** head,int data,int position){
    struct lL *p1, *p2= *head;
    struct lL*nN = (struct lL*)malloc(sizeof(struct lL));
    nN->data=data;
    int c=0;
    while(p2->next != NULL && c<position){
        c++;
        p1=p2;
        p2=p2->next;
    }
    p1->next=nN;
    nN->next=p2;
}

int size(struct lL* head){
    struct lL* p= head;
    int c=0;
    while(p->next!=NULL){
        c++;
        p=p->next;
    }
    c=c+1;
    
    return c;
}

void print(struct lL* head){
    struct lL* p = head;
    
    while(p->next != NULL){
        printf("%d->",p->data);
        p=p->next;
    }
    printf("%d\n",p->data);
}

void delete(struct lL** head){
    struct lL* p = *head;
    *head = (*head)->next;
    free(p);
}

void delete_end(struct lL** head){
    struct lL *p1,*p2 = *head;
    while(p2->next != NULL){
        p1=p2;
        p2=p2->next;
    }
    free(p2);
    p1->next = NULL;
}

void delete_k(struct lL** head,int position){
    struct lL *p1,*p2 = *head;
    int c=0;
    while(p2->next != NULL && c<position-1){
        c++;
        p1=p2;
        p2=p2->next;
    }
    p1->next=p2->next;
    p2->next=NULL;
    free(p2);
}

int main(){
    struct lL* h =NULL;
    insert(&h,1);
    insert(&h,2);
    insert(&h,3);
    insert(&h,4);
    insert(&h,5);
    insert_end(&h,6);
    insert_k(&h,7,3);
    print(h);
    printf("size: %d\n",size(h));
    
    delete(&h);
    delete_end(&h);
    delete_k(&h,3);
    print(h);
    printf("size: %d\n",size(h));
    
    return 0;
}