//Quay lui - BackTrack liet ke cac to hop chap k cua 1..n
#include <iostream>
using namespace std;
int	n, k, X[100], count=1;
void print(){
	cout << "\n" << count++ << ": ";
	for(int j=1; j<=k; j++) cout << X[j] << " ";
}
void BackTrack(int i){	//Sinh cau hinh bat dau tu X[i]
	for(int j=X[i-1]+1; j<=n-k+i; j++){
		X[i]=j;			//chap nhan kha nang j (khong co han che hay rang buoc)
		if(i==k)		//Du 1 cau hinh: in
			print();
		else			//Chua du cau hinh: liet ke cac cau hinh bat dau tu X[i+1]
			BackTrack(i+1);
	}
	return;
}
int main() {
	n=5;	k=3;
	X[0]=0;
	BackTrack(1);		//Liet ke tat ca cac cau hinh bat dau tu X[1]
}