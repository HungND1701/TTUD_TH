#include<bits/stdc++.h>
using namespace std;
#define N 100
int n ,M;
int x[N];
int soNghiem = 0;
int a[N];
int giatri ;
void solution(){
	
	soNghiem++;
}
bool check(int k , int v){
	if(k<n){
		return true;
	}else return giatri + v*a[k] == M;
}
void Try(int k ){
	for(int v = 1 ;v<=M- giatri-n+k; v++){
		if(check(k,v)){
			x[k] = v;
			giatri+= v*a[k];
			if(k==n) solution();
			else Try(k+1);	
			giatri-= v*a[k];
		}
		
	}
}
int main(){
	cin >>n >> M;
	for(int i = 1; i<= n;i++){
		cin >> a[i];
	}
	giatri = 0;
	Try(1);
	cout << soNghiem;
}