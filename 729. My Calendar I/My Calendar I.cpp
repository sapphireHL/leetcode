class MyCalendar {
public:
    vector<pair<int, int>> vec;
    MyCalendar() {
        
    }
    
    bool book(int start, int end) {
        for(int i=0; i<vec.size(); i++){
            if(start >= vec[i].first && start <= vec[i].second)
                return false;
            if(end - 1 >= vec[i].first && end - 1 <= vec[i].second)
                return false;
            if(start <= vec[i].first && end - 1 >= vec[i].second)
                return false;
        }
        vec.push_back(pair<int, int>(start, end-1));
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar obj = new MyCalendar();
 * bool param_1 = obj.book(start,end);
 */
