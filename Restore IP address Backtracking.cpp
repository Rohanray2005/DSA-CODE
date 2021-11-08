 bool isvalid(string s){
        if(s[0]=='0')return false;
        int x=stoi(s);
        if(x>255)return false;
        return true;
    }
    void solve(string s,vector<string>&v,string asf,int k){
        if(s.size()==0 || k==0){
            //cout<<asf<<"\n";
            if(s.size()==0 && k==0){
                v.push_back(asf.substr(0,asf.size()-1));
            }
            return;
        }
        solve(s.substr(1),v,asf+s.substr(0,1)+".",k-1);
        if(s.size()>=2 && isvalid(s.substr(0,2)))
        solve(s.substr(2),v,asf+s.substr(0,2)+".",k-1);
        if(s.size()>=3 && isvalid(s.substr(0,3)))
        solve(s.substr(3),v,asf+s.substr(0,3)+".",k-1);
    }
    
    vector<string> restoreIpAddresses(string s) {
        vector<string>v;
        solve(s,v,"",4);
        return v;
    }
