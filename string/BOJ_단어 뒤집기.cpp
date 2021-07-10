#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	string st;
	int i = 0, j = 0;
	getline(cin ,st);
	while(i < st.size()) {
		if(st[i] == '<') {
			if(i != 0) {
				reverse(st.begin()+j, st.begin()+i);
				j = i;
			}
			while(st[++i] != '>') ;
			++i;
			j = i;
		}
		else if(st[i] == ' ') {
			// 뒤집기
			reverse(st.begin()+j, st.begin()+i);
			i++;
			j = i;
		}
		else {
			i++;
		}
	}
	if(j != st.size()-1) reverse(st.begin()+j, st.begin()+i);
	cout << st;
	return 0;
}
