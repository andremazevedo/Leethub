import java.util.*;

class Solution {
    public int[] frequencySort(int[] nums) {
        HashMap<Integer, Integer> hashmap = new HashMap<>();

        for (int num : nums) {
            hashmap.put(num, hashmap.getOrDefault(num, 0) + 1);
        }

        return Arrays.stream(nums)
                     .boxed()
                     .sorted((a, b) -> hashmap.get(a) == hashmap.get(b) ? b - a : hashmap.get(a) - hashmap.get(b))
                     .mapToInt(i -> i)
                     .toArray();
    }

    public static void main(String[] args) {
        int[] nums = {1, 1, 2, 2, 2, 3};

        System.out.println("Input: nums = " + Arrays.toString(nums));

        System.out.println("Output: " + Arrays.toString(new Solution().frequencySort(nums)));
    }
}
