#include<iostream>
using namespace std;

const int maxn = 10000;

int m;  //������ 
int n;  //���Ա���Ԫ�ظ��� 
int arr[maxn];

void Insert(int i, int x){//����x��a[i]
    n++;
    for(int j = n; j > i ; j--){
    	arr[j] = arr[j-1];
	}
	arr[i] = x;
} 

void DeleteByIndex(int i){ //ɾ��a[i] 
    for(int j = i; j < n ; j++){
    	arr[j] = arr[j+1];
	}
	n--;
} 

int Find(int x){//���ҵ�һ��x 
    for(int i = 1; i <= n; i++){
    	if(arr[i] == x)return i;
	}
	return 0;
}

void EliminateRepeat(){ //ȥ���ظ�Ԫ�� 
    int tmp[maxn];
    int tail = 0;
    for(int i = 1; i <= n; i++){
    	int flag = 0;
    	for(int j = 1; j <= tail; j++){
    		if(arr[i] == tmp[j]){
    			flag = 1;
    			DeleteByIndex(i);
    			i--;
    			break;
			}
		}
		if(flag == 0){
			tmp[++tail] = arr[i];
		}
	}
}

int Count(int x, int y){//ͳ��[x,y]��Ԫ�ظ���	
	int k = 0;
	for (int j = 1; j <= n; j++)
		if (arr[j] >= x && arr[j] <= y)
			k++;
	return k;
}

void DeleteByRange(int x, int y){ //ȥ��[x,y]��Χ�ڵ�Ԫ�� 
	int k = 0;
	for (int j = 1; j <= n; j++){
		if(arr[j] >= x && arr[j] <= y){
			DeleteByIndex(j);
			j--;
		}
	}
} 

int main(){
	int m,x,y,i;
	cin>>m;
	int choose;
	while(m--){
		cin>>choose;
		switch (choose){
			case 1:
				cin>>i>>x;
				Insert(i,x);
				break;
			case 2:
				cin>>i;
				DeleteByIndex(i);
				break;
			case 3:
				cin>>x;
				cout<<Find(x)<<endl;
				break;
			case 4:
				cin>>x>>y;
				cout<<Count(x,y)<<endl;
				break;
			case 5:
				EliminateRepeat();
				break;
			case 6:
				cin>>x>>y;
				DeleteByRange(x,y);
				break;
		}
	}
	return 0;
}
