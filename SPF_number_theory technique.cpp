const int N=1e7+7;
vi spf(N,1);
void sieve(int n){
	for(int i=2;i<n;i++){
		if(spf[i]==1){
			spf[i]=i;
			for(int j=i*i;j<=n;j+=i){
				if(spf[j]==1)spf[j]=i;
			}
		}
	}
}
vi factorise(int n){
	vi ans;
	while(n>1){
		int fact = spf[n];
		while(n%fact==0){
			n/=fact;
			ans.pb(fact);
		}
	}
	return ans;
}