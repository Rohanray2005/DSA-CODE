#include<bits/stdc++.h>

using namespace std;
const int mod = 1e9+7;

int findminvertex(int distance[],bool visited[],int n){
	int minVertex=-1;

	for(int i=0;i<n;i++){
		if(!visited[i] && (minVertex==-1||distance[i]<distance[minVertex])){
			minVertex=i;
		}
	}
	return minVertex;
}

void Dijkstra(int **edges,int n){
	int distance[n];
	bool visited[n];
	for(int i=0;i<n;i++){
		distance[i]=INT_MAX;
		visited[i]=false;
	}
	distance[0]=0;

	for(int i=0;i<n-1;i++){
		int minVertex=findminvertex(distance,visited,n);
		visited[minVertex]=true;
		for(int j=0;j<n;j++){
			if(edges[minVertex][j]!=0 && !visited[j]){
				int dis=distance[minVertex]+edges[minVertex][j];
				if(dis<distance[j]){
					distance[j]=dis;
				}
			}
		}
	}
	for(int i=0;i<n;i++){
		cout<<i<<" "<<distance[i]<<"\n";
	}	

}

int main()
{   
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif 
    int n,e;
    cin>>n>>e;

    int**edge=new int *[n];
    for(int i=0;i<n;i++){
    	edge[i]=new int[n];
    	for(int j=0;j<n;j++){
    		edge[i][j]=0;
    	}
    }

    for(int i=0;i<e;i++){
    	int f,s,w;
    	cin>>f>>s>>w;
    	edge[f][s]=w;
    	edge[s][f]=w;
    }
    cout<<"\n";
    Dijkstra(edge,n);
    for(int i=0;i<n;i++){
    	delete []edge[i];
    }
    delete []edge;


}