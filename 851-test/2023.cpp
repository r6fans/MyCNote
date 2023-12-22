//十进制整数200转化成十六进制数是 c8
// 程序填空
#define MAX 100
typedef struct datatype;
typedef struct{
    datatype data[MAX];
    int top;
}SeqStack;
void fun(int x){
    SeqStack *SS;
    int y;
    SS = (SeqStack *)malloc(sizeof(SeqStack));
    SS->top=0;
    while( (2) ){
        Push(SS,x%16);
        (3);
    }
    while(SS->top, 0){
        y = Pop(SS);
        if( (4) ){
            printf("%d",y);
        }else
        printf("%c", (5));
    }
}

/*1. c8
2. x!=0
3. x= x/16
4. y<10
5. 'a' + (y-10)*/

/*给定二叉树的先序遍历序列ABCDEFG 中序序列CBEDAFG 写出后续序列 CEDBGFA
中序线索化二叉树 填空*/
typedef struct node{
    char data;
    int ltag, rtag;
    struct node *lchild, *rchild;
}bithptr;
bithptr *pre=NULL;
void INTHREAD(bithptr *t){
    if()
}