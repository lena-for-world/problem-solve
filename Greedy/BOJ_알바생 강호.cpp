#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int N;
	long long sum = 0;
	vector<int> v;
	cin >> N;
	for(int i = 0; i < N; i++) {
		int temp;
		cin >> temp;
		v.push_back(temp);
	}
	sort(v.begin(), v.end(), greater<int>());
	for(int i = 0; i < N; i++){
		int calc = v[i] - i;
		if(calc <= 0) break;
		sum += calc;
	}
	cout << sum;
	return 0;
}
