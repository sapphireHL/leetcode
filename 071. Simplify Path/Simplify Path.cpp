class Solution {
public:
    string simplifyPath(string path) {
        string res, temp;
        vector<string> stack;
        stringstream ss(path);
        //getline works as split
        while(getline(ss, temp, '/')){
            if(temp == "" || temp == ".") continue;
            if(temp == ".." && !stack.empty())  stack.pop_back();
            else if(temp != "..") stack.push_back(temp);
        }
        for(int i=0; i<stack.size(); i++){
            res += "/"+stack[i];
        }
        return res.empty()?"/":res;
    }
};
