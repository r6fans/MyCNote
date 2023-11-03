#include<stdio.h>
using namespace std;

//设计一个递归算法，删除不带头结点的单链表L中所有值为x的结点。
void Del_X_3(Linklist &L, ElemType x){
    LNode *p;                   //p指向待删除节点
    if(L==NULL)                 //递归出口
        return;
    if(L->data==x){             //若L所指向节点的值为x
        p=L;                    //删除*L，并让L指向下一节点
        L=L->next;
        free(p);
        Del_X_3(L,x);           //递归调用
    }else{
        Del_X_3(L->next,x)
    }
}

//在带头结点的单链表L中，删除所有值为x的结点，并释放其空间，假设值为x的结点不唯一，试编写算法以实现上述操作。






//设L为带头结点的单链表，编写算法实现从尾到头反向输出每个结点的值。