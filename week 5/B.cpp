#include<iostream>
#include<vector>
#include<string>
#include<stdio.h>
#include<algorithm>
#include<cstdio> 
#include<cstdlib>
#include<string.h>


//学习了https://blog.csdn.net/zhangfu2018/article/details/96476902 
using namespace std;
const int MAX = 31e5;
const int B = 8;
int base[7];
bool v[MAX]; //数组 

void init(){
	base[0] = 1;
	for(int i = 0; i < 6; ++i){
		base[i+1] = base[i]*B;
	}
}

void print(int value, int len){
	string ans = "";
	while(value){
		ans = char(value%B+'A') + ans;
		len--;
		value /= 8;
	} 
	while(len--){
		ans ='A' + ans;
	}
	cout << ans << endl;
	//printf("%s", ans); 
}

int main(){
	ios::sync_with_stdio(false);
	init();
	int T, i, len, n, last, del, t, hash;
	cin >> T;
	string s;
	while(T--){
		cin >> s;
		//cout << s << endl;
		n = s.size();
		for(len = 1; len <= 7; ++len){
			//if(len > n)break;
			memset(v, 0 ,sizeof(v));
			hash = 0;
			for(i = 0; i < len; ++i){
				hash = hash*B + s[i]-'A';
			}
			v[hash] = 1;
			for(i = len; i < n; ++i){
				del = (s[i-len]-'A')*base[len-1];
				hash = (hash-del)*B+s[i]-'A';
				v[hash] = 1;
			}
			t = 1 << (3*len);
			for(i = 0; i < t; ++i){
				if(!v[i]){
					print(i, len);
					break;
				}
			}
			if(i != t)break;
		}
	}	
	return 0;
} 
