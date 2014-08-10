#include <iostream>
#include <stdio.h>
using namespace std;

int UFS_NUM;    //���鼯��Ԫ������
typedef struct node{
    int data;    //�ڵ��Ӧ�ı��
    int rank;    //�ڵ��Ӧ��
    int parent;    //�ڵ��Ӧ��˫���±�
}UFSTree;        //���鼯���Ľڵ�����
void MAKE_SET(UFSTree t[])    //��ʼ�����鼯��
{
    int i;
    for(i=1;i<=UFS_NUM;i++){
        t[i].data = i;        //����Ϊ�õ���
        t[i].rank = 0;        //�ȳ�ʼ��Ϊ0
        t[i].parent = i;    //˫�׳�ʼ��Ϊָ���Լ�
    }
}
int FIND_SET(UFSTree t[],int x)    //��x���ڵ������в��Ҽ��ϱ��
{
    if(t[x].parent == x)    //˫�����Լ�
        return x;    //˫�����Լ������� x
    else    //˫�ײ����Լ�
        return FIND_SET(t,t[x].parent);    //�ݹ���˫���в���x
}
void UNION(UFSTree t[],int x,int y)    //��x��y���ڵ������ϲ�
{
    x = FIND_SET(t,x);    //���� x ���ڷ��뼯�����ı��
    y = FIND_SET(t,y);    //���� y ���ڷ��뼯�����ı��
    if(t[x].rank > t[y].rank)    //y �ڵ����С�� x�ڵ����
        t[y].parent = x;        //�� y ���ӵ� x �ڵ��ϣ�x ��Ϊ y ��˫�׽ڵ�
    else{                //y �ڵ���ȴ��ڵ��� x �ڵ����
        t[x].parent = y;            //�� x ���ӵ� y �ڵ��ϣ�y ��Ϊ x ��˫�׽ڵ�
        if(t[x].rank==t[y].rank)    //x �� y��˫�׽ڵ�����ͬ
            t[y].rank++;            //y �ڵ������ 1
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
