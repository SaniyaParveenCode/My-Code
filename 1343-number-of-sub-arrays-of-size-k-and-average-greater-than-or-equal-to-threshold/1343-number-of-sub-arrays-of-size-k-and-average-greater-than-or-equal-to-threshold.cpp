class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        
        int n = arr.size();

        int left =0 , right = 0 , ans = 0 , windowSum = 0;
        // int  windowsize = right - left +1;

         while(right < n) {
            // Add the current element to the window sum
            windowSum+= arr[right];

           // Check if the window size is equal to k
            if(right - left +1 == k) {
             if (windowSum / k >= threshold) 
            {
                    ans++;
            }

             // Slide the window: subtract the element going out and      move left pointer

            windowSum -= arr[left];
            left++;
            }
            right++;
         }
         return ans;
    }
};
