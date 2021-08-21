#include<bits/stdc++.h>
#include<vector>
using namespace std;

bool isBarpetite(vector<vector<int>>edges,int n,int src){
    int color[n];
    for (int i = 0; i < n; ++i)
        color[i] = -1;
    color[src] = 0;
    queue <int> q;
    q.push(src);
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        if (edges[u][u] == 1)
        return false;
        for (int v = 0; v < n; ++v)
        {
            if (edges[u][v] && color[v] == -1)
            {
                color[v] = 1 - color[u];
                q.push(v);
            }
            else if (edges[u][v] && color[v] == color[u])
                return false;
        }
    }
    return true;
} 
void helper(vector<vector<int>>edges,int n,int sv,vector<bool>&visit,vector<int>&temp)
{   
    if(visit[sv]==true)return;
    temp.push_back(sv);
    visit[sv]=true;    
    for(int i=0;i<n;i++)
    {
        if(i==sv)continue;
        if(edges[sv][i]==1 && !visit[i])
        {
            helper(edges,n,i,visit,temp);
        }
    }
}

void getconnected(vector<vector<int>>edges,int n,vector<bool>&visited,vector<vector<int>>&v){
    for(int i=0;i<n;i++){
        vector<int>temp;
        helper(edges,n,i,visited,temp);
        if(temp.size()>0)v.push_back(temp);
    }
}
bool modified_dfs(vector<vector<int>>edges,int n,int sv,int parent,vector<bool>&visited){
    visited[sv]=true;
    for(int i=0;i<n;i++){
        if(visited[i]==true && edges[sv][i]>0 && parent==sv)return true;
        if(visited[i]==false && edges[sv][i]){
            return modified_dfs(edges,n,i,sv,visited);
        }
    }
    return false;
}

bool iscycle(vector<vector<int>>edges,int n){
    vector<bool>visited(n,false);
    int ans=true;
    for(int i=0;i<n;i++){
        if(visited[i]==false)
        ans&=modified_dfs(edges,n,i,-1,visited);
    }
    return ans;
}

int main()
{   
    int n;
    cin>>n;//Taking input of no. of nodes
    vector<vector<int>>edges(n,vector<int>(n));//2-d matrix
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>edges[i][j];
        }
    }
    vector<vector<int>>components;
    if(isBarpetite(edges,n,0)){
    	cout<<"Graph is Barpetite\n";
    }
    else{
    	cout<<"Graph is not Barpetite\n";	
    }
    vector<bool>visited(n,false);
    getconnected(edges,n,visited,components);
    if(components.size()==1)cout<<"Connected\n";
    else{
    	cout<<"Not Connected\n";
        for(int i=0;i<components.size();i++){
            cout<<"  ";
            for(int j=0;j<components[i].size();j++)
            cout<<components[i][j]<<" ";
            cout<<"\n";
            for(int j=0;j<components[i].size();j++)
            {
                cout<<components[i][j]<<" ";
                for(int k=0;k<components[i].size();k++){
                    if(edges[components[i][j]][components[i][k]])
                        cout<<"1 ";
                    else
                        cout<<"0 ";
                }
                cout<<"\n";
            }
            cout<<"\n";
        }	
    }
    if(components.size()>1){
        cout<<"Graph is not a tree\n";//Graph is disconnected therefore not a tree
    }
    else{
        if(iscycle(edges,n))cout<<"Graph is not a tree\n";
        else cout<<"Graph is a tree\n";
    }
    return 0;
}