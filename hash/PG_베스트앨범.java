import java.util.*;
import java.util.Map.Entry;
import java.io.*;

class Genre implements Comparable<Genre> {
    int music;
    int played;

    Genre() {

    }

    Genre(int music, int played) {
        this.music = music;
        this.played = played;
    }

    public int getMusic() {
        return music;
    }

    public int getPlayed() {
        return played;
    }

    @Override
    public int compareTo(Genre g1) {
        if(g1.getPlayed() == getPlayed()) {
            // 고유번호 -- 오름차순
            return getMusic() - g1.getMusic();
        } else {
            // 노래 재생 횟수 -- 내림차순
            return g1.getPlayed() - getPlayed();
        }
    }
}

class Solution {
    public int[] solution(String[] genres, int[] plays) {
        List<Integer> anslist = new ArrayList<>();
        Map<String, Integer> genreTotal = new HashMap<>();
        Map<String, List<Genre>> genreMusic = new HashMap<>();
        for(int i = 0; i < genres.length; i++) {
            if(genreTotal.containsKey(genres[i])) {
                // 각 장르에 재생횟수 더한 값을 value로
                genreTotal.put(genres[i], genreTotal.get(genres[i])+plays[i]);
            } else {
                genreTotal.put(genres[i], plays[i]);
            }
        }
        for (int i = 0; i < plays.length; i++) {
            if(genreMusic.containsKey(genres[i])) {
                genreMusic.get(genres[i]).add(new Genre(i, plays[i]));
            } else {
                genreMusic.put(genres[i], new ArrayList<>());
                genreMusic.get(genres[i]).add(new Genre(i, plays[i]));
            }
        }
        // Map to List (map의 value값으로 정렬하기 위해)
        List<Entry<String, Integer>> entries = new ArrayList<>(genreTotal.entrySet());
        // value로 내림차순 정렬
        Collections.sort(entries, new Comparator<Entry<String, Integer>>() {
            @Override
            public int compare(Entry<String, Integer> o1, Entry<String, Integer> o2) {
                return o2.getValue().compareTo(o1.getValue());
            }
        });
        for(String key : genreMusic.keySet()) {
            // 객체 리스트 정렬
            Collections.sort(genreMusic.get(key));
        }
        int i = 0;
        for(Entry<String, Integer> entry : entries) {
            anslist.add(genreMusic.get(entry.getKey()).get(0).getMusic());
            if(genreMusic.get(entry.getKey()).size() >= 2) {
                anslist.add(genreMusic.get(entry.getKey()).get(1).getMusic());
            }
        }
        // Integer list to primitive array
        int[] answer = anslist.stream().mapToInt(v->v).toArray();
        return answer;
    }
}
