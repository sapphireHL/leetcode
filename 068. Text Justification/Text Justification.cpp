class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> res;
        queue<string> q;
        int len = maxWidth;
        for (int i = 0; i<words.size(); ){
            //如果有单词加一个空格
            if (!q.empty()) len--;
            //如果当前单词还能放进去
            if (len - (int)words[i].size() >= 0){
                q.push(words[i]);
                len -= words[i].size();
                i++;
            }
            //否则找到一行，输出
            else{
                string line;
                int wordsNumber = q.size();
                int spaces = len + q.size();
                int averageSpace = spaces;
                vector<int> space;
                //处理空格的个数
                if (q.size() > 1){
                    averageSpace = spaces / (q.size() - 1);
                    space.resize(q.size() - 1, averageSpace);
                }
                else
                    space.resize(1, averageSpace);
                //如果空格不能均分，左方的分得多一些
                if (q.size() >= 3 && averageSpace*(q.size() - 1) != spaces){
                    int rest = spaces - averageSpace*(q.size() - 1);
                    int j = q.size() - 2;
                    int extraSpace = 0;
                    while (rest % j != 0 && j >= 0){
                        j--;
                    }
                    extraSpace = rest / j;
                    for (int k = 0; k < j; k++)
                        space[k] += extraSpace;
                }
                //输出
                int j = 0, count = 0;
                while (!q.empty()){
                    string cur = q.front();
                    q.pop();
                    line += cur;
                    if(wordsNumber == 1 || !q.empty()){
                        for (int m = 0; m < space[count]; m++){
                            line += ' ';
                        }
                        count++;
                    }
                    j++;
                }
                res.push_back(line);
                len = maxWidth;
            }
        }
        //last line
        if (!q.empty()){
            string line;
            int wordsNumber = q.size();
            while (!q.empty()){
                string cur = q.front();
                q.pop();
                line += cur;
                if (!q.empty()) line += ' ';
            }
            for (int i = line.size(); i < maxWidth; i++)
                line += ' ';
            res.push_back(line);
        }
        return res;
    }
};
