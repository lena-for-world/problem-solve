/* package whatever; // don't place package name! */

import java.util.*;
import java.lang.*;
import java.io.*;

/* Name of the class has to be "Main" only if the class is public. */
class Main
{
	public static void main (String[] args) throws java.lang.Exception
	{
		int N, t;
		Scanner sc = new Scanner(System.in);
		N = sc.nextInt();
		int[] arr = new int[N];
		for(int i = 0; i < N; i++) {
			arr[i] = sc.nextInt();
		}
		t = sc.nextInt();
		int[] arrt = new int[t];
		for(int j = 0; j < t; j++) {
			arrt[j] = sc.nextInt();
		}
		Arrays.sort(arr);
		for(int i = 0; i < t; i++) {
			int obj = arrt[i];
			int flag = 1;
			int low = 0, high = N-1;
			while(low <= high) {
				int mid = (low+high) / 2;
				if(arr[mid] == obj) {
					System.out.println(1);
					flag = 0;
					break;
				}
				else if(arr[mid] > obj) {
					high = mid-1;
				}
				else {
					low = mid+1;
				}
			}
			if(flag==1) System.out.println(0);
		}
	}
}
