#include <iostream>
#include <map>
using namespace std;

map<string, string> p;
map<string, int> cnt;

string find(string n) {
	if(p[n] == "-1") return n;
	p[n] = find(p[n]);
	return p[n];
}

void merge(string a, string b) {
	string t1 = find(a);
	string t2 = find(b);
	
	if(t1 != "-1" && (t1 == t2)) {
		cout << cnt[t2] << '\n';
		return;
	}
	
	p[t1] = t2;
	cnt[t2] += cnt[t1];
	cout << cnt[t2] << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t, n;
	cin >> t;
	for(int i = 0; i < t; i++) {
		cin >> n;
		for(int i = 0 ; i < n; i++) {
			string a, b;
			cin >> a >> b;
			if(cnt[a] == 0) {
				cnt[a] = 1;
				p[a] = "-1";
			}
			if(cnt[b] == 0) {
				cnt[b] = 1;
				p[b] = "-1";
			}
			merge(a, b);
		}
		p.clear();
		cnt.clear();
	}
	return 0;
}
