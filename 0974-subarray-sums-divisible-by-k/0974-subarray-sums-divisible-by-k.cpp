class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int>freq(k , 0);
        freq[0] = 1;
        int sum = 0;
        int count = 0;

        for(int start = 0;start <n;start++) {
                sum += nums[start];
                int remainder = (sum % k) < 0? sum % k + k : sum % k;

                count += freq[remainder];
                freq[remainder]++;
            }

            return count;
 }
};

    

