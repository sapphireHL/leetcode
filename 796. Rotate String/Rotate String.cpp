class Solution {
public:
    bool rotateString(string A, string B) {
        deque<char> a(A.begin(), A.end());
        deque<char> b(B.begin(), B.end());
        for(int i = 0; i < a.size(); i++){
            a.push_back(a[0]);
            a.pop_front();
            if(a == b)
                return true;
        }
        return false;
    }
};
