class MyCalendarTwo {
public:
    MyCalendarTwo() {
        
    }
    
    bool book(int start, int end) {
        timeline[start]++;
        timeline[end]--;
        int ongoing = 0;
        for(auto i:timeline){
            ongoing += i.second;
            if(ongoing > 2){
                timeline[start]--;
                timeline[end]++;
                return false;
            } 
        }
        return true;
    }
private:
    map<int, int> timeline;
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo obj = new MyCalendarTwo();
 * bool param_1 = obj.book(start,end);
 */
