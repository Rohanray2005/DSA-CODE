#include <bits/stdc++.h>

using namespace std;

template <typename Type>
istream &operator>>(istream &in, vector<Type> &vec) {
    int n = vec.size();
    for (int i = 0; i < n; i++)
        in >> vec[i];
    return in;
}
template <typename Type>
ostream &operator<<(ostream &out, vector<Type> &vec) {
    for (auto val : vec)
        out << val << " ";
    return out;
}
void printdfs(int **edges,int n,int sv,bool*visit)
{
    cout<<sv<<"";
    visit[sv]=true;

    for(int i=0;i<n;i++)
    {
        if(i==sv)continue;
        if(edges[sv][i]==1)
        {
            if(visit[i]==true)
             continue;
            printdfs(edges,n,i,visit);
        }
    }
}

void printbfs(int **edges,int n,int sv,bool *visit)
{
    queue<int>q;
    q.push(sv);
    visit[sv]=true;
    while(!q.empty())
    {
        int curr=q.front();
        q.pop();
        cout<<curr<<"";
        for(int i=0;i<n;i++)
        {
            if(visit[i]==true)
            continue;
            if(edges[curr][i]==1 && !visit[i])
            {
                q.push(i);
                visit[i]=true;
            }
        }
    }

}

void dfs(int **edges,int n)
{
    bool *visit=new bool [n];
    for(int i=0;i<n;i++)
        visit[i]=false;
    for(int i=0;i<n;i++)
    {
        if(visit[i]==false)
        {
            printdfs(edges,n,i,visit);
        }
    }
    delete[]visit;
}

void bfs(int **edges,int n)
{
    bool *visit=new bool [n];
    for(int i=0;i<n;i++)
        visit[i]=false;
    for(int i=0;i<n;i++)
    {
        if(visit[i]==false)
        {
            printbfs(edges,n,i,visit);
        }
    }
    delete[]visit;
}
bool visit[1000];

bool haspath(int **edges,int n,int start,int end )
{
    int ans=false;
    visit[start]=true;
    for(int i=0;i<n;i++)
    {
        if(start==i)continue;
        if(edges[i][start]==1)
        {
            if(i==end)return true;
            if(visit[i]==true)continue;
            ans=ans|haspath(edges,n,i,end);
        }
    }
    return ans;
}

vector<int> getpath(int **edges,int n,int start,int end)
{
    vector<int>ans;
    visit[start]=true;
    ans.push_back(start);
    for(int i=0;i<n;i++)
    {
        if(start==i)continue;
        if(edges[i][start]==1)
        {
            if(i==end)
            {
                ans.push_back(i);
                return ans;
            }
            if(visit[i]==true)continue;
            vector<int>temp=getpath(edges,n,i,end);
            if(temp.size()!=0)
            {
                //temp.push_back(start);
                // int t=temp[temp.size()-1];
                // temp[temp.size()-1]=temp[temp.size()-2];
                // temp[temp.size()-2]=t;
                ans.insert(ans.end(), temp.begin(), temp.end());
                return ans;
            }
        }
    }
    vector<int>t;
    return t;

}

vector<int>getpath_bfs(int **edges,int n,int start,int end)
{
    vector<int>ans;
    map<int,int>m;
    queue<int>q;
    q.push(start);
    visit[start]=true;
    while(!q.empty())
    {
        int curr=q.front();
        q.pop();
        if(curr==end)
            break;
        for(int i=0;i<n;i++)
        {
            if(visit[i]==true)
            continue;
            if(edges[curr][i]==1 && !visit[i])
            {
                q.push(i);
                m[i]=curr;
                visit[i]=true;
            }
        }
    }
    ans.push_back(end);
    int x=m[end];
    ans.push_back(x);
    while(x!=0)
    {
        x=m[x];
        ans.push_back(x);
    }
    reverse(ans.begin(),ans.end());
    return ans;
}

bool isconnected(int **edges,int n,int sv)
{
    //cout<<sv<<"";
    visit[sv]=true;

    for(int i=0;i<n;i++)
    {
        if(i==sv)continue;
        if(edges[sv][i]==1)
        {
            if(visit[i]==true)
             continue;
            isconnected(edges,n,i);
        }
    }
    for(int i=0;i<n;i++)
    if(visit[i]==false)
    return false;
    return true;
}

void printallpath(int**edges,int n,bool visited[],int st,int en,string psf){
    if(st==en){
        cout<<psf<<"\n";
        return;
    }
    visited[st]=true;
    for(int i=0;i<n;i++){
        if(!visited[i] && edges[i][st]){
            printallpath(edges,n,visited,i,en,psf+to_string(i));
        }
    }
    visited[st]=false;
}
void helper(int **edges,int n,int sv,bool*visit,vector<int>&temp)
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

void getconnected(int **edges,int n,bool visited[],vector<vector<int>>&v){
    for(int i=0;i<n;i++){
        vector<int>temp;
        helper(edges,n,i,visited,temp);
        if(temp.size()>0)v.push_back(temp);
    }
}


int main()
{
    int n,e;
    cin>>n>>e;
    int **edges=new int* [n];
    for(int i=0;i<n;i++)
    {
        edges[i]=new int [n];
        for(int j=0;j<n;j++)
            edges[i][j]=0;
    }
    for(int i=0;i<e;i++)
    {
        int f,s,w;
        cin>>f>>s>>w;
        edges[f][s]=1;
        edges[s][f]=1;
    }
    bool visited[n];
    memset(visited,0,sizeof(visited));
    vector<vector<int>>v;
    getconnected(edges,n,visited,v);
    cout<<"[";
    for(int i=0;i<v.size();i++){
        cout<<"[";
        for(int j=0;j<v[i].size();j++){
            cout<<v[i][j];
            if(j!=v[i].size()-1)cout<<", ";
        }
        cout<<"]";
        if(i!=v.size()-1)cout<<", ";
    }
    cout<<"]";
}
