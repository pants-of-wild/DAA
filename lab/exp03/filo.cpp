
#include<stdio.h>
int main(){
	char v='A',s,Q[8];
	Q[0]=v;
	int count=0,top=1;
	while(count<8){
		scanf("%c",&s);
		count++;
		while(Q[top-1]!=s&&v<'H'){
			Q[top++]=++v;
		}
		if(Q[top-1]==s&&v<='H'){
			top--;
		}
		else{
			break;
		}
	}
	if(top){
		printf("0");
	}
	else{
		printf("1");
	}
	return 0;
}
