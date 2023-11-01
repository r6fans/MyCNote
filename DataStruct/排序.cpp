#include<stdio.h>

//直接插入排序
// void InsertSort(ElementType A[], int n){
//     int i,j;
//     for(i=2;i<=n;i++){              //依次将A[2]-A[n]插入前面已排序序列
//         if(A[i]<A[i-1]){            //若A[i]关键码小于其前驱，将A[i]插入有序表
//             A[0]=A[i];              //复制为哨兵，A[0]不存放元素
//         }
//         for(j=i-1;A[0]<A[j];--j){   //从后往前查找待插入位置
//             A[j+1]=A[j];            //向后挪位
//         }
//         A[j+1]=A[0];                //复制到插入位置
//     }
// }

//折半插入排序
void InsertSort(ElementType A[],int n){
    int i,j,low,high,mid; 
    for(i=2;i<=n;i++){                  //依次将A[2]-A[n]插入前面已排序序列
        A[0]=A[i];                      //将A[i]暂存到A[0]
        low=1;high=i-1;                 //设置折半查找的范围
        while(low<=high){               //折半查找(默认递增有序)
            mid=(low+high)/2;           //取中间点
            if(A[mid]>A[0]) high=mid-1; //查找左半子表
            else{
                low=mid+1;              //查找右半子表
            }
        }
        for(j=i-1;j>=high+1;--j){
            A[j+1]=A[j];                //统一后移元素，空出插入位置
        }
        A[high+1]=A[0];                 //插入操作
    }
}

//希尔排序
void ShellSort(ElementType A[],int n){
    int dk,i,j;                         //增量变化
    for()
}

//冒泡排序
void BubbleSort(ElementType A[], int n){
    for(int i=0;i<n-1;i++){
        bool flag=false;                //表示本趟冒泡是否发生交换
        for(int j=n-1;j>i;j--){
            if(A[j-1]>A[j]){
                swap(A[j-1],A[j]);      //交换
                flag=true;
            }
        }
        if(flag==false)
            return;
    }
}

//快速排序

//划分
int Partition(ElementType A[], int low, int high){//一趟划分
    ElementType pivot=A[low];           //将当前表中第一个元素设为枢轴,对标进行划分
    while(low<high){                    //循环跳出条件
        while(low<high && A[high]>=pivot){
            --high;
        }
        A[low]=A[high];                 //将比枢轴小的元素移动到左端
        while(low<high&&A[low]<=pivot){
            ++low;
        }
        A[high]=A[low];                 //将比枢轴大的元素移动到右端
    }
    A[low]=pivot;                       //枢轴元素存放到最终位置
    return low;                         //返回存放枢轴的最终位置
}

//快排
void QuickSort(ElementType A[], int low,  int high){
    if(low<high){                       //递归跳出的条件
        int pivotpos=Partition(A,low,high);  //划分
        QuickSort(A,low,pivotpos-1);    //依次对两个子表进行递归排序
        QuickSort(A,pivotpos+1,high);
    }
}

//简单选择排序
void SelectSort(ElementType A[], int n){
    for(int i=0;i<n-1;i++){             //一共进行n-1趟
        int min=i;                      //记录最小元素位置
        for(int j=i+1; j<n; j++){       //更新最小元素位置
            if(A[j]<A[min]){
                min=j;                 
            }
        }
        if(min!=i){
            swap(A[i],A[min]);
        }
    }
}

//堆排序
//建立大顶堆
void BuildMaxHeap(ElementType A[], int len){
    for(int i=len/2;i>0;i--){           //从i=[n/2]~1,反复调整堆
        HeadAdjust(A,i,len);
    }
}

void HeadAdjust(ElementType A[],int k,int len){
    A[0]=A[K];                          //A[0]暂存子树的根节点
    for(int i=2*k;i<=len;i*=2){         //沿key较大的子节点向下筛选
        if(i<len&&A[i]<A[i+1]){
            i++;                        //沿key较大的子节点的下标
        }
        if(A[0]>=A[i]){
            break;                      //筛选结束
        }else{
            A[k]=A[i];
            k=i;                        //修改K值，以便继续向下筛选
        }
    }
    A[K]=A[0];                          //被筛选节点的值放入最终位置
}

void HeapSort(ElementType A[],int len){
    BuildMaxHeap(A,len);                //初始建堆
    for(int i=len;i>1;i--){             //n-1趟的交换和建堆过程
        swap(A[i], A[1]);               //输出堆顶元素(和堆低元素交换)
        HeadAdjust(A,1,i-1);            //调整,把剩余的i-1个元素整理成堆

    }
}

void swap(int &a,int &b){
    int t = a;
    a = b;
    b = t;
}


//归并排序
ElementType *B = (ElementType *)malloc((n+1)*sizeof(ElementType)); //构造辅助数组B
void Merge(ElementType A[],int low,int high){
    //表A的两段数组A[low...mid]和A[mid+1...high]各自有序，将两个数组合并成一个有序数组
    int i,j,k;
    for(k=low;<=high;k++){
        B[k]=A[k];                      //将A中所有元素复制到B中
    }
    for(i=low,j=mid+1,k=i;i<=mid&&j<=high;k++){
        if(B[i]<=B[j])   A[K]=B[i++];   //比较B的左右两段中的元素
        else    A[k]=B[j++];
    }
    while(i<=mid)   A[k++]=B[i++];      //若第一个表未检测完，复制
    while(j<=high)  A[k++]=B[j++];      //若第二个表未检测完，复制
}