#define MaxSize 50                  //定义队列中元素的最大个数
//顺序存储的队列
typedef struct{
    ElemType data[MaxSize];         //存放队列元素
    int front,rear;                 //队头指针和队尾指针
}SqQueue;

/*初始时：Q.front=Q.rear=0
进队操作: 当队不满时，先将值送队尾，然后队尾元素+1
出队操作: 当队不空时，先取队头元素值，再将队头指针+1*/



/*
循环队列队空/队满判定
1.牺牲一个数据单元来进行判定
初始时:Q.front=Q.rear=0
队首指针进1：Q.front=(Q.front+1)%MaxSize
队尾指针进1:Q.rear=(Q.rear+1)%MaxSize
队列长度:(Q.rear+Maxsize-Q.front)%MaxSize*/

// typedef struct{
//     ElemType data[MaxSize];         
//     int front,rear;
//     int size;         //2.设置一个记录元素个数的数据成员     
//     int tag;          //增设tag来进行区分 
// }SqQueue;


//循环队列初始化
void InitQueue(SqQueue &Q){
    Q.rear=Q.front=0;                   //初始化队首、队尾指针
}

bool IsEmpty(SqQueue Q){
    if(Q.rear==Q.front){
        return true;                    //队空条件
    }else{
        return false;
    }
}
//出队
bool EnQueue(SqQueue &Q, ElemType x){
    if((Q.rear+1)%MaxSize==Q.front){        //队满则报错
        return false;
    }
    Q.data[Q.rear]=x;                       //队尾指针加1取模
    return true;
}

//入队
bool DeQueue(SqQueue &Q,ElemType &x){
    if(Q.rear==Q.front){
        return false;                       //队空报错
        x=Q.data[Q.front];
        Q.front=(Q.front+1)%MaxSize;        //队头指针加1取模
        return true;
    }
}

//队列链式存储
typedef struct LinkNode{                    //链式队列节点
    ElemType data;
    struct LinkNode *next;
}LinkNode;
typedef struct{                              //链式队列
    LinkNode *front,*rear;                  //队列的队头和队尾指针
}*LinkQueue;

/*当Q.front==NULL且Q.rear==NULL时，链式队列为空*/

//链式队列初始化
void InitQueue(LinkNode &Q){
    Q.front=Q.rear=(LinkNode*)malloc(sizeof(LinkNode));         //建立头节点
    Q.front->next=NULL;                                         //初始为空 
}

//判队空
bool isEmpty(LinkNode Q){
    if(Q.front==Q.rear){
        return true;
    }else{
        return false;
    }
}


//入队
void EnQueue(LinkQueue &Q,ElemType x){
    LinkNode *s=(LinkNode *)malloc(sizeof(LinkNode));
    s->data=x;
    s->next=NULL;
    Q.rear->next=s;
    Q.rear=s;
}

//出队
bool DeQueue(LinkQueue &Q,ElemType &x){
    if(Q.front==Q.rear){                                        //空队
        return false;
    }
    LinkNode *p=Q.front->next;
    x=p->data;
    Q.front->next=p->next;
    if(Q.rear==p){
        Q.rear=Q.front;                                         //若原队列中只有一个节点，删除后变空
    }
    free(p);
    return true;
}

/*请设计一个队列，要求满足：①初始时队列为空；②入队时，允许增 
加队列占用空间；③出队后，出队元素所占用的空间可重复使用，即整个队列所占用的 
空间只增不减；④入队操作和出队操作的时间复杂度始终保持为o（1）。请回答下列问题：
1）该队列是应选择链式存储结构，还是应选择顺序存储结构？
2） 画出队列的初始状态，并给出判断队空和队满的条件。
3） 画出第一个元素入队后的队列状态。
4） 给出入队操作和出队操作的基本过程。*/