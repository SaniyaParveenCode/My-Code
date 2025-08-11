class Solution {
public:
    string addBinary(string a, string b) {
        int n = a.size();
        int m = b.size();
        int carry = 0;
        string result = "";

        int i = n-1 , j = m-1;
        while(i>=0 || j>=0||carry>0) {
            int bitA = (i>=0) ? a[i--] - '0' : 0;
            int bitB = (j>=0) ? b[j--] - '0' : 0;

            int sum = bitA + bitB + carry;
            result+=(sum%2) + '0';
            carry = sum/2;
        }
        reverse(result.begin() , result.end());
        return result;
    }
};