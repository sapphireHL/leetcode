class Solution {
public:
    int myAtoi(string str) {
        int result = 0, sign = 1, i = 0;
		while (str[i] == ' ')
			i++;
		if (str[i] == '-'){
			sign = -1;
			i++;
		}
		else if (str[i] == '+')
			i++;
		for (; i < str.size(); i++){
			if (str[i]<'0' || str[i]>'9')
				break;
			if ((result>INT_MAX / 10) || (result == INT_MAX / 10 && (str[i] - '0') > INT_MAX % 10))
				return sign == 1 ? INT_MAX : INT_MIN;
			result = 10 * result + str[i] - '0';
		}
		return result*sign;
    }
};
