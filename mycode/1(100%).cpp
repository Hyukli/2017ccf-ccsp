#include<iostream>
#include<vector>
#include<algorithm>
#include<stdlib.h>
#include<map>
#include<stack>
#include<queue>
#include<string.h>
#include<string>
#include<limits.h>
using namespace std;

int n;
int ans=0;
char a[50][50];
map<int,int> m;

int dfs(int i,int j)
{
    int d1,d2,l1,l2,k1,k2,m1,m2;
    for(d1=0; d1<50; d1++)
    {
        if(i+d1>=n||a[i+d1][j]!='w')
        {
            break;
        }
    }
    d1--;
    for(d2=0; d2>-50; d2--)
    {
        if(i+d2<0||a[i+d2][j]!='w')
        {
            break;
        }
    }
    d2++;
    if(d1-d2>=4)
    {
        int tmp=i+d1+j*100+(i+d2)*10000+j*1000000;
        if(m.find(tmp)==m.end())
        {
            m[tmp]++;
            ans++;
        }
    }
    ///
    for(l1=0; l1<50; l1++)
    {
        if(j+l1>=n||a[i][j+l1]!='w')
        {
            break;
        }
    }
    l1--;
    for(l2=0; l2>-50; l2--)
    {
        if(j+l2<0||a[i][j+l2]!='w')
        {
            break;
        }
    }
    l2++;
    if(l1-l2>=4)
    {
        int tmp=i+(j+l1)*100+i*10000+(j+l2)*1000000;
        if(m.find(tmp)==m.end())
        {
            m[tmp]++;
            ans++;
        }
    }
    ///
    for(k1=0; k1<50; k1++)
    {
        if(i-k1<0||j+k1>=n||a[i-k1][j+k1]!='w')
        {
            break;
        }
    }
    k1--;
    for(k2=0; k2>-50; k2--)
    {
        if(i-k2>=n||j+k2<0||a[i-k2][j+k2]!='w')
        {
            break;
        }
    }
    k2++;
    if(k1-k2>=4)
    {
        int tmp=i-k1+(j+k1)*100+(i-k2)*10000+(j+k2)*1000000;
        if(m.find(tmp)==m.end())
        {
            m[tmp]++;
            ans++;
        }
    }
    ///
    for(m1=0; m1<50; m1++)
    {
        if(i-m1<0||j-m1<0||a[i-m1][j-m1]!='w')
        {
            break;
        }
    }
    m1--;
    for(m2=0; m2>-50; m2--)
    {
        if(i-m2>=n||j-m2<0||a[i-m2][j-m2]!='w')
        {
            break;
        }
    }
    m2++;
    if(m1-m2>=4)
    {
        int tmp=i-m1+(j-m1)*100+(i-m2)*10000+(j-m2)*1000000;
        if(m.find(tmp)==m.end())
        {
            m[tmp]++;
            ans++;
        }
    }
    return 0;
}

int main()
{
    cin>>n;
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            cin>>a[i][j];
        }
    }
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            if(a[i][j]=='w')
            {
                dfs(i,j);
            }
        }
    }
    //cout<<"!!!"<<endl;
    int a2=ans;
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            if(a[i][j]=='*')
            {
                ans=0;
                m.clear();
                a[i][j]='w';
                for(int ii=0; ii<n; ii++)
                {
                    for(int jj=0; jj<n; jj++)
                    {
                        if(a[ii][jj]=='w')
                        {
                            dfs(ii,jj);
                        }
                    }
                }
                if(ans>a2)
                {
                    cout<<j<<" "<<i<<endl;
                }
                a[i][j]='*';
            }
        }
    }
    return 0;
}
