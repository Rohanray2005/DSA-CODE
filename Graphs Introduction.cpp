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
    cout<<sv<<"\n";
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
        cout<<curr<<"\n";
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
        int f,s;
        cin>>f>>s;
        edges[f][s]=1;
        edges[s][f]=1;
    }
    /*
    dfs(edges,n);
    cout<<"\n\n";
    bfs(edges,n);
    */
    cout<<"\nEnter start and end\n";
    int start,end;
    cin>>start>>end;
    memset(visit,false,sizeof(visit));
    vector<int>v=getpath(edges,n,start,end);
    cout<<v;
    return 0;
}
