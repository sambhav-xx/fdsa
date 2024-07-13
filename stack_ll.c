#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int data;
    struct Node* next;
}Node;

typedef struct{
    Node*top;
}Stack;

void push(Stack* stack, int data){
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = stack->top;
    stack->top = newNode;

}

int pop(Stack* stack){
    int popped = stack->top->data;
    Node* p = stack->top;
    p->next = stack->top->next;
    free(p);
    
    return popped;
}

int main(){
    Stack* s1 = (Stack*)malloc(sizeof(Stack));
    push(s1,1);
    
    return 0;
}