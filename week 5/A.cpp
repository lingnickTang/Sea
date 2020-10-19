#include<iostream>
#include<vector>
#include<string>
#include<stdio.h>
#include<algorithm>
#include<cstdio> 
#include<cstdlib>

using namespace std;
const int MAX = 11e5;
int s[MAX], a[MAX];

int main(){
	int n, least = ~(1<<31), ans, i;
	s[0] = 0;
	while(1){
		scanf("%d", &n);
		if(!n)break;
		for(i = 0; i < n; ++i)scanf("%d", &a[i]);
		least = ~(1<<31);
		for(i = 0; i < n; ++i){
			s[i+1] = s[i]+a[i];
			least = min(least, s[i+1]);
		}
		ans = 0;
		if(s[n] < 0){
			printf("%d\n", ans);
			continue;
		}
		for(i = n-1; i >= 0; --i){
			least += a[i];
			least = min(least, a[i]);
			if(least >= 0)ans++;
		}
		printf("%d\n", ans);
	}
	return 0;
} 
