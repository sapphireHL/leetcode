class Solution {
public:
    bool isSubStringSame(string str, int i, int j, int length){
        for(int k=0; k<length; k++){
            if(str[i+k] != str[j+k]){
                return false;
            }
        }
        return true;
    }
    
    bool repeatedSubstringPattern(string str) {
        int repeatlength = 0;
        for(int i=str.length()/2; i>=1; i--){
            string str1 = str.substr(0, i);
            string str2 = str.substr(str.length()-i, str.length()-1);
            if(!strcmp(str1.c_str(), str2.c_str())){
                repeatlength = i;
                if(str.length()%repeatlength != 0){
                    continue;
                }
                break;
            }
        }
        cout<<repeatlength<<endl;
        if(!repeatlength){
            return false;
        }
        for(int i=0; i<str.length()-repeatlength; i+=repeatlength){
            if(!isSubStringSame(str, i, i+repeatlength, repeatlength)){
                return false;
            }
        }
        return true;
    }
};
