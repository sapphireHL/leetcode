class Solution {
public:
	double myPow(double x, int n) {
		if (n == 0) return 1;
		double v = myPow(x, n / 2);
		if (n % 2 == 0)
			return v*v;
		else
			return n < 0 ? 1 / x*v*v : x*v*v;
	}
};
