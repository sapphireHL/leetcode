class Solution {
public:
    string minWindow(string s, string t) {
        if(s.empty() || s.size() < t.size()) return "";
        int appear_count[256] = {0};
        int expect_count[256] = {0};
        for(int i=0; i<t.size(); i++)
            expect_count[t[i]]++;
        int wnd_start = 0, wnd_end = 0;
        int min_len = INT_MAX, min_start  = 0;
        int appear = 0;//记录一个完整的t在s中出现
        for(; wnd_end < s.size(); wnd_end++){
            if(expect_count[s[wnd_end]] > 0){
                appear_count[s[wnd_end]]++;
                if(appear_count[s[wnd_end]] <= expect_count[s[wnd_end]])
                    appear++;
            }
            //包含整个t，前指针后移
            if(appear == t.size()){
                while(expect_count[s[wnd_start]] == 0 || appear_count[s[wnd_start]] > expect_count[s[wnd_start]]){
                    appear_count[s[wnd_start]]--;
                    wnd_start++;
                }
                if(wnd_end - wnd_start + 1 < min_len){
                    min_len = wnd_end - wnd_start + 1;
                    min_start = wnd_start;
                }
            }
        }
        if(min_len == INT_MAX) return "";
        return s.substr(min_start, min_len);
    }
};
