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
int Find(ElemenType X, List L);
void Insert(ElemenType X, int i, List L); //在下标为i的地方插入X
void Delete(int i, List L); // 删除下标为i的当前值
ElemenType FindKth(int K, List L); //返回下标为K的当前值
int Length(List L); //返回顺序表的长度

//初始化
List MakeEmpty(){
    List L;
    L = (List)malloc(sizeof(struct LNode));
    L->Last = -1;
    return L;
}

// 按值查找
int Find(ElemenType X, List L){
    int i = 0;
    while( i <= L->Last && L -> Data[i] != X)
        i++;
    if(L->Last < i) //若未找到，返回-1
        return -1;
    else //
        return i;
}

//插入
void Insert(ElemenType X, int i, List L){
    int j;
    if(L->Last == MAXSIZE - 1){
        printf("表满");
        return;
    }
    if(i < 0 || L->Last+1 < i){ //数组越界
        printf("位置不合法");
        return;
    }

    for(j=L->Last; j>=i; j--){
        L->Data[j+1] = L->Data[j];
    }

    L->Data[i] = X; //新元素插入
    L->Last++;
    return;
}

//删除
void Delete(int i, List L){
    int j;
    if(i < 0 || L->Last < i){
        printf("L->Data[%d]不存在元素",i);
        return;
    }

    for(j=i+1; j<=L->Last;j++){
        L->Data[j-1] = L->Data[j];
    }

    L->Last--; // Last仍然指向最后元素
    return;
}

//按序查找
ElemenType FindKth(int K, List L){
    if(K < 0 || L->Last < k){//数组越界
        printf("L->Data[%d]不存在元素",K);
    }
    return L->Data[K];
}

//表长
int Length(List L){
    return L->Last+1;
}