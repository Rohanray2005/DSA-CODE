vector<int>divisor;
  for(int i=1;i*i<=n;i++){
    if(n%i==0){
      divisor.pb(i);
      if(i!=n/i)divisor.pb(n/i);//include only if i is not square root of n otherwise a same number will be included twice.
    }
  }
