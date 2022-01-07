import java.lang.reflect.Array;
import java.util.*;
import java.io.*;

public class Main {

    public static void main(String[] args) throws IOException {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String sts = br.readLine();
        String [] arr = sts.split(" ");
        int N = Integer.parseInt(arr[0]);
        int M = Integer.parseInt(arr[1]);

        int count = 0;

        Map<String, Integer> map = new HashMap<>();

        for(int i = 0 ; i < N; i++) {
            map.put(br.readLine(), 1);
        }

        for (int i = 0; i < M; i++) {
            String st = br.readLine();
            if(map.containsKey(st)) {
                count++;
            }
        }

        System.out.println(count);

    }

}
