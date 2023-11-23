#include<iostream>
using namespace std;
int main(){
	string s;
	cin>>s;
	int i = 0,j = s.size()-2;
	for(;i!=j;i++,j--){
		if(s[i]!=s[j]){
			cout<<0;
			return 0;
		}
	}
	cout<<1;
	return 0;
}
