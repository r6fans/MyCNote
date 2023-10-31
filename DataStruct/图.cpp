#include<stdio.h>
#include<stdlib.h>
#define MAXN 100
#define MAX_VERTEX_NUM 100 //顶点的最大值
int G[MAXN][MAXN],Nv,Ne;

//图的邻接矩阵存储
typedef char VertexType; //顶点的数据类型
typedef int EdgeType;  //带权图中边上权值的数据结构
typedef struct {
    VertexType Vex[MAX_VERTEX_NUM]; //顶点表
    EdgeType Edge[MAX_VERTEX_NUM][MAX_VERTEX_NUM]; //邻接矩阵，边表
    int vexnum,arcnum;  //图的当前顶点数
};

//广度优先遍历
bool visited[MAX_VERTEX_NUM];       //访问标记数组
void BFSTraverse(Graph G){          //对图G进行广度优先遍历
    for(i=0;i<G.vexnum; ++i){
        visited[i]=FALSE;           //访问标记数组初始化
    }
    InitQueue(Q);                   //初始化辅助队列Q
    for(i=0;i<G.vexnum){            //从0号顶点开始遍历
            if(!visited[i]){        //对每个连通分量调用一次BFS
            BFS(G,i);               //vi未被访问过，从vi开始
        }
    }
}

void BFS(Graph G,int v){            //从顶点v出发，广度优先遍历图G
    visit(v);                       //访问初始顶点v
    visited[v]=TRUE;                //对v做已访问标记
    Enqueue(Q,v);                   //顶点v入队
    while(!IsEmpty(Q)){             
        DeQueue(Q,v);               //顶点v出队
        for(w=FirstNeighbor(G,v);w>=0;w=NeNighbor(G,v,w)){
                                    //检测v所有邻接点
            if(!visited[w]){        //w为v尚未访问的邻接节点
                visit(W);           //访问顶点w
                visited[w]=TRUE;    //对w做已访问标记
                Enqueue(Q,w);       //顶点w入队
            }
        }
    }
}

/*深度优先遍历*/
void DFSTraverse(Graph G){          //对图G进行深度优先遍历
    for(v=0;v=G.vexnum;++v){
        visited[v]=FALSE;           //初始化已访问标记数组
    }
    for(v=0;v<G.vexnum;++v){        //从v=0开始遍历
        if(!visited[v]){
            DFS(G,v);
        }
    }
}

void DFS(Graph G,int v){            //从顶点v出发，深度优先遍历图G
    visit(v);                       //访问顶点v
    visited[v]=TRUE;                //设已访问标记
    for(w=FirstNeighbor(G,v);w>=0;w=NextNeighbor(G,v,w)){
        if(!visited[w]){            //w为v的尚未访问的邻接顶点
            DFS(G,w);
        }
    }
}
