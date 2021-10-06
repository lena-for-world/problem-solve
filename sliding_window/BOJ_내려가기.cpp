#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int main() {
	int colMin[3] = {0}, colMax[3] = {0}, tempMax[3] = {0}, tempMin[3] ={0};
	int n, a;
	cin >> n;
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < 3; j++) {
			cin >> a;
			tempMin[j] = tempMax[j] = a;
			tempMax[j] += max(colMax[1], (j==1)?max(colMax[0], colMax[2]) : colMax[j]);
			tempMin[j] += min(colMin[1], (j==1)?min(colMin[0], colMin[2]) : colMin[j]);
		}
		memcpy(colMax, tempMax, sizeof(int) * 3);
		memcpy(colMin, tempMin, sizeof(int) * 3);
	}
	sort(colMax, colMax+3);
	sort(colMin, colMin + 3);
	cout << colMax[2] << " " << colMin[0];
	return 0;
}
