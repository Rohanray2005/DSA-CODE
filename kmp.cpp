#include<bits/stdc++.h>

using namespace std;

vector<int> kmp_lps(string s){
	vector<int>lps(s.size(),0);
	for(int i=1;i<lps.size();++i){
		int prev_idx=lps[i-1];

		while(prev_idx>0 && s[i]!=s[prev_idx]){
			prev_idx=lps[prev_idx-1];
		}
		lps[i]=prev_idx+(s[i]==s[prev_idx]?1:0);
	}
	return lps;
}
int no_of_occ_of_pattern(string text,string pattern){
	int ans=0;
	string t=pattern+"#"+text;
	vector<int>lps=kmp_lps(t);
	for(int i=0;i<lps.size();i++){
		if(lps[i]==pattern.size())ans++;
	}
	return ans;
}

int main(){
	string text="aabaarbaab",pattern="aab";
	cout<<no_of_occ_of_pattern(text,pattern);
}