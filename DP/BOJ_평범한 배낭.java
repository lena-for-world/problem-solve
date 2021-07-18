/* package whatever; // don't place package name! */

import java.util.*;
import java.lang.*;
import java.io.*;

/* Name of the class has to be "Main" only if the class is public. */
class Main
{
	static int[] w;
	static int[] v;
	static int[][] bag;
	static int N, K;
	
	public static int func(int n, int k) {
		if(n == N) return 0;
		if(bag[n][k] != -1) return bag[n][k];
		if(w[n] > k) bag[n][k] = func(n+1, k);
		else bag[n][k] = Math.max(func(n+1, k), func(n+1, k-w[n])+v[n]);
		return bag[n][k];
	}
	
	public static void main (String[] args) throws java.lang.Exception
	{
		Scanner sc = new Scanner(System.in);
		N= sc.nextInt(); K = sc.nextInt();
		w = new int[N+1];
		v = new int[N+1];
		bag = new int[N+1][K+1];
		for(int i = 0; i < N; i++) {
			w[i] = sc.nextInt();
			v[i] = sc.nextInt();
		}
		for(int i = 0; i <= N; i++)
			for(int j = 0; j <= K; j++)
				bag[i][j] = -1;
		int ans = func(0, K);
		System.out.print(ans);
	}
}
