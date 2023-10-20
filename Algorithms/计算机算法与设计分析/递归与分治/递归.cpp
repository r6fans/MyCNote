//例2.1阶乘函数n!
int factorial(int n){
    if(n==0){
        return 1;
    }
    return n*factorial(n-1)
}
//例2.2 Fibonacci 数列
// 无穷数列1，1，2，3，5，8，13，21，34，55...称为Fibonacci数列
int Fibonacci(int n){
    if(n<=1){
        return 1
    }
    return Fibonacci(n-1) + Fibonacci(n-2)
}

/*例2.5 整数划分。 将正整数n表示成一系列正整数之和， n=n1+n2+....+nk
整数划分可分为以下四种情况
1. q(1,1)=1 当 最大加数不大于1时
2. 当 最大加数大于n时 q(n,m)=q(n,n)
*/

int q(int n,int m){
    if(n<1 || m<1){
        return 0;
    }
    if(n==1 || m==1){
        return 1;
    }
    if(n<m){
        return q(n,m-1)+1;
    }

    return q(n,m-1) + q(n-m, m)
}

/*例2.6 Hanoi塔问题*/

int hanoi(int n, int a; int b, int c){
    if(n>0){
        hanoi(n-1,a,c,b);
        move(a,b);
        hanoi(n-1,c,b,a);
    }
}