class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
      int size = digits.size();
    	vector<int> res = digits;
    	int step = 0;
    	res[size-1] += 1;
    	for(int i=size-1; i>=0; i--){
    	    res[i] += step;
    	    step = 0;
    	    if(res[i] >= 10){
    	        res[i] -= 10;
    	        step = 1;
    	    }
    	}
    	if(step == 1){
    	    res.insert(res.begin(), 1);
    	}
    	return res;
    }
};
