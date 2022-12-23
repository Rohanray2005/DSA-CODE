#include<bits/stdc++.h>

using namespace std;

vector<int>adj[100005];

vector<int>vis(1e5+6,0);
vector<int>dp(1e5+5);

void dfs(int n){
	vis[n]=1;
	dp[n]=0;
	for(auto i:adj[n]){
		if(!vis[i]){
			dfs(i);
		}
		dp[n]=max(dp[n],dp[i]+1);
	}
}

int main(){
	int n,m;
	cin>>n>>m;
	for(int i=0;i<m;i++){
		int x,y;
		cin>>x>>y;
		adj[x].push_back(y);
	}
	int ans=0;
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			dfs(i);
		}
	}
	for(int i=1;i<=n;i++){
		ans=max(ans,dp[i]);
	}
	cout<<ans;
}