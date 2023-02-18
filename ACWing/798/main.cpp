//AC
#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,m,q;
    cin>>n>>m>>q;
    int mat[n+1][m+1]={0};
    int b[n+1][m+1]={0};
    //formula: mat[i][j]=mat[i-1][j]+mat[i][j-1]-mat[i-1][j-1]+b[i][j];
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            cin>>mat[i][j];
        }
    }
    for(int i=0;i<=n;i++)
    {
        mat[i][0]=0;
    }
    for(int j=0;j<=m;j++)
    {
        mat[0][j]=0;
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            b[i][j]=mat[i][j]-mat[i-1][j]-mat[i][j-1]+mat[i-1][j-1];
        }
    }
    int x1,y1,x2,y2,c;
    while(q--)
    {
        cin>>x1>>y1>>x2>>y2>>c;

        b[x1][y1]+=c;
        if(x2+1<=n && y2+1<=m)
            b[x2+1][y2+1]-=c;

        if(y2+1<=m)
            b[x1][y2+1]-=c;
        if(x2+1<=n && y2+1<=m)
            b[x2+1][y2+1]+=c;

        if(x2+1<=n)    
            b[x2+1][y1]-=c;
        if(x2+1<=n && y2+1<=m)
            b[x2+1][y2+1]+=c;    
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            mat[i][j]=b[i][j]+mat[i-1][j]+mat[i][j-1]-mat[i-1][j-1];
            cout<<mat[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}