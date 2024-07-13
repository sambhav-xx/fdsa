#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

typedef struct{
    int items[MAX_SIZE];
    int front;
    int rear;
    int size;
}Queue;

void enqueue(Queue* queue, int data){
    queue->rear = (queue->rear+1)%MAX_SIZE;
    queue->items[queue->rear] = data;
    queue->size++;
}

int dequeue(Queue* queue){
    int popped = queue->items[queue->front];
    queue->front = (queue->front+1)%MAX_SIZE;
    queue->size--;
    
    return popped;
}

void print(Queue* queue){
    while(queue->front != MAX_SIZE-1)
}

int main(){
    Queue* q1 = malloc(sizeof(Queue));
    q1->front = 0;
    q1->rear = -1;
    q1->size = 0;
    
    enqueue(q1,1);
    enqueue(q1,2);
    enqueue(q1,3);
    
    return 0;
}