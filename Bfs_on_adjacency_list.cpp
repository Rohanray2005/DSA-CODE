class Pair{
    public:
    int v;
    string psf;
    Pair(int v,string psf){
        this->v=v;
        this->psf=psf;
    }
};
void bfsnew(map<int,vector<int>>edges,int n,int src){
    queue<Pair>q;
    Pair p(src,to_string(src));
    q.push(p);
    vector<bool>visit(n,false);
    while(!q.empty()){
        Pair rem=q.front();
        q.pop();
        if(visit[rem.v]==true)continue;
        visit[rem.v]=true;
        
        cout<<rem.v<<"@"<<rem.psf<<"\n";
        
        for(int i=0;i<edges[rem.v].size();i++){
            if(visit[edges[rem.v][i]]==false)
            {
                Pair p(edges[rem.v][i],rem.psf+to_string(edges[rem.v][i]));       
                q.push(p);
            }
        }
    }
}


int main()
{
    int n,e;
    cin>>n>>e;
    map<int,vector<int>>edges;
    for(int i=0;i<e;i++)
    {
        int f,s,w;
        cin>>f>>s>>w;
        edges[f].push_back(s);
        edges[s].push_back(f);
    }
    int st;
    cin>>st;
    bfsnew(edges,n,st);
}
