int maxsum_non_overlapping_subarray(int arr[],int n,int k)
{
    int dp1[n];
    int dp2[n];
    int sum=0;
    for(int i=0;i<n;i++)
    {   
        if(i<k)
        {
            sum+=arr[i];
            dp1[i]=sum;
        }
        else
        {   
            sum=arr[i]-arr[i-k];
            dp1[i]=max(dp1[i-1],sum);
        }
    }
    sum=0;
    for(int i=n-1;i>=0;i--)
    {   
        if(i+k<=n)
        {
            sum+=arr[i];
            dp2[i]=sum;
        }
        else
        {   
            sum=arr[i]-arr[i+k];
            dp2[i]=max(dp2[i+1],sum);
        }
    }
    int ans=-100000;
    for(int i=k-1;i<n-k;i++)
    {
        ans=max(ans,dp1[i]+dp2[i]);
    }
    return ans;
}
