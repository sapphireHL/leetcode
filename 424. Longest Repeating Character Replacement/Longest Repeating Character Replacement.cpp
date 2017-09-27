class Solution {
public:
    int characterReplacement(string s, int k) {
        if(s.size() < 2) return s.size();
        int left = 0, right = 0, maxcount = 0, maxlen = 0;
        int count[26] = {0};
        for(; right < s.size(); right++){
            count[s[right]-'A']++;
            maxcount = max(maxcount, count[s[right]-'A']);
            
            //Since we are only interested in the longest valid substring, 
            //our sliding windows need not shrink, even if a window may cover an invalid substring. 
            //We either grow the window by appending one char on the right, 
            //or shift the whole window to the right by one. 
            //And we only grow the window when the count of the new char exceeds the historical max count
            
            if(right - left + 1 - maxcount > k){
                count[s[left]-'A']--;
                left++;
            }
            maxlen = max(maxlen, right - left + 1);
        }
        return maxlen;
    }
};
