//Sudoku solver : https://www.codechef.com/problems/AX06
#include<bits/stdc++.h>

using namespace std;
const int mod = 1e9+7;
const int size=1e3;
int arr[10][10];

bool findemptylocations(int &row,int &col){
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            if(arr[i][j]==0){
                row=i;
                col=j;
                return true;
            }
        }
    }
    return false;
}
bool issafe_row(int row,int col,int num){
    for(int i=0;i<9;i++){
        if(arr[row][i]==num)return false;
    }
    return true;
}
bool issafe_col(int row,int col,int num){
    for(int i=0;i<9;i++){
        if(arr[i][col]==num)return false;
    }
    return true;
}
bool issafe_grid(int row,int col,int num){
    int rowfactor=row-(row%3);
    int colfactor=col-(col%3);
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            if(arr[i+rowfactor][j+colfactor]==num){
                return false;
            }
        }
    }
    return true;
}

bool issafe(int row,int col,int num){
    if(issafe_grid(row,col,num)&& issafe_col(row,col,num) && issafe_row(row,col,num))
        return true;
    else
        return false;
}

bool sudoku_solver(){
	int row,col;
	if(!findemptylocations(row,col))return true;

	for(int i=1;i<=9;i++){
		if(issafe(row,col,i)){
            arr[row][col]=i;
            if(sudoku_solver()){
                return true;
            }
            arr[row][col]=0;
        }
	}
    return false;
}

int main()
{
    for(int i=0;i<9;i++){
    	string s;
    	cin>>s;
    	for(int j=0;j<9;j++){
    		arr[i][j]=s[j]-'0';
    	}
    }
    sudoku_solver();
    for(int i=0;i<9;i++){
    	for(int j=0;j<9;j++){
    		cout<<arr[i][j];
    	}
    	cout<<"\n";
    }
 }
