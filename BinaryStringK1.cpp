#include<bits/stdc++.h>
using namespace std;

int n,k, X[17];
bool cauhinhcuoi=false;
void sinh(){
	//X[1..n]: cau hinh hien tai
	//tim tu ben phai sang: bat dau voi X[n]
	int i=n;
	while((i>0)&&(X[i]==1)) i--;	//Neu X[i]==1 voi i>0 thi bo qua
	//Neu i==0: X[i]==1 voi i=1..n hay cau hinh dang xet la cau hinh cuoi cung
	//    i!=0: ton tai X[i]!=1 hay X[i]==0 hay chua phai cau hinh cuoi cung
	if(i==0){	//Cau hinh cuoi cung: thong bao dung la cau hinh cuoi, dung ham sinh
		cauhinhcuoi=true;	return;
	}
	else{		//Chua phai cau hinh cuoi: sinh cau hinh tiep theo
		for(int j=i; j<=n; j++)	X[j]=1-X[j];	//Tu i den n: dao bit
	}
	return;
}
void print(){
	for(int j=1; j<=n; j++) cout << X[j];
    cout << endl;
}
int main() {
    int t; cin >> t;
    while (t--)
    {   
        cin >> n >> k;
        	//Tao cau hinh dau tien
        for(int j=1; j<=n; j++)	X[j]=0;
        //Lap khi chua phai cau hinh cuoi cung
        while(!cauhinhcuoi)
        {
            int res = 0;
            for (int k = 1; k <=n ;k++)
                if (X[k] == 1)
                    res++;
            if ( res == k)
                print();	//in cau hinh hien tai
            sinh();		//sinh cau hinh tiep theo
        }
        cauhinhcuoi = false;
    }
	return 0;
}