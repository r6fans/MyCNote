//线性表
typedef int datatype;

typedef struct List{
    datatype element;
    struct List *next;
}List;

List* Init(){
    List *link;
    link = (List *)malloc(sizeof(List));
    return link;
}

void Add(datatype element, List* link){
    List *temp = link;
    while(temp->next != NULL){
        temp = temp->next;
    }
    List *new = (List *)malloc(sizeof(List));
    new->element = element;
    temp->next=new;
}

//插入
void Insert(datatype element, int index, List *link){
    List *temp = link;
    //遍历到上个节点
    for(int i=0; i < index;++i){
        temp = temp->next;
        if(temp == NULL) return;
    }
    List *new = (List*)malloc(sizeof(List));
    new->element=element;
    new->next=temp->next;
    temp->next=new;
}

void Delete(int index, List* link){
    List *temp = link;
    //遍历到上个节点
    for(int i=0;i<index; ++i){
        temp = temp->next;
        if(temp == NULL) return;
    }
    List *del=temp->next;
    temp->next=temp->next->next;
    free(del); //手动释放节点，防止内存泄漏
}



//双链表
typedef struct DoubList{
    datatype element;
    struct DoubleList *prior;
    struct DoubleList *next;
}DoubleList;

//有首元节点
DoubleList Init(){
    DoubleList *head;
    head = (DoubleList *)malloc(sizeof(DoubleList));
    return head;
}

//循环链表
typedef struct CircList{
    datatype element;
    struct CircList *next;
}CircList;

CircList *Init(){
    CircList *head;
    head = (CircList *)malloc(sizeof(CircList));
    head->next=head;
    return head;
}

//顺序栈
typedef struct{
    datatype data[100];
    int top;
}SeqStack;

SeqStack* Init(){
    SeqStack *SS;
    SS = (SeqStack *)malloc(sizeof(SeqStack));
    SS -> top = -1;
    return SS;
}

void Push(datatype data, SeqStack *SS){
    SS->data[++SS->top]=data;
}

datatype Pop(SeqStack *SS){
    if(SS->top == -1) return -1;
    return SS->data[SS->top--];
}

//数制转换(求余法) 10进制->b进制
void Conversion(int num, int b){
    SeqStack *stack = init();
    while(num){
        push(num%b, stack);
        num = num/b;
    }
    while(!empty(stack)){
        printf("%d", pop(stack));
    }
}

//冒泡排序
int *BubbleSort(int nums[, int len]){
    //一共len-1个两两比较
    for(int i=0; i<len-1;++i){
        for(int j=0; j<len-1;++j){
            if(nums[j] > nums[j+1]){
                int temp = nums[j];
                nums[j]
            }
        }
    }
}

//快速排序
//快排分区函数
int partition(int nums[], int low, int high){
    //记录基准点，此时出现中转节点
    int pivot = nums[low];
    while(low<high){
        //从高找直到找到一个比基准点小的，记录到低中转节点中
        while(nums[high] >= pivot) --high;
        nums[low] = nums[high];
        while(nums[low] <= pivot) ++low;
        nums[high] = nums[low];
    }
    //low=分区结束位置=高与低中转节点
    nums[low] - pivot;
    return low;
}

//快排主函数，分区递归
int* QuickSort(int nums[], int low, int high){
    if(low >= high) return NULL;
    int pivot = partition(nums,low,high);
    QuickSort(nums, low, pivot-1);
    QuickSort(nums, pivot+1, high);
    return nums;
}

//折半查找
int BinarySearch_Recursion(int start, int end, const int nums[], int target){
    if(start > end) return -1;
    if(start == end){
        return nums[start] == target ? start: -1;
    }
    int middle = (start+end)/2;
    if(nums[middle]==target) return middle;
    if(nums[middle] > target)
        return BinarySearch_Recursion(start, middle-1,nums,target);
    else
        return BinarySearch_Recursion(middle+1, end, nums, target);
}

//非递归
int BinarySearch(const int nums[], int len, int target){
    int start = 0, end = len - 1;
    while(start<=end){
        if(start == end)
            return nums[start] == target ? start : -1;
        int middle = (start+end) / 2;
        if(nums[middle] == target) return middle;
        if(nums[middle] > target) end = middle -1;
        else
            start = middle + 1;
    }
    return -1;
}