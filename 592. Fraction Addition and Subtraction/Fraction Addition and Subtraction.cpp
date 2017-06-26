class Solution {
public:
	int gcd(int a, int b){
		if (a == 0) return b;
		if (b == 0) return a;
		return gcd(b, a%b);
	}
	string fractionAddition(string expression) {
		//a/b+c/d=ad+bc/bd
		int sign = 1, a = 0, b = 0, c = 0, d = 0, start = 0;
		string res;
		if (expression[0] == '-') {
			start = 1;
			sign = -1;
		}
		if (expression[start + 1] == '0'){ a = sign*10; start++; }
		else a = sign*(expression[start]-'0');
		if (start + 3 < expression.size() && expression[start + 3] == '0'){ b = 10; start++; }
		else b = expression[start + 2] - '0';
		start += 3;
		while (start < expression.size()){
			if (expression[start] == '-') sign = -1;
			else sign = 1;
			start++;
			if (expression[start + 1] == '0'){ c = sign * 10; start++; }
			else c = sign*(expression[start] - '0');
			if (start + 3 < expression.size() && expression[start + 3] == '0'){ d = 10; start++; }
			else d = expression[start + 2] - '0';
			a = a*d + b*c;
			b = b*d;
			start += 3;
		}
		int g = abs(gcd(a, b));
		res += to_string(a/g) + "/" + to_string(b/g);
		return res;
	}
};
