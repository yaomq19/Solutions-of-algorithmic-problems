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
    *�����ҵ����Ϊ0�Ŀ�Ŀ�����
    *ĳ��������翪ʼʱ��=��ǰ�����������ʱ��+1���������ֵ
    *ĳ������������ʱ��=�����翪ʼʱ��+�û��ʱ-1
    *ĳ������������ʱ��=����̣�����ʼʱ��-1������Сֵ
    *ĳ���������ʼʱ��=���������ʱ��-�û��ʱ+1
    *�ܽ᣺���翪ʼʱ�����ޣ��������ʱ��������翪ʼʱ��ֱ�����
    *     �������ʱ�����ޣ�����ʼʱ������������ʱ��ֱ�����
    *�㷨���������Ϊ0��㣨��ʼ�������翪ʼʱ��ͳ���Ϊ0��㣨���������������ʱ��
    *     ����ɢ�õ�������Ҫ��ʱ��
    */
    for(int i=1;i<=m;i++)
    {
        //���һ��i��û��ǰ�����������ֵ
        if(p[i]==0)
        {
            start_earliest[i]=1;
            end_earliest[i] = start_earliest[i] + t[i]-1;
        }
        //���һ��i��û�к�̣��������ֵ
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