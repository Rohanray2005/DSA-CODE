double findNthRootOfM(int n, long long m) {
	   // this is a very generalised version of this problem without any errors and high precision 
     // m is very large and n<=300 so computation of mid^n is not possible in every case of binary search that is handled very cleverly.
     // also z indicated whether we are able to take powers upto n times otherwise we don't check for it to be correct ans.
    double lo=0,hi=(m);
    double ans=1;
    int t=100;
    while(t--){
        double mid=(lo+(hi-lo)/2);
        double val=1.0;
        int z=n;
        while(val<m && z>0){
            val*=mid;
            z--;
        }
        if(val<=m && z==0){
            ans=mid;
            lo=mid;
        }else{
            hi=mid;
        }                
    }
    return ans;
}
