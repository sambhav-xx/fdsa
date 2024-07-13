#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct listNode{
    int data;
    struct listNode *next;
};

struct Queue{
    struct listNode *front;
    struct listNode *rear;
};

struct Queue* CreateQ(){
    struct Queue *Q;
    
    Q=malloc(sizeof(struct Queue));
    if(!Q){
        return NULL;
    }
    
    Q->front = Q->rear = NULL;
    return Q;
}

void enqueue(struct Queue*Q, int data){
    struct listNode*newNode;
    newNode=malloc(sizeof(struct listNode));
    if(!newNode){
        return;
    }
    
    newNode->data = data;
    newNode->next = NULL;
    if(Q->rear){
        Q->rear->next = newNode;
    }
    Q->rear = newNode;
    if(Q->front == NULL){
        Q->front = Q->rear;
    }
}

bool IsEmpty(struct Queue *Q){
    return Q->front == NULL;
}

int dequeue(struct Queue *Q){
    int data = 0;
    struct listNode*temp;
    if(IsEmpty(Q)){
        printf("Queue is empty\n");
        return 0;
    }
    else{
        temp = Q->front;
        data = Q->front->data;
        Q->front = Q->front->next;
        if (Q->front == NULL) {
            Q->rear = NULL;
        }
        free(temp);
    }
    return data;
}

void DeleteQ(struct Queue *queue){
    while(!IsEmpty(queue)){
        dequeue(queue);
    }
    free(queue);
}

void print(struct Queue* queue){
    if (IsEmpty(queue)) {
        printf("Queue is empty\n");
        return;
    }
    struct listNode* p;
    p = queue->front;
    while(p->next != NULL){
        printf("%d->",p->data);
        p = p->next;
    }
    printf("%d\n",p->data);
}

int main()
{
    struct Queue* q1 = CreateQ();
    if(!q1){
        printf("Failed to create queue...\n");
        return 1;
    }
    
    enqueue(q1,1);
    enqueue(q1,2);
    enqueue(q1,3);
    enqueue(q1,4);
    enqueue(q1,5);
    enqueue(q1,6);
    
    print(q1);
    
    printf("dequeued : %d\n",dequeue(q1));
    print(q1);
    
    DeleteQ(q1);
    //print(q1);
    printf("...end...");

    return 0;
}
