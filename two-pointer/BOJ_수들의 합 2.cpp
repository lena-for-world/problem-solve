#include <iostream>
using namespace std;

int arr[10000];

int main() {
	int N, M, a;
	int cnt = 0;
	int i = 0, j = 0;
	cin >> N >> M;
	for(int i = 0; i < N; i++) {
		cin >> a;
		arr[i] = a;
	}
	int sum = 0;
	while(1) {
		if(sum >= M) {
			sum -= arr[i++];
		} else if(j == N) {
			break;
		} else {
			sum += arr[j++];
		}
		if(sum == M) cnt++;
	}
	cout << cnt;
	return 0;
}
