#include<iostream>
#include<string>
#include<stdio.h>
#include<algorithm>
#include<cstdio> 
#include<cstdlib>
#include<string.h>
#include<vector>

using namespace std;
const int MAX = 11e5;
typedef long long ll;

int pos[3];

const string pushS = "pushStack", popS = "popStack";
const string pushQ = "pushQueue", popQ = "popQueue";
const string pushF = "pushFront", popF = "popFront";
const string pushB = "pushBack" , popB = "popBack" ;

void find3max(const vector<int>& seq){
	int fir, sec, thr, i, n = seq.size();
	fir = sec = thr = -1;
	for(i = 0; i < n; ++i){
		if(fir == -1 || seq[fir] < seq[i])fir = i;
	}
	for(i = 0; i < n; ++i){
		if((sec == -1 || seq[sec] < seq[i]) && fir != i)sec = i;
	}
	for(i = 0; i < n; ++i){
		if((thr == -1 || seq[thr] < seq[i]) && fir != i && sec != i)thr = i;
	}
	pos[0] = min(fir, min(sec, thr));
	pos[2] = max(fir, max(sec, thr));
	if(fir < pos[2] && fir > pos[0])pos[1] = fir;
	if(sec < pos[2] && sec > pos[0])pos[1] = sec;
	if(thr < pos[2] && thr > pos[0])pos[1] = thr;
}
 
void print(int n){
	int i;
	for(i = 0; i <= pos[0]; i++){
		cout << pushS << '\n';
	}
	for(i = pos[0]+1; i <= pos[1]; ++i){
		cout << pushB << '\n';
	}
	for(i = pos[1]+1; i < pos[2]; ++i){
		cout << pushF << '\n';
	}
	for(i = pos[2]; i < n; ++i){
		cout << pushQ << '\n';
	}
	cout << 3 << " " << popS << " " << popQ << " " << popB;
}

int main(){
	ios::sync_with_stdio(false);
	int n, cmd, i;
	cin >> n;
	vector<int> seq;
	while(n--){
		cin >> cmd;
		if(cmd != 0){
			seq.push_back(cmd);
		}else{
			if(seq.size() == 0){
				cout << 0;
			}else if(seq.size() == 1){
				cout << pushS << endl;
				cout << 1 << " " << popS; 
			}else if(seq.size() == 2){
				cout << pushS << '\n' << pushQ << endl;
				cout << 2 << " " << popS << " " << popQ;
			}else if(seq.size() == 3){
				cout << pushS << '\n' << pushQ << '\n' << pushF << endl;
				cout << 3 << " " << popS << " " << popQ << " " << popF;
			}else{
				find3max(seq);
				print(seq.size());
			}
			seq.clear();
			if(n)cout << '\n';
		}		
	}
	for(i = 0; i < seq.size(); ++i){ //如果没有0，也需要push 
		cout << pushS << '\n';
	}	
	return 0;
}
