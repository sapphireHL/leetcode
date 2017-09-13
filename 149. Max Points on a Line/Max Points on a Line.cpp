/**
 * Definition for a point.
 * struct Point {
 *     int x;
 *     int y;
 *     Point() : x(0), y(0) {}
 *     Point(int a, int b) : x(a), y(b) {}
 * };
 */
class Solution {
public:
    int gcd(int a, int b){
        if(b == 0) return a;
        else return gcd(b, a%b);
    }
    string calculateAB(Point a, Point b){
        int A = a.x - b.x;
        int B = a.y - b.y;
        int g = gcd((A), (B));
        if(g){
            A /= g;
            B /= g;
        }
        string res = to_string(A)+"+"+to_string(B);
        return res;
    }
    int maxPoints(vector<Point>& points) {
        int res = 0;
        for(int i=0; i<points.size(); i++){
            int samePoints = 1, maxP = 0;
            unordered_map<string, int> m;
            for(int j=i+1; j<points.size(); j++){
                if(points[i].x == points[j].x && points[i].y == points[j].y)
                    samePoints++;
                else{
                    string slope = calculateAB(points[i], points[j]);
                    m[slope]++;
                }
            }
            for(auto i:m){
                maxP = max(maxP, i.second);
            }
            maxP += samePoints;
            res = max(res, maxP);
        }
        return res;
    }
};
