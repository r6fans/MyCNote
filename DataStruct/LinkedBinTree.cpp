#include<stdio.h>
#include<malloc.h>
#include<vector>
#include<queue>
#include<algorithm>
using namesapce std;
typedef struct TreeNode *BinTree;
struct TreeNode{
    int Data; //存值
    BinTree Left; //左孩子
    BinTree Right; //右孩子
};

BinTree CreatBinTree(); //创建二叉树
bool IsEmpty(BinTree BT);
void PreOrderTraversal(BinTree BT); //先序遍历二叉树, 根左右
void InOrderTraversal(BinTree BT); //中序遍历二叉树，左右根
void PostOrderTraversal(BinTree BT); //后序遍历，左右根

typedef struct SNode *Stack;
struct SNode{
    BinTree Data;
    Stack Next;
};

Stack CreateStack();
int IsEmpty(Stack s); //判断栈是否为空
void Push(Stack S, BinTree item); //入栈
BinTree Pop(Stack S); //出栈


//初始化链栈
Stack CreateStack(){
    Stack S;
    S = (Stack)malloc(sizeof(struct SNode));
    S->Next = NULL;
    return S;
}


//判断是否为空
int IsEmpty(Stack S){
    return (S->Next == NULL);
}

//入栈
void Push(Stack S, BinTree item){
    Stack tmp;
    tmp = (Stack)malloc(sizeof(struct SNode));
    tmp->Data = item;
    //链栈栈顶元素是链表头节点，新入栈的在栈顶元素后面
    tmp->Next = S->Next;
    S->Next = tmp;
}

//出栈
BinTree Pop(Stack S){
    Stack First;
    BinTree TopVal;
    if(IsEmpty(S)){
        printf("堆栈空");
        return 0;
    }else{
        First = S->Next; //出栈第一个元素在栈顶元素后
        S->Next = First->Next;//把第一个元素从链栈删除
        TopVal = First->Data;
        free(First);
        return TopVal;
    }
}

BinTree Insert(int Data){
    BinTree BT;
    BT = (BinTree)malloc(sizeof(struct TreeNode));
    BT->Data = Data;
    BT->Left = NULL;
    BT->Right = NULL;
    return BT;
}

// 初始化二叉树
BinTree CreatBinTree(){
    BinTree BT;
    BT = (BinTree)malloc(sizeof(struct TreeNode));
    BT->Data = 1;
    BT->Left = Insert(2);
    BT->Right = Insert(3);
    BT->Left->Left = Insert(4);
    BT->Left->Right = Insert(6);
    BT->Left->Right->Left = Insert(5);
    BT->Right->Left->Right = Insert(8);
    return BT;
}

//判断树为空
bool IsEmpty(BinTree BT){
}

//先序递归
// void PreOrderTraversal(BinTree BT){
//     if(BT){
//         printf("%d", BT->Data);//打印根
//         PreOrderTraversal(BT->Left); // 进入左子树
//         PreOrderTraversal(BT->Right); // 进入右子树
//     }
// }

//先序非递归
void PreOrderTraversal(BinTree BT){
    BinTree T = BT;
    Stack S = CreateStack(); // 创建并初始化堆栈 S
    while(T || !IsEmpty(S)){
        while(T){
            Push(S,T); //压栈。第一次遇到该节点
            printf("%d",T->Data); //访问节点
            T = T -> Left;
        }
        if(!IsEmpty(S)){ //当栈不空时
            T = Pop(S); //出栈，第二次遇到该节点
            T = T->Right; //访问右节点
        }
    }
}

// //递归中序遍历
// void InOrderTraversal(BinTree BT){
//     if(BT){
//         InOrderTraversal(BT->Left); // 进入左子树
//         printf("%d",T->Data);
//         InOrderTraversal(BT->Right); // 进入右子树
//     }
// }

// 中序非递归
void InOrderTraversal(BinTree BT){
    BinTree T = BinTree Data;
    Stack S = CreateStack(); //初始化创建堆栈S
    while(T || !IsEmpty(S)){ //当树不为空或堆栈不空
        while(T){
            Push(S,T); //压栈
            T = T->Left; //遍历左子树

        }
    }
}

//递归后序遍历
// void PostOrderTraversal(BinTree BT){
//     if(BT){
//         PostOrderTraversal(BT->Left); // 进入左子树
//         PostOrderTraversal(BT->Right); // 进入右子树
//         printf("%d", T->Data); //打印根
//     }
// }

