#include<iostream>
#include<string>
#include<stdio.h>
#include<algorithm>
#include<cstdio> 
#include<cstdlib>
#include<string.h>

using namespace std;
const int MAX = 11e5;
typedef long long ll;

int a[MAX], memo[MAX], ans[MAX]; 

int main(){
	int n, m, i, j, big = -1;
	scanf("%d%d", &n, &m);
	memset(memo, 0, sizeof(memo));
	memset(ans, 0, sizeof(ans));
	for(i = 0; i < n; i++){
		scanf("%d", &a[i]);
		if(a[i] <= m)
			memo[a[i]]++;
	}
	for(i = 1; i <= m; ++i){
		for(j = i; j <= m; j += i){
			ans[j] += memo[i];
		}
	}
	for(i = 1; i <= m; ++i){
		if(big < 0 || ans[i] > ans[big])big = i;
	}
	printf("%d %d\n", big, ans[big]);
	if(ans[big] == 0)return 0;
	for(j = 0; j < n; ++j){
		if(big % a[j] == 0)printf("%d ", j+1);
	}
	//printf("\n%d %d", memo[2], ans[3]);
	return 0;
}
