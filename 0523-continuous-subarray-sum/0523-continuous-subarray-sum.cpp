class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int currSum = 0;

        unordered_map<int , int>remaindersFound;

        remaindersFound[0] = -1;

        for(int i=0;i<nums.size();i++) {
            currSum += nums[i];
             int remainder = currSum % k;
             if(remainder < 0) remainder+=k;

            if(remaindersFound.find(remainder) != remaindersFound.end()) {
                if(i - remaindersFound[remainder] >=2) {
                    return true;
                }
}
                else {
                        remaindersFound[remainder] = i;
                }
            }
            return false;

    }
};

