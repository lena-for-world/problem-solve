import java.util.*;
import java.lang.*;
import java.io.*;

// c++로 풀어봤던 문제인데 java로 다시 풀려고 하니까 너무 복잡하다... 자바^^...

class Conference {
	int s;
	int e;
	Conference(int s, int e) {
		this.s = s;
		this.e = e;
	}
	public int getS() { return this.s; }
	public int getE() { return this.e; }
}

/* Name of the class has to be "Main" only if the class is public. */
class Main
{
	public static void main (String[] args) throws java.lang.Exception
	{
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt();
		List<Conference> list = new ArrayList<>();
		int start;
		int end;
		for(int i =0; i< N; i++) {
			start = sc.nextInt();
			end = sc.nextInt();
			Conference con = new Conference(start, end);
			list.add(con);
		}
		Comparator<Conference> com = new Comparator<Conference>() {
			@Override
			public int compare(Conference c1, Conference c2) {
				if(c2.s - c1.s == 0) return c2.e - c1.e;
				else return c2.s - c1.s;
			}
		};
		Collections.sort(list, com);
		int i = 1;
		int sum = 1;
		int endtime = list.get(0).getS();
		while(i < list.size()) {
			if(list.get(i).getE() <= endtime) {
				endtime = list.get(i).getS();
				sum++;
			}
			i++;
		}
		System.out.print(sum);
	}
}
