#include <iostream>
#include <map> // binary search tree
using namespace std;

int main() {
	int a, n, m;
	int ans = 0;
	map<int, int> node;
	cin >> n >> m;
	for(int i= 0; i < n; i++) {
		cin >> a ;
		node[a] = 1;
	}
	for(int i = 0; i < m; i++) {
		cin >> a;
		if(node[a] == 1) ans++;
	}
	cout << n+m-2*ans;
	return 0;
}
