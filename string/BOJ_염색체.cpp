#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int N;
	cin >> N;
	for(int i = 0; i < N; i++) {
		string st; 
		cin >> st;
		int len = st.size()-1;
		if(st[0] >= 'A' && st[0] <= 'F' && st[len] >= 'A' && st[len] <= 'F') {
      			// A, F, C가 한 개 이상 나올 수 있지만, 한 개만 있어도 조건을 만족하기에 충분하다
			st.erase(unique(st.begin(), st.end()), st.end());
			if(st.size() == 5) {
				if(st[1] == 'A' && st[2] == 'F' && st[3] == 'C') {
					cout << "Infected!" <<'\n';
					continue;
				}
			}
			else if(st.size() == 4) {
				if(st[0] == 'A' && st[1] == 'F' && st[2] == 'C') {
					cout << "Infected!" <<'\n';
					continue;
				}
				if(st[1] == 'A' && st[2] == 'F' && st[3] == 'C') {
					cout << "Infected!" <<'\n';
					continue;
				}
			}
			else if(st.size() == 3) {
				if(st[0] == 'A' && st[1] == 'F' && st[2] == 'C') {
					cout << "Infected!" <<'\n';
					continue;
				}
			}
		}
		cout << "Good" <<'\n';
	}
	return 0;
}
