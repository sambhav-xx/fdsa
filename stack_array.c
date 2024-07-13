#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

typedef struct{
    int top;
    int items[MAX_SIZE];
}Stack;

void push(Stack* stack, int value){
    if(stack->top == MAX_SIZE-1){
        printf("stack overflow");
        return;
    }
    stack->top++;
    stack->items[stack->top] = value;
}

int pop(Stack* stack){
    if(stack->top == -1){
        printf("stack underflow");
        return -1;
    }
    int popped = stack->items[stack->top];
    stack->top--;
    
    return popped;
}

int isEmpty(Stack* stack){
    return stack->top == -1;
}

void print(Stack* stack){
    int i = stack->top;
    while(i > 0){
        printf("%d->",stack->items[i]);
        i--;
    }
    printf("%d\n",stack->items[i]);
}

int top(Stack* stack){
    return stack->items[stack->top];
}

int size(Stack* stack){
    int size = stack->top;
    int count = 0;
    while(size >= 0){
        count++;
        size--;
    }
    return count;
}

int main(){
    Stack* s1 = malloc(sizeof(Stack));
    s1->top = -1;
    
    push(s1,1);
    push(s1,2);
    push(s1,3);
    push(s1,4);
    push(s1,5);
    push(s1,9);
    print(s1);
    
    printf("top: %d\n", top(s1));
    printf("size: %d\n", size(s1));
    
    pop(s1);
    pop(s1);
    pop(s1);
    pop(s1);
    pop(s1);
    pop(s1);
    print(s1);
    
    free(s1);
    
    return 0;
}