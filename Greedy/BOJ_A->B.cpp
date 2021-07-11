#include <iostream>
using namespace std;

int main() {
	int cnt = 1;
	long long a, b;
	cin >> a >> b;
	while(b > a) {
		string t = to_string(b);
		if(t[t.size()-1] == '1') {
			t.erase(t.size()-1, t.size());
			b = stoll(t);
		}
		else if (b % 2 == 1) {
			cout << -1;
			return 0;
		}
		else b /= 2;
		cnt++;
	}
	if(b== a) cout << cnt;
	else cout << -1;
	return 0;
}
