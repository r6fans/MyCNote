#include<stdio.h>

/*0-1背包回溯法  子集树
给定n种物品和一个背包，物品i的重量是wi,价值为vi,背包容量是c
问如何选择装入背包的物品，使得装入的总价值最大*/

int n,c; //物品数,背包容量 
float *w,*p, //物品重量数组，物品价值数组
cW,         // 当前重量
cP,         //当前价值
bextP;      //最优价值


//分支界限函数，右孩子的最大值
int bound(int i){
    int cRight = c - cW; //背包剩余容量
    int tempcP = cP;     //临时当前价值变量
    //以物品单位重量价值降序，依次装入物品
    while(i <= n && w[i]<=cRight){
        cRight -= w[i];
        tempcP += p[i];
        ++i;
    }
    // 以当前单位价值装满剩余的背包
    //贪心思想 -- 完全装不下后割掉部分装入
    if(i<=n) 
}
