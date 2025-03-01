class Solution {
public:
    int countSeniors(vector<string>& details) {
        int count = 0;
        for(const string& detail :details) {
            string age = detail.substr(11,2);
            int ageVal = std::stoi(age);
            if(ageVal>60) {
                count++;
            }
        }
        return count;
    }
};

