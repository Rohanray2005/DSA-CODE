int find_in_rotated_array(vector<int>v,int k){
     int n=v.size();
        if(n==0){
            return -1;
        }
        int lo=0,hi=n-1;        
        while(lo<=hi){
            int mid=(lo+hi)/2;
            if(v[mid]==k)return mid;
            else if(v[lo]<=v[mid]){
                if(k>=v[lo] && k<=v[mid]){
                    hi=mid-1;
                }
                else{
                    lo=mid+1;
                }
            }
            else {
                if(k>=v[mid] && k<=v[hi]){
                    lo=mid+1;
                }
                else{
                    hi=mid-1;
                }
            }           
        }  
        return -1;
}
