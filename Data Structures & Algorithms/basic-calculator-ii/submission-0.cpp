class Solution {
public:
    int calculate(string s) {
        // two stack approach
        stack<int> operands;
        stack<char> operators;
        int cur = 0;

        auto should_pop = [&](char c) -> bool {
            if (operators.empty()) return false;
            if (c == '+' || c == '-') return true;
            return operators.top() == '*' || operators.top() == '/';
        };
        auto cal = [&]() -> void {
            const int b = operands.top(); operands.pop();
            const int a = operands.top(); operands.pop();
            const char op = operators.top(); operators.pop();
            switch (op) {
                case '+': operands.push(a + b); break;
                case '-': operands.push(a - b); break;
                case '*': operands.push(a * b); break;
                case '/': operands.push(a / b); break;
            }
            return;
        };

        for (const auto c : s) {
            if (c == ' ') continue;
            if ('0' <= c && c <= '9') {
                cur = cur * 10 + (c - '0');
                continue;
            }
            // encounter an operator
            operands.push(cur);
            cur = 0;
            while (should_pop(c))
                cal();
            operators.push(c);
        }

        // clean up
        operands.push(cur);
        while (!operators.empty()) cal();
        return operands.top();
    }
};
