#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <time.h>
using namespace std;
int g;
struct node
{
	int num;
	int data;
	node *next;
};
typedef struct node ND;

node *FI(node *front,int n){
	node *ptr = front;
	while(ptr!=NULL){
		if(ptr -> num == n){
			return (ptr);
		}
		ptr = ptr ->next;
	}
	cout << "\n資料毀損\n";
	system("pause");
}

void Msort(node *front,int n){
	srand((unsigned)time(NULL));
	for(int j=0,k=1;1<(n-j);j++){
		int tmp = rand()%(n-j);
		int num = FI(front,(n-k))->data;
		FI(front,(n-k))->data = FI(front,tmp)->data;
		FI(front,tmp)->data = num;
		k++;
	}
}

int main(){
	node *H,*P;
	cout << "想輸入幾個數字" << endl;
	cin >> g;
	H = (node *)malloc(sizeof(ND));
	P = H;
	for(int i = 0;i<g;i++){
		cout << "請輸入第" << i+1 << "個數字" << endl;
		P -> num = i;
		cin >> P -> data;
		if(i==(g-1)){
			P -> next = NULL;
		}
		else{
			P -> next = (node *)malloc(sizeof(ND));
			P = P -> next;
		}
		
	}
	int ct=0;
	A:
	Msort(H,g);
	for(int k=0;k<(g-1);k++){
		if( (FI(H,k)-> data) > (FI(H,k+1)-> data) ){
			ct++;
			goto A;
		}
	}
	for(int k=0;k<g;k++){
		int NB = FI(H,k)->data;
		cout << NB << " ";
	}
	cout << endl;
	cout << "共移動了" << ct<< "次" << endl; 
	system("pause");
}
