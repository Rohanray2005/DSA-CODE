void printallpath(int **edges,int n,map<int,int>&v,int src,int osrc,string psf){
    
    if(v.size()==n-1){
        cout<<psf;
        int j=psf[psf.size()-1]-'0';
        if(edges[osrc][j])cout<<"*\n";
        else cout<<".\n";
        return;
    }
    v[src]++;
    for(int i=0;i<n;i++){
        if(i==src)continue;
        if(edges[src][i]==1 && v.count(i)==0)
        {
           printallpath(edges,n,v,i,osrc,psf+to_string(i));
        }
    }
    v.erase(src);
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
    int src;
    cin>>src;
    map<int,int>visit;
    string psf=to_string(src);
    printallpath(edges,n,visit,src,src,psf);
}
