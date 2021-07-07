#include <iostream>
#include <vector>
using namespace std;

int main() {
	vector<int> oil;
	vector<int> dist;
	int N, i = 0, j;
	long long sum = 0, temp = 0;
	cin >> N;
	for(int i = 0; i < N-1; i++) {
		cin >> temp;
		dist.push_back(temp);
	}
	for(int i = 0; i < N; i++) {
		cin >> temp;
		oil.push_back(temp);
  }
	while(i < N-1) {
		j = i+1;
		long long temp = 0;
		if(oil[i] > oil[j]) {
			temp += dist[i];
		}
		else {
			while(oil[i] <= oil[j]) {
				temp += dist[j-1];
				j++;
			}
			temp += dist[j-1];
		}
		temp *= oil[i];
		sum += temp;
		i = j;
	}
	cout << sum;
	return 0;
}
