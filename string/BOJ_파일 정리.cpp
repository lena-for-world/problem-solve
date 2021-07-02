#include <iostream>
#include <map>
#include <vector>
#include <sstream>
#include <algorithm>
using namespace std;

int main() {
	int N;
	cin >> N;
	int z = 0;
	vector<string> v;
	map<string, int> m;
	for(int i = 0; i < N; i++) {
		string stringBuffer;
		cin >> stringBuffer;
		istringstream ss(stringBuffer);
		while(getline(ss, stringBuffer, '.')) {
			if(z == 1) {
				if(m[stringBuffer] == 0) v.push_back(stringBuffer);
				m[stringBuffer] += 1;
			}
			z++;
		}
		z = 0;
	}
	sort(v.begin(), v.end());
	for(int i = 0; i < v.size(); i++) cout << v[i] << " " << m[v[i]] << '\n';
	return 0;
}
