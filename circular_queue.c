#include <stdio.h>
#include <stdlib.h>

struct ArrayQueue{
    int front, rear;
    int capa;
    int *arr;
};

struct ArrayQueue* Queue(int size){
    struct ArrayQueue* q = malloc(sizeof(struct ArrayQueue));
    q->capa = size;
    q->front = q->rear = -1;
    q->arr=(int*) malloc(q->capa*sizeof(int));
    return q;
}

int queue_size(struct ArrayQueue* q){
    if(q->front == -1){
        return 0;
    }
    return (q->capa+1+q->rear-q->front)%q->capa;
}

int IsEmptyQueue(struct ArrayQueue *q){
    return q->front == -1;
}

int IsFullQueue(struct ArrayQueue *q){
        return (q->rear+1)%q->capa == q->front ;
}

void enqueue(struct ArrayQueue *q, int data){
    if(IsFullQueue(q)){
        printf("queue overflow");
        return;
    }else{
        q->rear = (q->rear+1)%q->capa;
        q->arr[q->rear]=data;
        if(q->front == -1){
            q->front = q->rear;
        }
    }
    
}

int dequeue(struct ArrayQueue *q){
    if(IsEmptyQueue(q)){
        printf("queue empty");
        return 0;
    }else{
        int data = q->arr[q->front];
        if(q->front == q->rear){
            q->front = q->rear=-1;
        }else{
        q->front=(q->front+1)%q->capa;
        }
        return data;
    }
}

void print(struct ArrayQueue* q){
    if(IsEmptyQueue(q)){
        printf("queue is empty");
        return;
    }
    int i = q->front;
    while(i != q->rear){
        printf("%d ",q->arr[i]);
        i = (i+1)%q->capa;
    }
    printf("%d\n",q->arr[q->rear]);
}

int main()
{
    struct ArrayQueue* q = Queue(5);
    
    enqueue(q,1);
    enqueue(q,2);
    enqueue(q,3);
    enqueue(q,4);
    enqueue(q,5);
    print(q);
    
    dequeue(q);
    dequeue(q);
    print(q);

    return 0;
}