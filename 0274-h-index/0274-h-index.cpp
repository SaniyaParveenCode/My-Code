class Solution {
public:
int hIndex(vector<int>& citations) {
vector<int> arr(citations.size() + 1, 0);
        int sum = 0;
        for (int i = 0; i < citations.size(); i++) {
            if (citations[i] > citations.size())
                arr[arr.size() - 1]++;
            else
                arr[citations[i]]++;
        }
        for (int i = arr.size() - 1; i >= 0; i--) {
            sum += arr[i];
            if (sum >= i)
                return i;
        }
        return 0;
    }
};