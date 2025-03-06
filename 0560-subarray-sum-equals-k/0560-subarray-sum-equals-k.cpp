class Solution {
public:
    int subarraySum(vector<int>& nums, int k)
    {
        unordered_map<int , int>prefixSumMap;
        int count = 0 , sum =0;

        prefixSumMap[0] = 1;

        for(int num :nums) {
            sum+=num;

            if(prefixSumMap.find(sum-k) != prefixSumMap.end()) {
                count += prefixSumMap[sum - k];
            }
            prefixSumMap[sum]++;
        }
        return count;

    }
};



