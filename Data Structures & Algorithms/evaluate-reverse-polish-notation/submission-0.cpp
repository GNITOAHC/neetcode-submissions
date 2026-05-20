class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        std::stack<std::string> stk;

        // https://en.wikipedia.org/wiki/Reverse_Polish_notation

        for (const std::string& s : tokens) {
            if (s == "+" || s == "-" || s == "*" || s == "/") {
                const int first = std::stoi(stk.top());
                stk.pop();
                const int second = std::stoi(stk.top());
                stk.pop();
                
                if (s == "+") stk.push(std::to_string(second + first));
                else if (s == "-") stk.push(std::to_string(second - first));
                else if (s == "*") stk.push(std::to_string(second * first));
                else if (s == "/") stk.push(std::to_string(second / first));
            } else {
                stk.push(s);
            }
        }

        return std::stoi(stk.top());
    }
};
