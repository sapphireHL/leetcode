class Solution {
public:
    void dfs(vector<vector<int>>& image, int sr, int sc, int newColor, int originColor){
        if(sr < 0 || sr >= image.size() || sc < 0 || sc >= image[0].size()) return;
        if(image[sr][sc] != originColor) return;
        image[sr][sc] = newColor;
        dfs(image, sr-1, sc, newColor, originColor);
        dfs(image, sr+1, sc, newColor, originColor);
        dfs(image, sr, sc-1, newColor, originColor);
        dfs(image, sr, sc+1, newColor, originColor);
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        if(image[sr][sc] == newColor) return image;
        dfs(image, sr, sc, newColor, image[sr][sc]);
        return image;
    }
};
