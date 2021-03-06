Distribute Candies
Send Feedback
Shaky has N (1<=N<=50000) candy boxes each of them contains a non-zero number of candies (between 1 and 1000000000).
Shaky want to distibute these candies among his K (1<=K<=1000000000) IIIT-Delhi students. He want to distibute them in a way such that:
1. All students get equal number of candies.
2. All the candies which a student get must be from a single box only.
As he want to make all of them happy so he want to give as many candies as possible.
  Help Shaky in finding out what is the maximum number of candies which a student can get.
Input
First line contains 1<=T<=20 the number of test cases. Then T test cases follow. First line of each test case contains N and K. Next line contains N integers, 
ith of which is the number of candies in ith box.
Output
For each test case print the required answer in a seperate line.
Sample Input:
2
3 2 
3 1 4
4 1
3 2 3 9
Sample Output:
3
9

int ispossible(ll arr[],int n,int k,ll d)
{   
    int count=0;
    rep(i,0,n){
        count+=arr[i]/d;
    }
    if(count>=k)return 0;
    return -1;
}


ll solve(ll arr[],int n,int k){
    int i=0,j=arr[n-1];
    int ans=1;
    while(i<=j){
        int mid=(i+j)/2;
        if(ispossible(arr,n,k,mid)==0){
            ans=mid;
            i=mid+1;
        }
        else{
            j=mid-1;
        }
        
    }    
    return ans;
}

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif  
    int t;
    ll n,k;
    cin>>t;
    while(t--){
        cin>>n>>k;
        ll arr[n];
        rep(i,0,n){
            cin>>arr[i];
        }
        sort(arr,arr+n);
        ll ans=solve(arr,n,k);
        cout<<ans<<"\n";        
    }
    return 0;
}
