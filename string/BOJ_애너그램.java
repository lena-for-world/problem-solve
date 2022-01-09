import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;

public class Main {

    private static boolean solveAnagrams(String s1, String s2 ) {
        /* ------------------- INSERT CODE HERE --------------------
         *
         * Your code should return true if the two strings are anagrams of each other.
         *
         * */
        boolean flag = true;
        int [] alp = new int[26];
        for(int j = 0; j < s1.length(); j++) {
            alp[s1.charAt(j)-'a']++;
        }
        for(int j = 0; j < s2.length(); j++) {
            alp[s2.charAt(j)-'a']--;
        }
        for(int j = 0; j < 26; j++) {
            if(alp[j] != 0) flag = false;
        }
        return flag;

        /* -------------------- END OF INSERTION --------------------*/
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int numTests = sc.nextInt();

        for (int i = 0; i < numTests; i++) {
            String first = sc.next().toLowerCase();
            String second = sc.next().toLowerCase();
            System.out.println(first + " & " + second + " are " + (solveAnagrams(first, second) ? "anagrams." : "NOT anagrams."));
        }
    }
}
