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
    return -1
}