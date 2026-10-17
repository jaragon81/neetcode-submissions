class MinStack {
public:
    MinStack() {
        min = std::numeric_limits<int>::max();
    }
    
    void push(int val) {
        min = std::min(min, val);
        stck.push({val, min});
    }
    
    void pop() {
        stck.pop();
        if (!stck.empty())
            min = stck.top().second;
        else
            min = std::numeric_limits<int>::max();
    }
    
    int top() {
        return stck.top().first;
    }
    
    int getMin() {
        return stck.top().second;
    }

    std::stack<std::pair<int, int>> stck;
    int min;
};
