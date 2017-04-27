class Solution {
public:
    int strStr(string haystack, string needle) {
        int n = haystack.size()-needle.size();
        for(int i=0; i<=n; i++){
                int j=i, k=0;
                while(k<needle.size() && j<haystack.size() && needle[k] == haystack[j]){
                    j++;
                    k++;
                }
                if(k == needle.size()) return i;
        }
        return -1;
        
        
        // if(haystack.length() < needle.length()){
        //     return -1;
        // }
        // int res = 0;
        // int isfind = 0;
        // for(int i=0; i<=haystack.length()-needle.length(); i++){
        //     string str1 = haystack.substr(i, needle.length());
        //     if(!strcmp(str1.c_str(), needle.c_str())){
        //         res = i;
        //         isfind = 1;
        //         break;
        //     }
        //     else{
        //      isfind = 0;   
        //     }
        // }
        // return isfind?res:-1;
    }
};
