#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;
int p[101];
int t[101];
int start_earliest[101];
int start_lastest[101];
int end_earliest[101];
int end_lastest[101];
int n,m;

bool test()
{
    bool success = true;
    cin>>n>>m;
    unordered_map<int,int> pre;
    unordered_map<int,int> post;
    for(int i=1;i<=m;i++)
    {
        cin>>p[i];
        pre[i]=p[i];
        if(p[i]!=0)post[p[i]]=i;
    }
    for(int i=1;i<=m;i++)
    {
        cin>>t[i];
    }
    /*
    *遍历找到入度为0的科目，入队
    *某个活动的最早开始时间=各前驱（最早结束时间+1）的最大（晚）值
    *某个活动的最早结束时间=其最早开始时间+该活动耗时-1
    *某个活动的最晚结束时间=各后继（最晚开始时间-1）的最小值
    *某个活动的最晚开始时间=其最晚结束时间-该活动耗时+1
    *总结：最早开始时间受限，最早结束时间可由最早开始时间直接求得
    *     最晚结束时间受限，最晚开始时间可由最晚结束时间直接求得
    *算法：给定入度为0结点（起始）的最早开始时间和出度为0结点（结束）的最晚结束时间
    *     经扩散得到所有需要的时间
    */
    for(int i=1;i<=m;i++)
    {
        //如果一个i点没有前驱，则给定初值
        if(p[i]==0)
        {
            start_earliest[i]=1;
            end_earliest[i] = start_earliest[i] + t[i]-1;
        }
        //如果一个i点没有后继，则给定初值
        if(post[i]==0)
        {
            end_lastest[i]=n;
            start_lastest[i]=end_lastest[i]-t[i]+1;
        }
    }
    for(int i=1;i<=m;i++)
    {
        if(p[i]!=0)
        {
            start_earliest[i] = end_earliest[p[i]]+1;
            end_earliest[i] = start_earliest[i] + t[i]-1;
        }
        if(post[i]!=0)
        {
            end_lastest[i] = start_lastest[post[i]]-1;
            start_lastest[i]=end_lastest[i]-t[i]+1;
        }
        if(end_earliest[i]>n)
        {
            success = false;
        }
    }
    if(success)
    {
        return true;
    }
    else
    {
        return false;
    }
}
int main()
{
    if(test())
    {
        for(int i=1;i<=m;i++)
        {
            cout<<start_earliest[i]<<" ";
        }
        cout<<endl;
        for(int i=1;i<=m;i++)
        {
            cout<<start_lastest[i]<<" ";
        }
    }
    else
    {
        for(int i=1;i<=m;i++)
        {
            cout<<start_earliest[i]<<" ";
        }
    }
    return 0;
}