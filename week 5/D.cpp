#include<iostream>
#include<string>
#include<stdio.h>
#include<algorithm>
#include<cstdio> 
#include<cstdlib>
#include<string.h>

using namespace std;
const int MAX = 3e5+1;
int seq[MAX], t3v[MAX], t2v[MAX], v[MAX], appns[MAX];

void init(){
	memset(seq, 0, sizeof(seq));
	memset(t3v, 0, sizeof(t3v));
	memset(t2v, 0, sizeof(t2v));
	memset(v, 0, sizeof(v));
	memset(appns, 0, sizeof(appns));
}

int main(){
	int n, q, type, total = 0, num, read = 0, i = 0, j, last = -1;
	scanf("%d%d", &n, &q);
	init();
	while(q--){
		scanf("%d", &type);
		scanf("%d", &num);
		if(type == 1){
			total++;
			appns[num]++;
			seq[i++] = num;
		}else if(type == 2){
			t2v[num] = appns[num];
			if(t2v[num] > v[num]){
				read += t2v[num] - v[num];
				v[num] = t2v[num];
			}
		}else{
			for(j = last+1; j < num; ++j){
				int cur = seq[j];
				t3v[cur]++;
				if(t3v[cur] > v[cur]){
					read++;
					v[cur]++;
				}
			}
			last = last > (num-1) ? last:(num-1);
		}
		printf("%d\n", total-read);
	}
	return 0;
}
