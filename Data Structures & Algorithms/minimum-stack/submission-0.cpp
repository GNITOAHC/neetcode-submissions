class MinStack {
public:
    // O(1) time complexity for each function & O(n) space complexity
    std::stack<int> stk;
    std::stack<int> stk_min; // Stores the minimum value at that level
    MinStack() {}
    
    void push(int val) {
        stk.push(val);
        if (stk_min.empty()) {
            stk_min.push(val);
        } else {
            stk_min.push(std::min(val, stk_min.top()));
        }
    }
    
    void pop() {
        stk.pop();
        stk_min.pop();
    }
    
    int top() {
        return stk.top();
    }
    
    int getMin() {
        return stk_min.top();
    }
};
