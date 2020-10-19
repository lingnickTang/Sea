#include<iostream>
#include<vector>
#include<string>
#include<stdio.h>
#include<algorithm>
#include<cstdio> 
#include<cstdlib>
#include<stack>

using namespace std;
const int MAX = 11e5;

int main(){
	string com;
	stack<int> stk;
	int n, num, isorder = 0, box2re = 1, i, ans = 0;
	scanf("%d", &n);
	for(i = 0; i < 2*n; ++i){
		cin >> com;
		if(com == "add"){
			scanf("%d", &num);
			stk.push(num);
		}else{
			if(isorder == stk.size()){
				stk.pop();
				isorder--;
			}else{
				if(stk.top() == box2re){
					stk.pop();	
				}else{
					ans++;
					stk.pop();
					isorder = stk.size();
				}
			}
			box2re++;
		}	
	}
	printf("%d\n", ans);
	return 0;
} 
