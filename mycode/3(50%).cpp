#include<queue>
#include<stdio.h>
#include<iostream>
#include<vector>
#include<string.h>
#include<map>
using namespace std;

int n,m,p,q;

char dp[20005][20005];

int main()
{
    memset(dp,0,sizeof(0));
    //cin>>n>>m>>p>>q;
    scanf("%d%d%d%d",&n,&m,&p,&q);
    vector<vector<int> > v(p,vector<int> (3));
    vector<vector<int> > qq(q,vector<int> (2));
    vector<vector<int> > houlim;
    vector<vector<int> > qianlim;
    vector<map<int,int> > tp(m+1);
    vector<map<int,int> > tp2;
    for(int i=0;i<p;i++)
    {
        //cin>>v[i][0]>>v[i][1]>>v[i][2];
        scanf("%d%d%d",&(v[i][0]),&(v[i][1]),&(v[i][2]));
    }
    for(int i=0;i<q;i++)
    {
        //cin>>qq[i][0]>>qq[i][1];
        scanf("%d%d",&(qq[i][0]),&(qq[i][1]));
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<p;j++)
        {
            if(v[j][0]==1&&v[j][1]==i)
            {
                vector<int> tmp;
                tmp.push_back(v[j][2]);
                for(int ii=j+1;ii<p;ii++)
                {
                    if(v[ii][1]==i&&v[ii][2]!=v[j][2])
                    {
                        tmp.push_back(v[ii][2]);
                        dp[v[ii][2]][v[j][2]]='b';
                        dp[v[j][2]][v[ii][2]]='a';
                    }
                }
                if(tmp.size()>1)
                {
                    houlim.push_back(tmp);
                }
                vector<int> tmp2;
                tmp2.push_back(v[j][2]);
                for(int ii=j-1;ii>=0;ii--)
                {
                    if(v[ii][1]==i&&v[ii][2]!=v[j][2])
                    {
                        tmp2.push_back(v[ii][2]);
                        dp[v[ii][2]][v[j][2]]='a';
                        dp[v[j][2]][v[ii][2]]='b';
                    }
                }
                if(tmp2.size()>1)
                {
                    qianlim.push_back(tmp2);
                }
            }
        }
    }
    for(int i=0;i<qianlim.size();i++)
    {
        for(int j=1;j<qianlim[i].size();j++)
        {
        //cout<<"tp"<<tp.size()<<" "<<qianlim[i][0]<<endl;
            if(tp[qianlim[i][0]].find(qianlim[i][j])==tp[qianlim[i][0]].end())
            {
                tp[qianlim[i][0]][qianlim[i][j]]++;
                //cout<<qianlim[i][0]<<"%%"<<qianlim[i][j]<<endl;
            }
        }
    }
    for(int i=0;i<houlim.size();i++)
    {
        for(int j=1;j<houlim[i].size();j++)
        {
         //cout<<"tp"<<tp.size()<<" "<<houlim[i][j]<<endl;
            if(tp[houlim[i][j]].find(houlim[i][0])==tp[houlim[i][j]].end())
            {
            //cout<<"@@@"<<endl;
                tp[houlim[i][j]][houlim[i][0]]++;
                //cout<<"%%$"<<endl;
                //cout<<houlim[i][j]<<"%%"<<houlim[i][0]<<endl;
            }
        }
    }
    tp2=tp;
    vector<int> ans1;
    int flag[100008];
    memset(flag,0,sizeof(flag));
    while(ans1.size()<m)
    {
//        for(int i=1;i<tp.size();i++)
//        {
//            cout<<i<<"**"<<tp[i].size()<<endl;
//        }
        for(int i=1;i<tp.size();i++)
        {
            if(flag[i]==0&&tp[i].empty())
            {
                //cout<<i<<endl;
                ans1.push_back(i);
                flag[i]=1;
                for(int j=0;j<tp.size();j++)
                {
                    map<int,int>::iterator t=tp[j].find(i);
                    if(t!=tp[j].end())
                    {
                        tp[j].erase(t);
                    }
                }
                //cout<<i<<"!!"<<endl;
                break;
            }
        }
    }
    //cout<<"&&&"<<endl;
    //cout<<ans1.size()<<endl;
    for(int i=0;i<ans1.size();i++)
    {
        //cout<<ans1[i]<<" ";
        printf("%d ",ans1[i]);
    }
    printf("\n");
    //cout<<endl;

    for(int i=0;i<q;i++)
    {
        tp=tp2;
        memset(flag,0,sizeof(flag));
        int ff=0;
        int left=qq[i][0];
        int right=qq[i][1];
        if(dp[left][right]!=0)
        {
            if(dp[left][right]=='a')
            {
                printf("%s\n","YES");
                //cout<<"YES"<<endl;
            }
            else
            {
                //cout<<"NO"<<endl;
                printf("%s\n","NO");
            }
            continue;
        }
        ///
        for(int i=1;i<=m;i++)
        {

        }
        queue<int> qu;
        //cout<<tp2[left].size()<<endl;
        for(map<int,int>::iterator mm=tp[left].begin();mm!=tp[left].end();mm++)
        {
            //cout<<mm->first<<"+++"<<endl;
            qu.push(mm->first);
            dp[mm->first][left]='a';
            dp[left][mm->first]='b';
        }
        while(!qu.empty())
        {
            int k=qu.front();
            qu.pop();
            if(k==right||dp[k][right]=='b')
            {
                //cout<<"NO"<<endl;
                printf("%s\n","NO");
                ff=1;
                break;
            }
            else
            {
                for(map<int,int>::iterator mm=tp[k].begin();mm!=tp[k].end();mm++)
                {
                    if(flag[mm->first]==0)
                    {
                        dp[k][mm->first]='b';
                        dp[mm->first][k]='a';
                        dp[left][mm->first]='b';
                        dp[mm->first][left]='a';
                        qu.push(mm->first);
                        //cout<<mm->first<<endl;
                        flag[mm->first]=1;
                    }
                }
            }
        }
        if(!ff)
        {
            //cout<<"YES"<<endl;
            printf("%s\n","YES");
        }
    }
    return 0;
}
