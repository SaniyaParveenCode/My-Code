class Solution {
public:
    int check(vector<int>& tops, vector<int>& bottoms, int target) {
        int rotationTop = 0, rotationBottom = 0;

        for (int i = 0; i < tops.size(); ++i) {
            if(tops[i] != target && bottoms[i] != target) return -1;
            if(tops[i] != target) rotationTop++;
            if(bottoms[i] != target) rotationBottom++;
        }

        return min(rotationTop, rotationBottom);
    }

    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        int result = check(tops, bottoms, tops[0]);
        if(result != -1) return result;
        return check(tops, bottoms, bottoms[0]);
    }
};