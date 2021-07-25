#include<bits/stdc++.h>

using namespace std;
const int mod = 1e9+7;
const int size=1e3;
int arr[size][size];

void Rat_in_maze(int i,int j,int n,int m,vector<vector<bool>>visit){
	if(i<0 || j<0 || i>=n || j>=m )return;
	if(arr[i][j]==0 || visit[i][j]==true)return;
	if(i==n-1 && j==m-1){	
		visit[i][j]=true;	
		for(int k=0;k<n;k++){
			for(int p=0;p<m;p++){
				cout<<visit[k][p]<<" ";
			}
			cout<<"\n";
		}
		cout<<"\n";
		return;
	}
	visit[i][j]=true;
	Rat_in_maze(i-1,j,n,m,visit);
	Rat_in_maze(i+1,j,n,m,visit);
	Rat_in_maze(i,j-1,n,m,visit);
	Rat_in_maze(i,j+1,n,m,visit);
	visit[i][j]=false;
}	
int main()
{   
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif 
    int n,m;
    cin>>n>>m;
    for(int i=0;i<n;i++){
    	for(int j=0;j<m;j++){
    		cin>>arr[i][j];
    	}
    }
    vector<vector<bool>>visit(n,vector<bool>(m,0));
    Rat_in_maze(0,0,n,m,visit);
 }
