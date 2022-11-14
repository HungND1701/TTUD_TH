#include<bits/stdc++.h>
using namespace std;
#define N 30
int n,K;
int C[N][N];
int f ;
int f_best = 1000;
int load; // ghi so khach dang co mat
bool visited[N];
int x[N]; 
bool check(int v,int k){
	if(visited[v]==true) return false;
	if(v <= n && load==K) return false;
	if(v > n && visited[v-n]!=true) return false;
	
	return true;
}
void solution(int d){
	d = d + C[x[2*n]][0];
	if(d<f_best) f_best = d;
}
void Try(int k){
	for(int v = 1; v<=2*n;v++){
		if(check(v,k)){
			x[k] = v;
			f += C[x[k-1]][v];
			visited[v] = true;
			if(v>=1&&v<=n){
				load+=1;
			}else{
				load-=1;
			}
			if(k==2*n) solution(f);
			else{
				Try(k+1);
			}
			f -= C[x[k-1]][v];
			visited[v] = false;
			if(v>=1&&v<=n){
				load-=1;
			}else{
				load+=1;
			}
		}
	}
}
void input(){
	cin >> n>>K;
	for(int i=0;i<=2*n;i++){
		for(int j=0;j<=2*n;j++){
			cin >> C[i][j];
		}
		visited[i] = false;
	}	
}
int main(){
	input();
	f = 0;
	load = 0;
	visited[0] = true;
	Try(1);
	cout <<f_best;
	return 0;
}