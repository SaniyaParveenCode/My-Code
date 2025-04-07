class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> nextGreaterMap;
        stack<int> s;  
        for (int i = nums2.size() - 1; i >= 0; --i) {      
            while (!s.empty() && s.top() <= nums2[i]) {
                s.pop();
            }       
            if (!s.empty()) {
                nextGreaterMap[nums2[i]] = s.top();
            } else {            
                nextGreaterMap[nums2[i]] = -1;
            }        
         s.push(nums2[i]);
        }      
        vector<int> result;
        for (int num : nums1) {
            result.push_back(nextGreaterMap[num]);
        }       
        return result;
    }
};
 