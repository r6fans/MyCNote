/*2.3 二分搜索*/
template<class Type>
int BinarySearch(Type a[], const Type& x,int n){ //在数组a(已排好序)中查找x的位置，n为数组长度
    //找到X时返回其在数组中的位置,否则返回-1
    int left = 0;
    int right = n-1;
    while(left <= right){
        int middle = (left+right)/2
        if(a[middle] == x){
            return middle;
        }
        if(a[middle] < x){
            left = middle + 1;
        }else{
            right = middle - 1;
        }
    }
    return -1;
}

/*2.7 归并排序
算法思想： 将待排序元素分成两个大小一致的两个子集，分别对两个子集进行归并排序，最后对排好序的子集合并*/
template<class Type>
void MergeSort(Type a[], int left, int right){
    if(left < right){
        int i = (left+right)/2;
        MergeSort(a, left,i);
        MergeSort(a,right,i);
    }
}