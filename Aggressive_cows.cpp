#include<bits/stdc++.h>

using namespace std;
const int mod = 1e9+7;

#define rep(i,j,n) for(int i=j;i<n;i++)

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
#define ll long long
int getbit(int n,int i)
{
	int mask=(1<<i);
   	int bit=(n&mask)>0?1:0;
   	return bit;
}

void BinaryRep(int n)
{	
	if(n==0)return;
	int x=n>>1;
	BinaryRep(x);
	cout<<(n&1);
}
int firstsetbitfromright(int n)
{	
	int i=0;
	while(n)
	{
		if(n&1==1)
			return i;
		i++;
		n=n>>1;
	}
	return -1;
}
void reduceFraction(int &x, int &y)
{
    int d;
    d = __gcd(x, y); 
    x = x / d;
    y = y / d;
}
bool get(int x)
{
     return (x && !(x & (x - 1)));
}

int countofsetbits(int n)
{	
	int count=0;
	while(n)
	{
		if(n&1==1)count++;
		n=n>>1;
	}
	return count;
}

string str(int i) {
    return i < 0 ? "" : str((i / 26) - 1) + (char)(97 + i % 26);
}

int uncommon_bits(int n,int m,int p)
{   
    int count = 0;
    for (int i = 0; i < p; i++) { 
        if (((n>> i) & 1) != ((m>> i) & 1)) {
            count++;
        }
    }
    return count;
}

bool ispossible(vector<ll>arr,int n,ll d,ll c){
    ll i=1;
    c--;
    ll prev=arr[0];
    while(i<n){
        if(arr[i]-prev>=d){
            c--;
            //cout<<prev<<" ";
            prev=arr[i];
        }
        if(c==0)break;
        i++;
    }
    //cout<<"\n";
    if(c==0)return true;
    else return false;
}

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif	
    int n,c,t;
    cin>>t;
    while(t--){
        cin>>n>>c;
        vector<ll>v(n);
        cin>>v;
        sort(v.begin(),v.end());
        int s=0,e=v[n-1]-v[0];
        vector<ll>ans;
        while(s<e){
            int d=(s+e)/2;
            if(ispossible(v,n,d,c)){
                ans.push_back(d);
                s=d+1;
                if(ispossible(v,n,s,c))ans.push_back(s);
            }
            else{
                e=d-1;
                if(ispossible(v,n,e,c))ans.push_back(e);
            }
        }
        ll max_e=0;
        for(int i=0;i<ans.size();i++){
            max_e=max(max_e,ans[i]);
        }
        cout<<max_e<<"\n";
    }
    return 0;
}


