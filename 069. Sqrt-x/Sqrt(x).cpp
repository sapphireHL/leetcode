class Solution {
public:
	int mySqrt(int x) {
	    if(x<2) return x;
		int left = x / 2, right = x / 2, mid = 0;
		//left*left溢出！！
		while (left > x/left) {
			right = left;
			left /= 2;
		}
		while (right - left > 1){
			mid = left + (right - left) / 2;
			//mid*mid溢出！！
			if (mid > x/mid)
				right = mid;
			else left = mid;
		}
		return left;
	}
};
