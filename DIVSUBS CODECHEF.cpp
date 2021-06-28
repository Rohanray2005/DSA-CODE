#include <bits/stdc++.h>
#define ll long long
const int mod=1e9+7;
const int maxn=2e5+5;
#define endl '\n'
#define pb push_back
using namespace std;

int min_self(int &a,int b) { a=min(a,b); }
int max_self(int &a,int b) { a=max(a,b); }
// ************************************//


int main() {
	ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    // t=1;
    //cin.ignore(numeric_limits<streamsize>::max(), '\n');
    while(t--){
        int n;
        cin>>n;
        vector<ll int>arr(n+1);
        int index=-1;
        for(int i=1;i<=n;i++){
            cin>>arr[i];
            arr[i]%=n;
        }
        for(int i=1;i<=n;i++){
            if(arr[i]==0) {index=i; break;}
        }
        if(index!=-1){
            cout<<"1\n"<<index<<endl;
        }
        else{
            vector<int>present(n,-1);
            int start,last,sum=0;
            present[0]=0;
            for(int i=1;i<=n;i++){
                sum=((sum+arr[i])%n+n)%n;
                if(present[sum]!=-1) {start=present[sum]; last=i; break;}
                present[sum]=i;
            }
            cout<<last-start<<"\n";
            for(int i=start+1;i<=last;i++){
                cout<<i<<" ";
            }
            cout<<"\n"; 
        }
    }
    return 0;
}
