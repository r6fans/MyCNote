/*1.叙述线性结构的特点；写一个算法，删除单链表的头节点

答：线性结构的特点
1. 线性结构元素之间存在唯一的前驱和后继，即每个元素只有一个前驱和后继
2. 元素之间是一对一的关系，不存在一对多或者多对多的关系
3. 元素在结构中有固定的位置，每个元素都有一个唯一的位置
4. 元素的插入和删除只能在特定位置进行*/

//删除单链表的头节点
Node *Delete_head(Node *pHead){
    if(pHead==NULL){
        return NULL; //最后有一个节点被删除时，返回NULL
    }
    Node *pTemp = pHead->next; //临时存储头节点的下一个节点，便于制作新的头节点
    free(pHead);
    if(pTemp==NULL){   //最后一个节点被删除时pTemp为空，则返回NULL
        return NULL;
    }
    //pHead指向的内存已经被释放
    pHead=pTemp; //通过pTemp让头指针指向第二个节点
    return pHead;
}

/*2
a. 栈是什么？有什么特点
b. 描述该算法的过程(可用自然语言)
c. 画图展示该算法的运行过程

a. 栈是用来存储逻辑关系为“一对一”数据关系的线性结构，同顺序表和链表一样。
特点：1. 栈只能用从表的一端存取数据，另一端是封闭的；2. 在栈中需要遵循先进后出的原则

b. 算法步骤
1. 将s入栈
2. 将栈顶元素出栈
3. 探索栈顶元素周围按照右上左下的顺序判断是否为可着色节点，可着色节点必须满足 该点是像素点不是边界点且该点并未被染色
4. 将合法的可染色节点入栈
5. 重复步骤2-4直到栈为空*/

/*3. 综合快速排序，回答一下问题
叙述冒泡排序的过程
设计实例，叙述快速排序的过程

答： 冒泡排序过程
比较两个相邻的元素，将值大的元素交换到右边
过程：依次比较相邻的两个数，将比较小的元素放在前面，较大的数放后面
1. 第一次比较：首先比较第一和第二个数，将小数放前面，大数放后面
2. 比较第二和第三个数，将小数放前面大数放后面
3. 如此继续，直到比较最后两个数，将小数放前面大数放后面，重复步骤，直到排序完成
4. 在上面一趟比较完成后，最后一个数一定是数组中最大的一个数，所以比较第二趟的时候，最后一个数不参加比较
5. 在第二趟排序完成后倒数第二个数一定是数组中倒数第二大的数，所以第三趟的比较中最后两数不比较
6. 以此类推，每趟排序比较次数减一

使用序列{49，38，65，97，76，13，27，49}来叙述快速排序过程，pivot为基准
起始状态 pivot=49
{49，38，65，97，76，13，27，49}
  i                          j

*/

/*4.结合计算机算法设计与分析
a. 什么是动态规划？动态规划与分治法的区别是什么？
b. 举例说明，动态规划求解最优化问题的过

a. 动态规划法是将复杂问题分解成更小的子问题，并将子问题的解缓存起来，以便保证每个子问题只需要求解一次，避免重复计算。动态规划法通过把问题分解为若干个重叠子问题，递归的求解子问题，并把子问题的解保存在一个查找表中，从而最终得出主问题的解。
分治法也是将问题分解成规模更小的子问题，并将子问题的解合并来求最终的主问题的解。分治法与动态规划法的区别在于子问题是否重复，动态规划法用于解决有重叠子问题的问题，分支用于解决子问题不重复的情况

b. 用0-1背包问题举例

在N件物品中取出若干件放在容量为W的背包中，每件物品的体积为W1,W2,....Wn(Wi为整数)，与之相对应的价值为P1,P2....Pn(Pi为整数)，求解背包能够容纳的最大价值。要解决最大的问题是n个物品的规模缩小为考虑前n-1个物品的(1,2,...c)
的背包容量等c个子问题。依次向前类推，当我们考虑只有1个物品时，最优解显然容易求解，再自底向上来求解大问题。当我们求解出子问题的最优解时，采用*/

/*5.
斐波那契函数 f(0)=1,f(1)=1,f(2)=f(0)+f(1)....f(n)=f(n-1)+f(n-2)*/
void Fibonacci(int n){
    if(n==0){
        return 1; 
    }
    else if(n==1){
        return 1;
    }else{
        return Fibonacci(n-1)+Fibonacci(n-2)
    }

}

/*斐波那契数列的时间复杂度与空间复杂度
假设需要求其中的第n位，可以构建二叉树，二叉树的高度为n-1, 一颗高度为k的二叉树叶子节点数有2^k-1个叶子结点，所以递归项最多
执行2^k-1次，所以时间复杂度为O(2^n),空间复杂度为数的高度S(n)*/

/*6. 哈夫曼树以自底向上实现，若定义叶子结点所在层位第一层，其父为第二层，以此类推，处在第n层的节点扫描n-1次，复杂度为0(n^2)
a. 分别设计能表示二叉树的链式结构和队列数据结构*/

//e链式结构
typedef struct _htNode{         //树节点的结构体
    char symbol;
    struct _htNode *left,*right;   
}htNode;

typedef struct _htTree{         //树的结构体，树的根
    htNode *root;

}htTree;

typedef struct _htNode{         //编码表结点结构体，表示每个字符以及字符编码
    char symbol;
    char *code;
    struct _hlNode *next;
}hlNode;

typedef struct _hlTable{            //编码表结构体
    hlNode *first;
    hlNode *last;
}hlTable;

