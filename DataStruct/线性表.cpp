#include<stdio.h>
//顺序存储的线性表
#define MaxSize 50

typedef struct{
    ElemType data[MaxSize];             //顺序表的长度
    int length;                         //顺序表的当前长度
}SqList;                                //顺序表的类型定义


//顺序表插入
bool ListInsert(SqList &L,int i, ElemType e){
    if(i<1||i>L.length+1){              //判断i的范围是否有效
        return false;
    }
    if(L.length>=MaxSize){              //当前存储空间已满，不能插入
        return false;
    }
    for(int j=L.length;j>=i;j--){       //将第i个元素及之后的元素后移
        L.data[j]=L.data[j-1];
    }
    L.data[i-1]=e;                      //在位置i处放入e
    L.length++;                         //线性表长度加1
    return true;
}

//删除操作
bool ListDelete(SqList &L,int i,ElemType &e){
    if(i<1||i>L.length){                //判断i的范围是否有效
        return false;
    }
    e=L.data[i-1];                      //将被删除的元素赋值给e
    for(int j=i;j<L.length;j++){
        L.data[j-1]=L.data[j];
    }
    L.length--;
    return true;
}

//按值查找
int LocateElem(SqList L, ElemType e){
    int i;
    for(i=0;i<L.length;i++){
        if(L.data[i]==e){
            return i+1;                 //下标为i的元素值等于e,返回其位序i+1
        }
    return 0;                           //退出循环，说明查找失败
    }
}

//线性表链式表示
typedef struct LNode{                   //定义单链表节点类型
    ElemType data;                      //数据域
    struct LNode *next;                 //指针域
}LNode, *LinkList;

//头插法建立单链表
LinkList List_HeadInsert(LinkList &L){  //逆向建立单链表
    LNode *s;
    int x;
    L = (LinkList)malloc(sizeof(LNode));//创建头节点
    L->Next=NULL;                       //初始为空链表
    scanf("%d",&x);                     //输入节点的值
    while(x!=9999){                     //输入9999表示结束
        s=(LNode*)malloc(sizeof(LNode));//创建新节点
        s->data=x;
        s->next=L->next;
        L->next=s;                      //将新节点插入
        scanf("%d",&x);
    }
    return L;
}

//尾插法构造单链表
LinkList List_TailInsert(LinkList &L){  //正向建立单链表
    int x;                              //设元素类型为整形
    L=(LinkList)malloc(sizeof(LNode));
    LNode *s,*r=L;                      //r为表尾指针
    scanf("%d",&x);                     //输入节点的值
    while(x!=9999){                     //输入9999表示结束
        s=(LNode *)malloc(sizeof(LNode));
        s->data=x;
        r->next=s;
        r=s;                            //r指向新的链表节点
        scanf("%d",&x);
    }
    r->next=NULL;                       //尾节点执政制空
    return L;
}

//双链表
typedef struct DNode{
    ElemType int Data;                  //数据域
    struct DNode *prior,*next;          //前驱和后继指针
}DNode, *DLinklist;