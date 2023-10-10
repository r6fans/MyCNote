#include<stdio.h>
#include<malloc.h>
#define MAXSIZE 100 // 定义为Data数组大小

typedef struct LNode *List;
struct LNode{
    ElemenType Data[MAXSIZE];
    int Last; // 线性表最后一个元素
};

List L;
// 访问下标为i的元素： L->Data[i]
// 线性表的长度: L->Last+1

List MakeEmpty(); //初始化线性表
int Find()