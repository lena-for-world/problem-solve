#include <iostream>
#include<vector>
#include <queue>
using namespace std;

int solution(vector<int> A, vector<int> B)
{
    int answer = 0;
	priority_queue<int> pq; // bigger
	priority_queue<int, vector<int>, greater<int>> spq;
    for(int i = 0;i < A.size(); i++) {
        pq.push(A[i]);
    }
    for(int j = 0; j < B.size(); j++) {
        spq.push(B[j]);
    }
    for(int i = 0; i < A.size(); i++) {
        int temp = pq.top() * spq.top();
        pq.pop();
        spq.pop();
        answer += temp;
    }
    return answer;
}
