 static const int __ = [](){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();
class MyCircularDeque {
public:
    int size;
    vector<int>q;
    MyCircularDeque(int k) {
        q.clear();
        size = k;
    }
    
    bool insertFront(int value) {
        int s = q.size();
        if (s != size) {
            q.emplace (q.begin(), value);
            return true;
        }
        else return false;
    }
    
    bool insertLast(int value) {
        int s = q.size();
        if (s  != size) {
            q.push_back(value);
            return true;
        }
        return false;
    }
    
    bool deleteFront() {
        int s = q.size();
        if (s){
            q.erase(q.begin());
            return true;
        }
        return false;
    }
    
    bool deleteLast() {
        int s = q.size();
        if (s){
            q.pop_back();
            return true;
        }
        return false;
    }
    
    int getFront() {
        int s = q.size();
        if (s) return q.front();
        return -1;
    }
    
    int getRear() {
        int s = q.size();
        if (s) return q.back();
        return -1;
    }
    
    bool isEmpty() {
        int s = q.size();
        if (s) return false;
        return true;
    }
    
    bool isFull() {
        int s = q.size();
        if (size == s) return true;
        return false;
    }
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */