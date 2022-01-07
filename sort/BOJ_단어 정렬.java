import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;
import java.util.*;

public class Main {

    public static void main(String[] args) throws IOException {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int N = Integer.parseInt(br.readLine());
        String[] sts = new String[N];
        for (int i = 0; i < N; i++) {
            sts[i] = br.readLine();
        }

        Set<String> set = new HashSet<String>(Arrays.asList(sts));
        // 또는 ArrayList->List로 변환 후 Stream 사용하여 중복  : newList.stream().distinct().collect(Collectors.toList());

        List<String> newList = new ArrayList<String>(set);

        Collections.sort(newList, new Comparator<String>() {
            @Override
            public int compare(String o1, String o2) {
                if(o1.length() == o2.length()) {
                    return o1.compareTo(o2);
                } else {
                    return o1.length() - o2.length();
                }
            }
        });

        for (int i = 0; i < newList.size(); i++) {
            System.out.println(newList.get(i));
        }
    }

}
