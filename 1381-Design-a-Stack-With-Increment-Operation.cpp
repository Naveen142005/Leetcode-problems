static const int __ = [](){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();
class CustomStack {
public:
    vector<int> stk;
    int size;
    CustomStack(int maxSize) {
        size = maxSize;
    }
    void push(int x) {
        if (stk.size() != size) {
            stk.push_back(x);
        }
    }
    
    int pop() {
        if (!stk.size())
            return -1;
        int val = stk.back();
        stk.pop_back();
        return val;
    }
    
    void increment(int k, int val) {
        for (int i = 0 ; i < k && i < stk.size(); i++) {
            stk[i] += val;
        }
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */