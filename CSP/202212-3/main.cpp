#include<bits/stdc++.h>
using namespace std;
int Q[8][8];
int M[8][8];
double M_[8][8];
int command;
double alpha(int u)
{
    if(u==0)return sqrt(0.5f);
    else return 1.f;
}
void fillQ()
{
    for(int i=0;i<8;i++)
    {
        for(int j=0;j<8;j++)
        {
            cin>>Q[i][j];
        }
    }
}
void fillM()
{
    int n;
    cin>>n>>command;
    //i+j在每一层都是常数sum[k]，只是如何分配的问题
    //sum总共15层
    int sum[15]={
        0,1,2,3,4,5,6,7,8,9,10,11,12,13,14
    };
    int count=0;
    for(int k=0;k<15;k++)
    {
        for(int i=0;i<=sum[k];i++)
        {
            int j = sum[k]-i;
            if(k%2 != 0){
                cin>>M[i][j];
                n--;
            }
            else{
                cin>>M[j][i];
                n--;
            }
            if(n==0)return;
        }
    }
}
void QmultiM()
{
    for(int i=0;i<8;i++)
    {
        for(int j=0;j<8;j++)
        {
            M[i][j]*=Q[i][j];
        }
    }
}
void lisan()
{
    double pi = (double)acos(-1);
    for(int i=0;i<8;i++)
    {
        for(int j=0;j<8;j++)
        {
            double sum = 0.f;
            for(int u=0;u<8;u++)
            {
                for(int v=0;v<8;v++)
                {
                    sum+=(M[u][v]*
                    alpha(u)*alpha(v)*
                    cos(pi/8*u*(i+0.5))*
                    cos(pi/8*v*(j+0.5)));
                }
            }
            M_[i][j] = sum*0.25f;
        }
    }
}
void final()
{
    for(int i=0;i<8;i++)
    {
        for(int j=0;j<8;j++)
        {
            M_[i][j]+=128.f;
            double mid = floor(M_[i][j]) + 0.5f;
            if(M_[i][j]<mid)
            {
                M_[i][j]=floor(M_[i][j]);
            }
            else
            {
                M_[i][j]=floor(M_[i][j])+1;
            }
            if(M_[i][j]<0)M_[i][j]=0;
            else if(M_[i][j]>255)M_[i][j]=255;
        }
    }
    for(int i=0;i<8;i++)
    {
        for(int j=0;j<8;j++)
        {
            M[i][j]=(int)M_[i][j];
        }
    }
}
int main()
{
    fillQ();
    fillM();
    if(command==0){
        ;
    }else if(command==1){
        QmultiM();
    }else{
        QmultiM();
        lisan();
        final();
    }
    for(int i=0;i<8;i++)
    {
        for(int j=0;j<8;j++)
        {
            cout<<M[i][j]<<" ";
        }
        if(i<7)cout<<endl;
    }
    return 0;
}