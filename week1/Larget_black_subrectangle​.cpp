#include<bits/stdc++.h>
using namespace std;
#define N 1000

int m ,n;
int A[N][N];
int h[N][N];
int L[N],R[N];
void input(){
	cin >> n>>m;
	for(int i = 1;i<=n;i++){
		for(int j =1;j<=m;j++){
			cin>>A[i][j];
			if(A[i][j]==0) h[i][j]=0;
			else{
				if(i==1) h[i][j] = 1;
				else{
					if(A[i-1][j]==1) h[i][j] = h[i-1][j]+1;
					else h[i][j] = 1;
				}
			}
		}
	}
}