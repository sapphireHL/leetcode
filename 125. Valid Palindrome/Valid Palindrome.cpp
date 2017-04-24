class Solution {
public:
    bool isAlpha(char a){
        if((a>='a'&&a<='z') || (a>='A'&&a<='Z') || (a>='0'&&a<='9')){
            return 1;
        }
        return 0;
    }
    bool isPalindrome(string s) {
        transform(s.begin(), s.end(), s.begin(), ::tolower);
        int left = 0, right = s.size()-1;
        while(left < right){
            if(!isAlpha(s[left])) left++;
            else if(!isAlpha(s[right])) right--;
            else if((s[left] == s[right])){
                left++;
                right--;
            }
            else return false;
        }
        return true;
    }
};
