#include<stdio.h>
#include<malloc.h>
#define MaxSize 100 // 堆栈元素的最大值
typedef struct SNode *Stack;
struct SNode{
    ElementType Data[MaxSize]; //存储堆栈下标
    int Top;  //记录栈顶元素下标
}

Stack CreateStack(); //初始化堆栈
int IsFull(Stack S); //判断堆栈是否已满
int IsEmpty(Stack S); //判断堆栈是否为空
void Push(Stack S,ElementType item); //入栈
ElementType Pop(Stack S); //出栈

//初始化堆栈
Stack CreateStack(){
    Stack S;
    S = (Stack)malloc(sizeof())
}