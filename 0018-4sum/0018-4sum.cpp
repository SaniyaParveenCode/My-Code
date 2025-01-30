class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();

        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());

        set<vector<int>> uniqueSets;

        for(int i = 0; i < n; i++){
            for(int j = i + 1; j < n; j++){
                int k = j + 1;
                int l = n - 1;

                while(k < l){
                    long long sum = static_cast<long long>(nums[i]) + nums[j] + nums[k] + nums[l];

                    if(sum == target){
                        vector<int> quadruplet = {nums[i], nums[j], nums[k], nums[l]};
                        uniqueSets.insert(quadruplet);
                        k++;
                        l--;
                    }
                    else if(sum < target) k++;
                    else if(sum > target) l--;
                }
            }
        }
        
        ans.assign(uniqueSets.begin(), uniqueSets.end());
        return ans;
    }
};