#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    double i;
    int data[51];
    scanf("%d %lf",&n,&i);
    for(int j=0;j<n+1;j++)
    {
        scanf("%d",&data[j]);
    }
    double sum = data[0];
    for(int k=1;k<n+1;k++)
    {
        sum += data[k]*pow((1.f+i),-1*k);
    }
    printf("%.3f",sum);
    return 0;
}