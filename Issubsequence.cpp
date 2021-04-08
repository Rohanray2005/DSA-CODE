#include <bits/stdc++.h>
using namespace std;

 bool isSubsequence(string s, string t) {
        vector<bool>v(t.length(),false);
        int i=0,j=0;
        while(j<t.length() && i<s.length())
        {
            if(s[i]==t[j])
            {   
                v[j]=true;
                i++;
                j++;
            }
            else
            {
                i++;
            }
        }
        bool flag=true;
        for(int i=0;i<v.size();i++)
        {   
            cout<<v[i];
            if(v[i]==false)
            flag=false;
        }
        cout<<"\n";
        return flag;
 }
int main() {
	string a="1001011";
	string b="1100";
	cout<<isSubsequence(a,b);
	return 0;
}