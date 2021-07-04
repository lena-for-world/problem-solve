
// c++

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int N, K;
	int ans = 0;
	vector<int> sensor;
	vector<int> sums;
	cin >> N >> K;
	for(int i = 0; i < N; i++) {
		int temp;
		cin >> temp;
		sensor.push_back(temp);
	}
	if(sensor.size() <= K) cout << "0";
	else {
		sort(sensor.begin(), sensor.end());
		sensor.erase(unique(sensor.begin(), sensor.end()), sensor.end());
		for(int i = sensor.size()-1; i >= 1; i--) {
			sums.push_back(sensor[i] - sensor[i-1]);
		}
		sort(sums.begin(), sums.end());
		for(int i = 0; i < sums.size()-K+1; i++) {
			ans += sums[i];
		}
		cout << ans;
	}
	return 0;
}


// java

/* package whatever; // don't place package name! */

import java.util.*;
import java.lang.*;
import java.io.*;

/* Name of the class has to be "Main" only if the class is public. */
class Main
{
	public static void main (String[] args) throws java.lang.Exception
	{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int n = Integer.parseInt(br.readLine());
		int k = Integer.parseInt(br.readLine());
		StringTokenizer st = null;
		int[] sensor = new int[n];
		st = new StringTokenizer(br.readLine());
		for(int i = 0; i < n; i++) sensor[i] = Integer.parseInt(st.nextToken());
		ArrayList<Integer> arrayList = new ArrayList<>();
        for(int item : sensor){
            if(!arrayList.contains(item)) {
                arrayList.add(item);
            }
        }
		Collections.sort(arrayList);
		if(arrayList.size() <= k) System.out.print(0);
		else {
			int ans = 0;
			ArrayList<Integer> sumList = new ArrayList<>();
			for(int i = arrayList.size()-1; i >= 1; i--) {
				sumList.add(arrayList.get(i) - arrayList.get(i-1));
			}
			Collections.sort(sumList);
			for(int i = 0; i < sumList.size()-k+1; i++) ans += sumList.get(i);
			System.out.print(ans);
		}
	}
}
