#include<bits/stdc++.h>
using namespace std;
#define N 999
long n,A[N],m;
long Q;
long M[N][N];
long sum = 0;

long RMQ(long i,long j){
	if(M[i][j] > 0) return M[i][j];
	else{
		if(j == 0 ) return i;
		else{
			return (A[RMQ(i,j-1)] >= A[RMQ(i+pow(2,j-1), j-1)]) ? RMQ(i+pow(2,j-1), j-1): RMQ(i,j-1);
		}
	}
}

int main (){
	cin>> n ;
	for(long i=0;i<n;i++) {
		cin >> A[i];
		
	}
	cin >> m;
	for(long v = 1;v<=m;v++){
		long i,j;
		cin >> i >>j;
		if((j-i+1)%2!=0){
			sum += min(A[RMQ(i,log2(j-i))],A[j]);
		}else{
			sum += A[RMQ(i,log2(j+1-i))];
		}
		
	}
	
	cout<<sum;
	return 0 ;
}