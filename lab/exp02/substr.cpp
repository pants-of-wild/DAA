#include<iostream>
using namespace std;
int main(){
	int a,len1;
	string s,ans;
	cin>>a>>len1>>s;
	int len2 = s.size();
	if(a>len2||a<1||len1>len2||len1<0) return 0;
	else{
		for(int i = a-1;i<len1+a-1;i++){
			cout<<s[i];
		}
	}
	return 0;
}