//队列数据结构
typedef struct _pQueueNode{         //队列节点结构体
    htNode *val;
    struct _pQueueNode *next;
}pQueueNode;

typedef struct _pQueue{             //队列节点
    unsigned int size;
    pQueueNode *first;
}pQueue;

/*b.基于上述两种数据结构设计一个复杂度为O(n)的哈夫曼树新编码算法，可实现从根向叶子结点编码，写出思想
c. 实现上述算法
d. 分析时间复杂度为什么是O(n)

算法思想：
1. 首先将字符按照出现的次数由小到大排序后放入队列1中
2. 比较以下几种情况后选择最小的代价合并后放入队列2中
情况1：队列1中和队列2中都有超过两个元素假设是x1,x2,y1,y2, 比较x1+x2 x1+y1 y1+y2 三种情况的最小情况放入队列2中
情况2： 队列1中有两个元素，而队列2为空，则直接将队列1中前两个元素合并后放入队列2中
情况3： 队列1中有两个元素x1和x2，而队列2中有1个元素y1,则比较x1+y1 x1+x2
情况4： 队列中有一个元素，而队列2中有两个以上元素，则比较x1+y1 y1+y2
情况5： 队列1中有一个元素，而队列2中有一个元素，直接合并两个元素
3. 循环执行上述几种情况，直到队列2中只有1个元素，则结束，此时二叉树合并完成*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<string>
#include<map>
#define Heapcapacity 64
#define MinData 0
typedef struct TreeNode *HuffmanTree;
typedef struct Heap *MinHeap;
struct Heap{                            //堆
    HuffmanTree *data;                  //存哈夫曼树
    int size;                           //堆的当前大小
}

struct TreeNode{                        //哈夫曼树
    int weight;                         //频率
    HuffmanTree left;
    HuffmanTree right;
};
using namespace std;

MinHeap createHeap();                   //建堆
HuffmanTree createHuffman();            //建哈夫曼树
void sortHeap(MinHeap H, int i);        //调整子最小堆
void adjust(MinHeap H);                 //调整堆
MinHeap InitHeap(int n);                //初始化堆
HuffmanTree Delete(MinHeap H);          //堆的删除
void Insert(MinHeap H,HuffmanTree Huff); //堆的插入
HuffmanTree Huffman(MinHeap H);             //哈夫曼树的构造
int WPL(HuffmanTree Huff, int depth);       //计算HuffmanTree的编码长度
void PreOrderTraversal(HuffmanTree Huff);   //前序遍历


map<char,int> mapp;                     //保持字符到频率的映射关系

//建堆
MinHeap createHeap(){
    MinHeap H;
    H = (MinHeap)malloc(sizeof(struct Heap));
    H -> data = (HuffmanTree *)malloc(sizeof(struct TreeNode) * HeapCapacity);
    H -> size = 0;
    //设置哨兵
    HuffmanTree Huff = createHuffman();
    H->data[0]=Huff;
    return H;
}

//建哈夫曼树
HuffmanTree createHuffman(){
    HuffmanTree Huff;
    Huff = (HuffmanTree)malloc(sizeof(struct TreeNode));
    Huff->weight=MinData;               //初始化成频率最小
    Huff->left=NULL;
    Huff->right=NULL;
    return Huff;
}


//调整子最小堆
void sortHeap(MinHeap H, int i){
    int parent,child;
    HuffmanTree Huff = H ->data[i];     //拿到当前根节点的哈夫曼树
    for(parent = i; parent*2<=H->size;parent=child){
        //左右儿子中挑小的
        child = parent * 2;
        if((child!=H->size) && (H->data[child+1]->weight < H->data[child] -> weight)){
            child++;
        }
        //没有更小的了结束循环
        if(Huff->weight <= H->data[child]->weight){
            break;
        }
        //否则把儿子节点拿上来
        H->data[parent] = H->data[child];
    }
    H->data[parent] = Huff;
}


//调整堆
void adjust(MinHeap H){
    //从第一个有孩子节点的节点开始调整
    for(int i=H->size/2;i>0;i--){
        sortHeap(H,i);
    }
}


//初始化堆
MinHeap InitHeap(int n){
    MinHeap H = createHeap();
    HuffmanTree Huff;
    char c;                     //临时保存字符
    int f;                      //临时保存频率
    for(int i=0;i<n;i++){
        getchar();
        scanf("%c,%d",&c,&d);
        mapp.insert(pair<char,int>(c,f));           //把字符和频率的映射关系存进map
        Huff = createHuffman();
        Huff->weight=f;
        H->data[++H->size] = Huff;
    }
    //调整最小堆
    adjust(H);
    return H;
}

//堆得删除
HuffmanTree Delete(MinHeap H){
    int parent,child;
    HuffmanTree T = H->data[1];                     //拿到根节点的哈夫曼树
    for(parent=1;parent*2<=H->size;parent=child){
        //左右儿子中挑小的
        child = parent * 2;
        if((child!=H->size) && (H->data[child+1]->weight < H->data[child]->weight)){
            child++;
        }
        //没有更小的则结束循环
        if(Huff->weight<=)
    }
}

//堆的插入
void Insert(MinHeap H, HuffmanTree Huff){
    int i= ++H->size;
    for(;Huff->wight < H->data[i/2]->weight;i/2){
        H->data[i] = H->data[i/2];
    }
    H->data[i]=Huff;
}

//哈夫曼树的构造
HuffmanTree Huffman(MinHeap H){
    HuffmanTree Huff;
    int times = H->size;
    for(int i=1;i<times;i++){
        Huff = createHuffman();
        Huff->left=Delete
    }
}