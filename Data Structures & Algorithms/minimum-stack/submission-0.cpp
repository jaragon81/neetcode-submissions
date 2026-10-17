class MinStack {
public:
    MinStack() {
        
    }
    
    void push(int val) {
        stck.push_back(val);
    }
    
    void pop() {
        stck.pop_back();
    }
    
    int top() {
        return stck.back();
    }
    
    int getMin() {
        return *std::min_element(stck.begin(), stck.end());
    }

    std::list<int> stck;
};
