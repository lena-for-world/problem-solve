#include <iostream>
using namespace std;

int n;
int cache[502], S[502];

int calcMax(int idx) {
	int& ret = cache[idx];
	if(ret != -1) return ret;
	ret = 1;
	for(int i = idx+1; i < n; i++) {
		if(S[idx] < S[i]) {
			ret = max(calcMax(i)+1, ret);
		}
	}
	return ret;
}

void init() {
	for(int j = 0; j < 502; j++) {
		cache[j] = -1;
		S[j] = 0;
	}
}
 
int main() {
	int t, a;
	cin >> t;
	for(int z = 0; z < t; z++) {
		cin >> n;
		init();
		for(int i = 0; i < n; i++) {
			cin >> a;
			S[i] = a;
		}
		int mx = 0;
		for(int i = 0; i < n; i++) {
			mx = max(mx, calcMax(i));
		}
		cout << mx << '\n';
	}
	return 0;
}



// 좀 더 간단한 방법
#include <iostream>
using namespace std;

int n;
int cache[502], S[502];

int calcMax(int idx) {
	int& ret = cache[idx+1];
	if(ret != -1) return ret;
	ret = 1;
	for(int i = idx+1; i < n; i++) {
		if(idx == -1 || (S[idx] < S[i])) {
			ret = max(calcMax(i)+1, ret);
		}
	}
	return ret;
}

void init() {
	for(int j = 0; j < 502; j++) {
		cache[j] = -1;
		S[j] = 0;
	}
}
 
int main() {
	int t, a;
	cin >> t;
	for(int z = 0; z < t; z++) {
		cin >> n;
		init();
		for(int q = 0; q < n; q++) {
			cin >> a;
			S[q] = a;
		}
    
    // -1에서 시작해서 모든 경우를 돌아볼 수도 있다
		cout << calcMax(-1)-1 << '\n';
	}
	return 0;
}
