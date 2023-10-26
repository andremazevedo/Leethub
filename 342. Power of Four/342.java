class Solution {
    public boolean isPowerOfFour(int n) {
        if (n == 1)
            return true;

        if (n == 0 || (n & 3) != 0)
            return false;

        return isPowerOfFour(n >> 2);
    }
}



class Main {
    public static void main(String args[]) { 
        int n = 64;

        System.out.println("Input: n = " + n);

        System.out.println("output: " + new Solution().isPowerOfFour(n));
    } 
}
