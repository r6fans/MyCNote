#include<stdio.h>
#include<malloc.h>

/*0-1背包问题
给定n种物品和一个背包，物品i的重量是wi，价值为vi,背包容量是c
问如何选择装入背包的物品，使得装入的总价值最大

m(i,j)=max{m(i-1,j),m(i-1,j-wi)+vi}*/

#define N 5 // 物品种类
#define C 11 // 背包容量
int dp[N+1][C+1];       //dp[i][j] 表示考虑前i件物品，有j的背包容量
/**
  * @param weight 物品重量
  * @param value  物品价值
**/

void knapsack01(const int weight[], const int value[]){
    //遍历每件物品
    for(int i=1;i<=N;++i){
        //计算1-c各个容量的最大收益
        for(int j=1;j<=C;++j){
            //背包载重量<商品总重量，则不放
            if(j<weight[i]){
                dp[i][j]=dp[i-1][j];
            }else{
                //比较装入该商品与不装该商品哪种获得的收益最大，并记录该最大收益
                d[i][j]=max(dp[i-1][j],dp[i-1][j-weight[i]]+value[i]);
            }
        }
    }
}

