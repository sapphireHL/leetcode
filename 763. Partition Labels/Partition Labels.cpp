class Solution {
public:
    bool completeRange(unordered_map<char, int>& numbersInRange, vector<int>& numbers){
        for(auto i = numbersInRange.begin(); i != numbersInRange.end(); i++){
            if(i->second != numbers[i->first - 'a'])
                return false;
        }
        return true;
    }
    
    vector<int> partitionLabels(string S) {
        vector<int> res;
        vector<int> numbers(26);
        int last = 0;
        for(int i = 0; i < S.size(); i++){
            numbers[S[i] - 'a']++;
        }
        
        unordered_map<char, int> numbersInRange;
        for(int i = 0; i < S.size(); i++){
            numbersInRange[S[i]]++;
            if(completeRange(numbersInRange, numbers)){
                numbersInRange.clear();
                res.push_back(i - last + 1);
                last = i + 1;
            }
        }
        return res;
    }
};
