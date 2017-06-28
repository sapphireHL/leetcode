class Solution {
public:
    int lengthOfLongestSubstring(string s) {
    //保存每个字符出现的位置
		vector<int> m(256,-1);
		int res = 0, start = 0;
		for (int i = 0; i < s.size();i++){
    //当字符重复时，开始位置变更为重复字符前一个位置的后面
			if(m[s[i]]!=-1){
			    start = max(start, m[s[i]]+1);
			}
      //更新位置
			m[s[i]] = i;
			res = max(res, i-start+1);
		}
		return res;
	}
};
