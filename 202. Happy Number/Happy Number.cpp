class Solution {
public:
    bool isHappy(int n) {
        int sum = 0;
        map<int, int> m;
     	while (1)
    	{
    	    if(sum == 1)
    	        return 1;
    		sum = 0;
    		while (n != 0 )
    		{
    			sum += (n%10) * (n%10);
    			n /= 10;
    		}
    		n = sum;
    		if(m[sum] == 1)
    		    return false;
    		m[sum] = 1;
    	}
    }
};
