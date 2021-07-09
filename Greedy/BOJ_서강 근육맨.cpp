#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int N;
	long long M = 0;
	vector<long long> v;
	cin >> N;
	for(int i = 0; i < N; i++) {
		long long temp; // ^^... 타입 확인을 잘하자 실수하지말자^^...
		cin >> temp;
		v.push_back(temp);
	}
	sort(v.begin(), v.end());
	if(v.size() % 2 == 1) {
		M = max(M, v[v.size()-1]);
		for(int i = 0; i < (N-1)/2; i++) M = max(v[i] + v[v.size()-2-i], M);
	}
	else {
		for(int i = 0; i < N/2; i++) M = max(v[i] + v[v.size()-1-i], M);
	}
	cout << M;
	return 0;
}
