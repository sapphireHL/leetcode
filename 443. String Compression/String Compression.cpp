class Solution {
public:
    int compress(vector<char>& chars) {
        int index = 0, count = 1;
        char cur = chars[0];
        bool flag = true;
        for(int i=1; i<chars.size(); i++){
            if(chars[i] == cur){
                count++;
            }
            else{
                chars[index++] = cur;
                cur = chars[i];
                if(count > 1){
                    string number = to_string(count);
                    for(int j=0; j<number.size(); j++){
                        chars[index++] = number[j];
                    }
                    count = 1;
                }
            }
        }
        chars[index++] = cur;
        if(count > 1){
            string number = to_string(count);
            for(int j=0; j<number.size(); j++){
                chars[index++] = number[j];
            }
        }
        return index;
    }
};
