#include <iostream>
#include <cstring>
using namespace std;

int main() {
	int N;
	string word;
	int alp[26], flag = 1, cnt = 0;
	cin >> N;
	for(int i = 0; i <N; i++) {
		cin >> word;
		flag = 1;
		memset(alp, 0, sizeof(alp));
		alp[word[0]-'a']++;
		for(int j = 1; j < word.size(); j++) {
			if(word[j-1] == word[j]) continue;
			if(alp[word[j]-'a'] != 0) flag = 0;
			alp[word[j]-'a']++;
		}
		if(flag) cnt++;
	}
	cout << cnt;
	return 0;
}
