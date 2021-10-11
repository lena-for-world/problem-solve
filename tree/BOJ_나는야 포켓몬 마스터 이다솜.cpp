#include <iostream>
#include <map> // bst
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	map<string, int> stmap;
	map<int, string> intmap;
	int n, m;
	cin >> n >> m;
	for(int i = 0; i < n; i++) {
		string a;
		cin >> a;
		stmap[a] = i+1;
		intmap[i+1] = a;
	}
	for(int i = 0; i < m; i++) {
		string a;
		cin >> a;
		if(a[0] - '0' >= 0 && a[0] -'0' <= 9) {
			cout << intmap[stoi(a)] << '\n';
		} else {
			cout << stmap[a] << '\n';
		}
	}
	return 0;
}
