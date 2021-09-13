#include <iostream>
#include <vector>
#define MAX 1000000001
using namespace std;

vector<string> v;

void func(int plus, int minus, int multi, int div, string st){
	if(plus == 0 && minus == 0 && multi == 0 && div == 0) {
		v.push_back(st);
		return;
	}
	if(plus != 0) func(plus-1, minus, multi, div, st + '+');
	if(minus != 0) func(plus, minus-1, multi, div, st + '-');
	if(multi != 0) func(plus, minus, multi-1, div, st + '*');
	if(div != 0) func(plus, minus, multi, div-1, st + '/');
}

int main() {
	int n, a;
	int mx = -MAX, mn = MAX;
	int sign[4];
	vector<int> num;
	cin >> n;
	for(int i = 0; i < n; i++) {
		cin >> a;
		num.push_back(a);
	}
	for(int i = 0; i < 4; i++) {
		cin >> a;
		sign[i] = a;
	}
	string st = "";
	func(sign[0],sign[1],sign[2],sign[3], st);
	for(int i = 0; i < v.size(); i++) {
		int ans = num[0];
		for(int j = 1; j < n; j++) {
			char sn = v[i][j-1];
			if(sn == '+') {
				ans += num[j];
			} else if(sn == '-') {
				ans -= num[j];
			} else if(sn =='*') {
				ans *= num[j];
			} else {
				if(ans < 0) {
					ans = (-ans) / num[j];
					ans *= -1;
				}
				else ans /= num[j];
			}
		}
		if(mx < ans) {
			mx = ans;
		}
		if( mn > ans) {
			mn = ans;
		}
	}
	cout << mx << '\n' << mn;
	return 0;
}



// 더 빠른 실행시간

#include <iostream>
#include <vector>
#define MAX 1000000001
using namespace std;

int n;
vector<int> num;
int mx = -MAX, mn = MAX;

void func(int plus, int minus, int multi, int div, int res, int depth){
	if(depth == n-1) {
		if(mx < res) mx = res;
		if(mn > res) mn = res;
		return;
	}
	if(plus != 0) func(plus-1, minus, multi, div, res+num[depth+1], depth+1);
	if(minus != 0) func(plus, minus-1, multi, div, res-num[depth+1], depth+1);
	if(multi != 0) func(plus, minus, multi-1, div, res*num[depth+1], depth+1);
	if(div != 0) func(plus, minus, multi, div-1, res/num[depth+1], depth+1);
}

int main() {
	int a;
	int sign[4];
	cin >> n;
	for(int i = 0; i < n; i++) {
		cin >> a;
		num.push_back(a);
	}
	for(int i = 0; i < 4; i++) {
		cin >> a;
		sign[i] = a;
	}
	string st = "";
	func(sign[0],sign[1],sign[2],sign[3], num[0], 0);
	cout << mx << endl << mn;
	return 0;
}

