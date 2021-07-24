#include<bits/stdc++.h>

using namespace std;

int findminvertex(int weight[],bool visited[],int n){
	int minVertex=-1;
	for(int i=0;i<n;i++){
		if(!visited[i] && (minVertex==-1 ||weight[i]<weight[minVertex])){
			minVertex=i;
		}
	}
	return minVertex;
}

void prim(int **edge,int n){
	int parent[n];
	int weight[n];
	bool visited[n];
	for(int i=0;i<n;i++){
		visited[i]=false;
		weight[i]=INT_MAX;
	}
	parent[0]=-1;
	weight[0]=0;

	for(int i=0;i<n;i++){
		//Find minVertex
		int minVertex=findminvertex(weight,visited,n);
		visited[minVertex]=true;
		//Explore unvisited neighbour
		for(int j=0;j<n;j++){
			if(edge[minVertex][j]!=0 && !visited[j]){
				if(edge[minVertex][j]<weight[j]){
					weight[j]=edge[minVertex][j];
					parent[j]=minVertex;
				}
			}
		}
	}
	for(int i=1;i<n;i++){
		if(parent[i]<i){
			cout<<parent[i]<<" "<<i<<" "<<weight[i]<<"\n";
		}
		else{
			cout<<i<<" "<<parent[i]<<" "<<weight[i]<<"\n";
		}
	}

}


int main(){
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
    prim(edge,n);
    for(int i=0;i<n;i++){
    	delete []edge[i];
    }
    delete []edge;
}