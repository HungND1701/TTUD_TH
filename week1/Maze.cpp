#include<bits/stdc++.h>
using namespace std;
#define maxN 300

int n,m,r,c; //sohang = n ; so cot = m ; 
int a[maxN][maxN];
bool visit[maxN][maxN];
int d[maxN][maxN];
int moveX[]={0, 0, 1, -1};
int moveY[]={1, -1, 0 , 0};
int dmin = 9999;
bool check(int x, int y){
	return (x==1||y==1||x==m||y==n);
}
void bfs(int sx, int sy){
	for(int i = 1; i<=n;++i){
		fill_n(d[i],m+1,0);
		fill_n(visit[i],m+1,false);
	}	
	queue<pair<int,int>> q;
	q.push({sx,sy});
	visit[sx][sy] = true;
	while(!q.empty()){
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		
		if(check(x,y)){
			cout << d[x][y] +1;
			return ;	
		}
		
		for(int i = 0; i < 4;i++){
			int u = x + moveX[i];
			int v = y + moveY[i];
			
			
			if(u > m || u < 1) continue;
			if(v > c || v < 1) continue;
			if(a[u][v] == 1) continue;
			
			if(!visit[u][v]){
				d[u][v] = d[x][y] +1;
				
				visit[u][v] = true;
				q.push({u,v});
			}
		}
	}	
}
int main(){
	cin >> n>>m>>r>>c;
	for(int i = 1 ; i<=n ; ++i){
		for(int j = 1; j<=m;++j){
			cin >> a[i][j];
		}
	}
	bfs(r,c);
	
	return 0;
}