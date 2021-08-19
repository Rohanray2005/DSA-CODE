#include<bits/stdc++.h>
#include<vector>
using namespace std;

bool isBarpetite(vector<vector<int>>edges,int n){
	vector<bool>visited(n,false);
	queue<int>q;
	int flag=1;
	map<int,int>m1,m2;
	for(int i=0;i<n;i++){
		if(visited[i])continue;
		q.push(i);
		while(!q.empty()){
			int x=q.front();
			q.pop();
			visited[x]=true; 
			if(flag){
	        	flag=0;
	        	if(m1.find(x)!=m1.end())return false;
	        	m1[x]++;
	    	}
	        else{
	            flag=1;
	            if(m2.find(x)!=m2.end())return false;
	            m2[x]++;
	        }
	        for(int j=0;j<n;j++){
	            if(visited[j]==false && edges[x][j]>0)
	            q.push(j);
	        }
		}
	}
	for(auto it:m1){
		if(m2[it.first]>0)return false;
	}
    return true;
} 

int main()
{   
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif  
    int n,e;
    cin>>n>>e;//Taking input of no. of nodes and edges
    vector<vector<int>>edges(n,vector<int>(n));//2-d matrix
    //Taking inputs of 
    for(int i=0;i<e;i++){
    	int f,s;
    	cin>>f>>s;
    	edges[f][s]=1;
    	edges[s][f]=1;
    }
    if(isBarpetite(edges,n)){
    	cout<<"Graph is Barpetite\n";
    }
    else{
    	cout<<"Graph is not Barpetite\n";	
    }
    return 0;
}