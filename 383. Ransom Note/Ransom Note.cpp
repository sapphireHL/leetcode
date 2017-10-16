class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int size1 = ransomNote.length();
        int size2 = magazine.length();
        unordered_map<char, int> mp1, mp2;
        for(char ch : magazine) mp1[ch]++;
        for(char ch : ransomNote) mp2[ch]++;
        for(auto i :mp2){
            if(i.second > mp1[i.first]) return false;
        }
        return true;
    }
};
