class Solution {
    public int countKSubsequencesWithMaxBeauty(String s, int k) {
        int[] freq = new int[26];
        for (char ch : s.toCharArray()) {
            freq[ch-'a']++;
        }
        Arrays.sort(freq);
        int i=0;
        int j = 25;
        while(i<j){
            int temp = freq[i];
            freq[i++] = freq[j];
            freq[j--] = temp;
        }
        if(k>26 || freq[k-1]==0){
            return 0;
        }
        int element = freq[k-1];
        int pending = 0;

        for (i = 0; i < freq.length; i++) {
            if (freq[i] == element) {
                pending++;
            }
        }
        long totalFreq = 1;
        int bar = 0;
        int idx = k;
        for (i = 0; i < idx; i++) {
            if (element > freq[i] || freq[i]==0) {
                break;
            }
            else if(element < freq[i]){
                k--;
            }
            totalFreq = (totalFreq*freq[i]) % 1000000007;
            bar++;
        }
        totalFreq*=combinations(pending, k);
        return (int)(totalFreq % 1000000007);
    }
    
    public static long combinations(int n, int r) {
        long ans = 1;
        long temp = 1;
        long temp1 = 1;
        r = Math.min(r,n-r);
        for(int i=0; i<r; i++){
            temp *= (n-i);
            temp1 *= (i+1);
        }
        ans = (temp/temp1) % 1000000007;

        return ans;
    }
}