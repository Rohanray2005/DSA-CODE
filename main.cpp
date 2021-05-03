#include <bits/stdc++.h>
#include<climits>
using namespace std;

int frog2(int n,int *arr,int k)
{
    int dp[n];
    dp[n-1]=0,dp[n-2]=abs(arr[n-1]-arr[n-2]);
    for(int i=n-3;i>=0;i--)
        dp[i]=INT_MAX;
    for(int i=n-3;i>=0;i--)
    {
        for(int j=1;j<=k && j+i<n;j++)
        {
             dp[i]=min(dp[i+j]+abs(arr[i+j]-arr[i]),dp[i]);
        }
    }
    return dp[0];
}


/*
int frog2(int n,int *arr,int k)
{
   int dp[n];
    dp[0]=0;
   for(int i=1;i<n;i++)
    dp[i]=INT_MAX;
   for(int i=1;i<n;i++)
   {
       for(int j=1;j<=k;j++)
       {
           if(i-j<0)
            break;
           dp[i]=min(dp[i],dp[i-j]+abs(arr[i]-arr[i-j]));
       }
   }
   return dp[n-1];
}
*/
int vacations()
{
    int n;
   cin>>n;
   vector<vector<int>>v(n,vector<int>(3));
   for(int i=0;i<n;i++)
   {
        for(int j=0;j<3;j++)
            cin>>v[i][j];
   }
   int dp[n][3];
   for(int i=0;i<3;i++)
   {
       dp[0][i]=v[0][i];
   }
   for(int i=1;i<n;i++)
   {
       dp[i][0]=v[i][0]+max(dp[i-1][1],dp[i-1][2]);
       dp[i][1]=v[i][1]+max(dp[i-1][0],dp[i-1][2]);
       dp[i][2]=v[i][2]+max(dp[i-1][0],dp[i-1][1]);
   }
   int ans=max(dp[n-1][0],max(dp[n-1][1],dp[n-1][2]));
   return ans;
}
#define int long long

int Knapack1()
{
    int n,W;
    cin>>n>>W;
    int w[n];
    int v[n];
    for(int i=0;i<n;i++)
    {
        cin>>w[i]>>v[i];
    }
    int dp[n+1][W+1];
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=W;j++)
        {
            if(i==0||j==0)
                dp[i][j]=0;
            else if(w[i-1]<=j)
            {
                dp[i][j]=max(v[i-1]+dp[i-1][j-w[i-1]],dp[i-1][j]);
            }
            else
                dp[i][j]=dp[i-1][j];
        }
    }
    return dp[n][W];
}
void lcs_print()
{
    string s,t;
    cin>>s>>t;
    int n=s.size();
    int m=t.size();
    vector<vector<int>>dp(n+1,vector<int>(m+1,0));
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(s[i-1]==t[j-1])
            {
                dp[i][j]=1+dp[i-1][j-1];
            }
            else
            {
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }
    int ans=dp[n][m];
    string str(ans,' ');
    int i=n,j=m;
    while(i>0 && j>0)
    {
        if(s[i-1]==t[j-1])
        {
            str[ans-1]=s[i-1];
            i--;
            j--;
            ans--;
        }
        else if(dp[i-1][j]>dp[i][j-1])
        {
            i--;
        }
        else
        {
            j--;
        }
    }
    cout<<str;
}
int M = 1000000007;

int Grid()
{
    int h,w;
    cin>>h>>w;
    vector<vector<char>>arr(h,vector<char>(w));
    for(int i=0;i<h;i++)
    {
        for(int j=0;j<w;j++)
            cin>>arr[i][j];
    }
    vector<vector<int>>dp(h,vector<int>(w));// dp array
    dp[h-1][w-1]=0;
    int flag=1;
    for(int i=h-2;i>=0;i--)
    {
        if(arr[i][w-1]=='#')
        {
            dp[i][w-1]=0;
            flag=0;
        }
        else if(arr[i][w-1]=='.' && flag==1)
            dp[i][w-1]=1;
        else
            dp[i][w-1]=0;
    }
    flag=1;
    for(int i=w-2;i>=0;i--)
    {
        if(arr[h-1][i]=='#')
        {
            dp[h-1][i]=0;
            flag=0;
        }
        else if(arr[h-1][i]=='.' && flag==1)
            dp[h-1][i]=1;
        else
            dp[h-1][i]=0;
    }
    for(int i=h-2;i>=0;i--)
    {
        for(int j=w-2;j>=0;j--)
        {
            if(arr[i][j]=='#')
                dp[i][j]=0;
            else
             dp[i][j]=((dp[i+1][j])%M+(dp[i][j+1])%M)%M;
        }
    }
    cout<<dp[0][0];
}

double dp[3000][3000];

double Coins(vector<double>arr,int i,int x)
{
    if(x==0)return 1;
    if(i==0)return 0;

    if(dp[i][x]>-0.9)
        return dp[i][x];

     dp[i][x]=arr[i]*Coins(arr,i-1,x-1)+(1-arr[i])*Coins(arr,i-1,x);
     return dp[i][x];
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    vector<double>arr(n+1);
    memset(dp,-1,sizeof(dp));
    for(int i=1;i<=n;i++)
        cin>>arr[i];
    printf("%0.10f",Coins(arr,n,(n+1)/2));
    return 0;
}
