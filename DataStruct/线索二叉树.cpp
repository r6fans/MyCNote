// 线索二叉树
#include<stdio.h>
#include<malloc.h>
using namespace std;

typedef struct ThreadNode{
    ElementType data; //数据元素
    struct ThreadNode *lchild,*rchild; //左右孩子指针
    int ltag,rtag;  //左右线索标识
}ThreadNode,*ThreadTree;

//中序遍历线索化递归
void InThread(ThreadTree &p, ThreadTree &prd){
    if(p!=NULL){
        InThread(p->lchild,prd) // 递归，线索化左子树
        if(p->lchild == NULL){ // 左子树为空，建立前驱线索
            p->lchild=pre;
            p->ltag=1;
        }
        if(pre!=NULL&&pre->rchild==NULL){
            pre->rchild=p; // 建立前驱节点的后继
            pre->rtag=1;
        }
        pre=p;  //标记当前节点成为刚刚访问过的节点
        InThread(p->rchild,pre); //递归，线索化右子树
    }
}

//通过中序遍历构建中序线索二叉树
void CreateInThread(ThreadTree T){
    ThreadTree pre=NULL;
    if(T!=NULL){ //若二叉树不空，则进行线索化
        InThread(T,pre); //线索化二叉树T
        pre->rchild=NULL; //处理遍历的最后一个节点
        pre->rtag=1;
    }
}

/*中序线索二叉树的遍历
中序线索二叉树的节点中隐含了线索二叉树的前驱和后继信息。在遍历时，只需要先找到序列的第一个节点，然后依次找节点的后继，直到后继为空
*/

//求中序线索二叉树的第一个节点
ThreadNode *Firstnode(ThreadNode *p){
    while(p->ltag==0)
        p=p->lchild; //最左下节点不一定是叶节点
    return p;
}

//求中序线索二叉树中节点p在中序序列下的后继
ThreadNode *Nextnode(ThreadNode *p){
    if(p->rtag==0)
        return Firstnode(p->rchild);
    else
        return p->rchild; //rtag==1直接返回后继线索
}