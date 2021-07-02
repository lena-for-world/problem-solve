#include <iostream>
using namespace std;

// 문제를 잘못 이해해서 삽질...

int main() {
	string st;
	cin >> st;
    bool pal = false, ans = false;
	for(int i = 0; i < st.size()/2; i++) {
		if(st[i] != st[st.size()-1-i]) ans = true;
        else if(st[i] != st[i+1]) pal = true; // 회문이긴 한데 모두 같은 문자는 아니라 -1 조건에 미해당
	}
	if(ans) cout << st.size();
	else {
        if(pal) cout << st.size()-1;
        else cout << -1;
    }
	return 0;
}
