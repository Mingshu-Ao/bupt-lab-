#define _CRT_SECURE_NO_WARNINGS 1  
#include<stdio.h>  
#include<stdlib.h>  

typedef struct SqStack {
    //build a stack
    int* base;
    int* top;
    int stacksize;
} SqStack;

int InitStack(SqStack* S) {
    //initialize it
    S->base = (int*)malloc(100 * sizeof(int));
    if (!S->base) {
        fprintf(stderr, "Memory allocation failed\n");
        return 0;
    }
    S->top = S->base;
    S->stacksize = 100;
    return 1;
}

int Push(int x, SqStack* S) {
    if (S->top - S->base >= S->stacksize) {
        S->base = (int*)realloc(S->base, (S->stacksize + 10) * sizeof(int));
        if (!S->base) {
            fprintf(stderr, "Memory reallocation failed\n");
            return 0;
        }
        S->stacksize += 10;
    }
    *S->top = x;
    S->top++;
    return 1;
}

int Pop(SqStack* S, int* value) {
    if (S->base == S->top)
        return 0;
    S->top--;
    *value = *S->top;
    return 1;
}

int main() {
    SqStack S;
    if (!InitStack(&S)) {
        return 1;
    }
    int dec_num;
    printf("Enter a decimal number: ");
    scanf("%d", &dec_num);
    for (; dec_num > 0; dec_num /= 8) {
        int remainder = dec_num % 8;
        Push(remainder, &S);
    }
    printf("Octal equivalent: ");
    while (S.top != S.base) {
        int num;
        Pop(&S, &num);
        printf("%d", num);
    }
    printf("\n");
    free(S.base);
    //free the memory
    return 0;
}

