import java.util.*;

class Solution {
    public String[] sortPeople(String[] names, int[] heights) {
        String[] answer = new String[names.length];
        HashMap<Integer, String> hashmap = new HashMap<>();
    
        for (int i = 0; i < names.length; i++) {
            hashmap.put(heights[i], names[i]);
        }

        Arrays.sort(heights);

        for (int i = heights.length - 1; i >= 0; i--) {
            answer[heights.length - 1 - i] = hashmap.get(heights[i]);
        }

        return answer;
    }

    public static void main(String[] args) {
        String[] names = {"Mike", "John", "Emma"};
        int[] heights = {180, 165, 170};

        System.out.println("Input: names = " + Arrays.toString(names) + ", heights = " + Arrays.toString(heights));

        System.out.println("Output: " + Arrays.toString(new Solution().sortPeople(names, heights)));
    }
}