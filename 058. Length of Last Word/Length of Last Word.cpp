class Solution {
public:
    int lengthOfLastWord(string s) {
        stringstream ss(s);
        string temp, last;
        while(getline(ss, temp, ' ')){
            if(temp != "") last = temp;
        }
        return last.size();
    }
};
