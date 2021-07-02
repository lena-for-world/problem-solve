#include <iostream>
#include <string>
using namespace std;

int main() {
	int N;
	cin >> N;
	for(int i = 0; i < N; i++) {
		string str;
		int ch = 0;
		int res = 0;
		cin >> str;
		string str2 = str; string str3 = str;
		for(int j = 0; j < str.size(); j++) {
			if(str[j] != str[str.size()-j-1]) {
				res = 1;
				ch = j;
			}
		}
		if(res == 0) {
			cout << res << '\n';
		}
		else {
			res = 1;
			str2.erase(ch, 1); str3.erase(str.size()-ch-1, 1);
			for(int q = 0; q < str2.size(); q++) {
				if(str2[q] != str2[str2.size()-q-1]) {
					res = 2;
					break;
				}
			}
			if(res == 2) {
				res = 1;
				for(int q = 0; q < str3.size(); q++) {
					if(str3[q] != str3[str2.size()-q-1]) {
						res = 2;
						break;
					}
				}
			}
			cout << res << '\n';
		}
	}
	return 0;
}
