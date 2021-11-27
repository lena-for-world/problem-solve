#include <iostream>
#include <vector>
using namespace std;

// max - 배열에 존재하는 가장 큰 수
// counts <- counts의 idx는 v배열에 존재하는 가장 큰 수
// counts는 for문 돌면서 누적합으로 변경됨
// counts의 각 누적치는 결과 배열인 sorted에 위치할 idx와 같음

int main() {
	int max = 5;
	int nums[11] = {1,0,1,5,4,3,1,4,5,2,1};
	int len = 11;
	int* counts = new int[max+1]; // max라는 idx에 값을 할당할 수 있어야 
	int* sorted = new int[len];
	
	for(int i = 0; i < len; i++) {
		++counts[nums[i]];
	}
	
	for(int i = 1; i <= max; i++) {
		counts[i] += counts[i-1];
	}
	
	for(int i = 0; i< len; i++) {
		sorted[--counts[nums[i]]] = nums[i];
		cout << nums[i] << " " << counts[nums[i]]+1 << endl;
	}
	
	for(int i = 0; i < len; i++) {
		cout << sorted[i] << " ";
	}
	return 0;
}
