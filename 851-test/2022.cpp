/*1. 
a. 分析s++的执行次数
b. 分析x+=2的执行次数
c. 若n=5,最后的输出结果*/
void fun(int n){
    int i,j,s,x;
    for(s=0,i=0;i<n;++i){
        for(j=i;j<n;++j){
            s++;
        }
    }
    i = 1;
    j = n;
    x = 0;
    while(i<j){
        i+=1;
        j--;
        x += 2;
    }
    printf("%d %d",s,x)
}

/*解答：
a. s++执行了1+2+3+....+N-1次
b. x+=2执行了 N-1次
c. 如果n=5，最后的输出结果为10,10*/

/*2. 现有一颗完全二叉树有892个节点
a. 求二叉树的高度
b. 求二叉树的叶子节点数
c. 求二叉树的单支节点数
d. 求二叉树的非端节点(最后一个叶节点的父节点)的序号,根节点序号为1

a. 2^h - 1 = 892 
所以高度为10
b. n0=n2+1 2n0=892 n0=446
c. 第九层节点数为2^9-1=511 第九层单支节点数为255-446/2=32 所以单支节点数位32+446=478个
d. 511-32 = 479*/

/*4. 使用堆排序、归并排序、快速排序对n个整数进行排序。
a. 仅从空间复杂度方面考虑，应该说是首选什么，其次选什么，最后选什么
b. 从时间复杂度考虑，要获得最小的时间复杂度，最小的应该选哪种排序
c. 如果即要求时间效率又要求空间复杂度则应该选择哪种排序
d. 对{29,18,25,47,58,12,51,10}分别用归并和快速排序，写出其排序过程.*/

/*解答:
a. 仅从空间复杂度方面考虑 首选堆排序其次选择归并排序最后选择快速排序
b. 从时间复杂度方面考虑若想要获得最小的时间复杂度应该选择堆排序
c. 若既要从时间又要从空间方面考虑则应该选择堆排序
d. */

/*5. 
a. 使用c语言给出双链表的数据结构
b. 用上述结构写出删除节点的c语言实现*/

typedef struct DoubleList;
typedef ElemType data;

typedef struct DoubleList{
    ElementType data;
    struct DoubleList *prior;
    struct DoubleList *next;
}DoubleList;



void Delete(int index, DoubleList *p){      //index 为要删除节点的下标, p初始为头结点
    DoubleList *temp = p;
    for(i=0;i<index,i++){                   //遍历到需要删除的节点的前一个节点位置
        temp = temp -> next;
        if(temp->next==NULL){               //未找到该节点
            return;
        }
    }
    DoubleList *del = temp->next;
    temp->next=del->next;
    del->next->prior=temp;
    free(del);
}

/*6.对于输入的非负十进制整数，打印输出与其等值的八进制数，要求：
a. 用C语言给出栈的存储结构
b. 基于上述存储结构，给出元素入栈和出栈的C语言实现
c. 基于前两问，用C语言实现本题*/

//栈的数据结构
#define MAX_SIZE 100
typedef struct Stack{
    int data[MAX_SIZE];
    int top;
}Stack;

//栈的出栈入栈实现
void InitStack(Stack *s){
    s->top = -1;
}

bool IsEmpty(Stack *s){
    return (s->top == -1);
}

bool IsFull(Stack *s){
    return (s->top == MAX_SIZE - 1);
}

void push(Stack *s, int x){
    if(IsFull(s)){
        printf("Stack Full!\n");
        exit(1);
    }
    s->data[++(s->top)] = x;
}

int pop(Stack *s){
    if(IsEmpty(s)){
        printf("Stack empty!/n");
        exit(1);
    }
    return s->data[(s->top)--];
}

// 进制转换实现
void Conversion(int num, int b){
    Stack s;
    InitStack(&s);
    while(num != 0){
        push(&s,num/b);
    }
    while(!isEmpty(&s)){
        printf("%d", Pop(&s));
    }
}
