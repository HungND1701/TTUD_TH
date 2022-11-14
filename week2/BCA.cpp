#include<bits/stdc++.h>
using namespace std;
#define N 30
int n ,m; // n = so mon hoc m = so giao vien
bool ChuyenMon[N][N];
bool XungDot[N][N];
int PC[N][N];
bool DaPC[N];
int somondapc;
int Max= 100;

bool check(int i,int k,int v){
	if(ChuyenMon[i][v] == false) return false;
	if(DaPC[v] == true) return false;
	for(int j =1;j<k;j++) if(XungDot[PC[i][j]][v] == true) return false;
	return true;
}
void solution(int k){
	if(k < Max) Max = k;
//	for(int i = 1;i<=m;i++){
//		cout << "giao vien "<<i<<" :";
//		for(int j =1;j<=k;j++){
//			cout << PC[i][j] <<"-";
//		}
//		cout <<endl;
//	}
}
void Try(int i,int k){
	for(int v =1;v<=n;v++){
		if(check(i,k,v)){
			PC[i][k] = v;
			somondapc+=1;
			DaPC[v] = true;
			if(somondapc == n) solution(k);
			else {
				if(i==m) Try(1,k+1);
				else Try(i+1,k);
			}
			somondapc-=1;
			DaPC[v] = false;
		}
	}
}
void input(){
	
	cin >>m >>n;
	for(int i = 1;i<=m;i++){
		for(int j =1;j<=n;j++){
			ChuyenMon[i][j] = false;
		}
	}
	for(int i = 1;i<=n;i++){
		for(int j =1;j<=n;j++){
			XungDot[i][j] = false;
		}
		DaPC[i] = false;
	}
	
	for(int i = 1;i<=m;i++){
		int somon;
		cin >> somon;
		for(int j = 1;j<=somon;j++){
			int mon;
			cin >> mon;
			ChuyenMon[i][mon] = true;
		}
	}
	int soxungdot;
	cin >> soxungdot;
	for(int i = 1;i<=soxungdot;i++){
		int mon1,mon2;
		cin >> mon1>>mon2;
		XungDot[mon1][mon2] = true;
		XungDot[mon2][mon1] = true;
	}
}
int main(){
	input();
	somondapc = 0;
	Try(1,1);
	cout << Max;
}