//链表存储的线性表
#include<stdio.h>
#include<malloc.h>
typedef int ElementType; // ElemantType 可定义为任意类型
typedef struct LNode *List;
struct LNode{
    ElementType Data; // 数据域
    List Next;
};
List L;

List MakeEmpty(); //初始化链表
int Length(List L); //以遍历链表的方式求表长
List FindKth(int k, List L); //按序查找
List Find(ElementType X, List L); //按值查找
List Insert(ElementType X, int i, List L); //将X插入到第i-1个元素之后
List Delete(int i, List L); // 删除第i(i>0)个节点
void Print(List L); // 输出链表元素

//初始化链表
List MakeEmpty(){
    List L = (List)malloc(sizeof(struct LNode));
    L = NULL;
    return L;
}

//求表长
int Length(List L){
    List P = L;
    int len = 0;
    while(p){ // 当p不为空时
        p = p->Next;
        len++
    }
}

//按序查找
List FindKth(int K, List L){
    List p = L;
    int i = 1; //从1开始
    while(p && i<k){
        p = p->Next;
        i++;
    }

    if( i==k ){ //找到相应元素
        return p;
    }else{  //若未找到，返回空
        return NULL;
    }
}

//按值查找
List Find(ElementType X, List L){
    List p = L;
    while(p && p->Data!=X){
        p = p->Next;
    //找到返回p
    //未找到返回NULL，此时p为NULL
    return p;
    }
}

/*插入
1. 用s指向一个新节点
2. 用p指向第i-1个节点
3. s->Next = p->Next, 将s的下一个节点指向p的下一个节点
4. p->Next = s, 将p的下一个节点改为s*/
List Insert(ElementType X, int i, List L){
    List p,s;
    if(i == 1){ //在表头插入新节点
        s = (List)malloc(sizeof(struct LNode));
        s->Data = X;
        s->Next = L;
        return s; // 插入的节点为头节点
    }

    p = FindKth(i-1,L); // 找到第i-1个节点
    if(!p){ // 第i-1个节点不存在
        printf("节点错误");
        return NULL;
    }else{
        s = (List)malloc(sizeof(struct LNode));
        s->Data = X;
        s->Next = p->Next; //将s的下一个节点指向p的下一个节点
        p->Next = s; //将p的下一个节点改为s
        return L;
    }
}

/*删除
1. 用p指向链表的第i-1个节点
2. 用s指向要被删除的第i个节点
3. p->Next = s->Next, p指针指向s后面
4. free(s), 释放空间*/

List Delete(int i, List L){
    List p,s;
    if(i==1){ // 如果要删除头节点
        s = L;
        if(L){
            L = L->Next;
        }else{
            return NULL;
        }
        free(s); // 释放被删除节点
        return L;
    }

    p = FindKth(i-1, L); // 查找第i-1个节点
    if(!p || !(p->Next)){
        printf("节点错误");
        return NULL;
    }else{
        s=p->Next; //s指向第i个节点
        p->Next = s->Next; //从链表删除
        free(s);
        return L;
    }
}

//输出链表元素
void Print(List L){
    List t;
    int flag = 1;
    printf("当前链表为:");
    for(t=L;t;t=t->Nexts){
        printf("%d ", t->Data);
        flag=0;
    }
    if(flag){
        printf("NULL");
    }
}