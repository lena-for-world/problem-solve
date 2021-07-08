import java.util.*;
import java.lang.*;
import java.io.*;


/* Name of the class has to be "Main" only if the class is public. */
class Main
{
	static boolean func(int dist, int[] arr, int C) {
		int cnt = 1;
		long now = arr[0];
		int asize = arr.length;
		for(int i = 0; i < asize; i++) {
			if(now + dist <= arr[i]) {
				cnt++;
				now = arr[i];
			}
		}
		return cnt >= C;
	} 
	public static void main (String[] args) throws java.lang.Exception
	{
		int N, C, ans = 1;
		Scanner sc = new Scanner(System.in);
		N = sc.nextInt();
		C = sc.nextInt();
		int[] arr = new int[N];
		for(int i = 0;i< N; i++) {
			arr[i] = sc.nextInt();
		}
		Arrays.sort(arr);
		int low = 1, high = arr[N-1]-arr[0];
		while(low <= high) {
			int mid = (low + high) / 2;
			if(func(mid, arr, C)) {
				ans = Math.max(ans,mid);
				low = mid + 1;
			}
			else high = mid-1;
		}
		System.out.println(ans);
	}
}
