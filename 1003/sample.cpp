#include <iostream>
#include <stdio.h>
using namespace std;

int UFS_NUM;    //并查集中元素总数
typedef struct node{
    int data;    //节点对应的编号
    int rank;    //节点对应秩
    int parent;    //节点对应的双亲下标
}UFSTree;        //并查集树的节点类型
void MAKE_SET(UFSTree t[])    //初始化并查集树
{
    int i;
    for(i=1;i<=UFS_NUM;i++){
        t[i].data = i;        //数据为该点编号
        t[i].rank = 0;        //秩初始化为0
        t[i].parent = i;    //双亲初始化为指向自己
    }
}
int FIND_SET(UFSTree t[],int x)    //在x所在的子树中查找集合编号
{
    if(t[x].parent == x)    //双亲是自己
        return x;    //双亲是自己，返回 x
    else    //双亲不是自己
        return FIND_SET(t,t[x].parent);    //递归在双亲中查找x
}
void UNION(UFSTree t[],int x,int y)    //将x和y所在的子树合并
{
    x = FIND_SET(t,x);    //查找 x 所在分离集合树的编号
    y = FIND_SET(t,y);    //查找 y 所在分离集合树的编号
    if(t[x].rank > t[y].rank)    //y 节点的秩小于 x节点的秩
        t[y].parent = x;        //将 y 连接到 x 节点上，x 作为 y 的双亲节点
    else{                //y 节点的秩大于等于 x 节点的秩
        t[x].parent = y;            //将 x 连接到 y 节点上，y 作为 x 的双亲节点
        if(t[x].rank==t[y].rank)    //x 和 y的双亲节点秩相同
            t[y].rank++;            //y 节点的秩增 1
    }
}
int main()
{
    freopen("in.in", "r", stdin);
    int N,M;
    UFS_NUM=1000;
    UFSTree u[1001];
    while(cin>>N){
        if(N==0) break;
        cin>>M;
        MAKE_SET(u);
        for(int i=1;i<=M;i++){
            int x,y;
            cin>>x>>y;
            UNION(u,x,y);
        }
        int count = 0;
        for(int i=1;i<=N;i++)
            if(FIND_SET(u,i)==i)
                count++;
        cout<<count-1<<endl;
    }
    return 0;
}
