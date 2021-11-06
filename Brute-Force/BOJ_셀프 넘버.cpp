#include <iostream>
#include <cstring>
using namespace std;

int check[10001];

int main() {
	memset(check,0,sizeof(check));
	for(int i = 1; i <= 10000; i++) {
		string s = to_string(i);
		int temp = i;
		for(int j = 0; j < s.size(); j++) {
			temp += (s[j] - '0');
		}
		check[temp] = 1;
	}
	for(int i = 1; i <= 10000; i++) {
		if(check[i] == 0) cout << i << '\n';
	}
	return 0;
}



