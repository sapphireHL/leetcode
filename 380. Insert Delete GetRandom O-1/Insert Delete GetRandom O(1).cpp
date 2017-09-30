class RandomizedSet {
public:
	/** Initialize your data structure here. */
	unordered_map<int, int> set;
	vector<int> v;
	int count = 0, last = 0;
  
	RandomizedSet() {
		
	}

	/** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
	bool insert(int val) {
		if (set.count(val))
			return false;
		if (last >= v.size()) v.push_back(val);
		else v[last] = val;
		set[val] = last++;
		count++;
		return true;

	}

	/** Removes a value from the set. Returns true if the set contained the specified element. */
	bool remove(int val) {
		if (!set.count(val))
			return false;
    	//将要删除的元素和最后一个元素互换
		set[v[count-1]] = set[val];
		swap(v[count-1], v[set[val]]);
		last--;
		count--;
		set.erase(val);
		return true;
	}

	/** Get a random element from the set. */
	int getRandom() {
		int random = rand() % count;
		return v[random];
	}
};
    
/**
* Your RandomizedSet object will be instantiated and called as such:
* RandomizedSet obj = new RandomizedSet();
* bool param_1 = obj.insert(val);
* bool param_2 = obj.remove(val);
* int param_3 = obj.getRandom();
*/
