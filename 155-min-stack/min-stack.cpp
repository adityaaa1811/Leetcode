class MinStack {
public:
    stack<long long> st;
    long long minVal;

    MinStack() {
        minVal = 0;
    }

    void push(int value) {
        if (st.empty()) {
            minVal = value;
            st.push(value);
        }
        else if (value > minVal) {
            st.push(value);
        }
        else {
            st.push(2LL * value - minVal);
            minVal = value;
        }
    }

    void pop() {
        if (st.empty()) return;

        long long x = st.top();
        st.pop();

        if (x < minVal) {
            minVal = 2 * minVal - x;
        }
    }

    int top() {
        if (st.empty()) return -1;

        long long x = st.top();

        if (x < minVal) {
            return minVal;
        }

        return static_cast<int>(x);
    }

    int getMin() {
        return static_cast<int>(minVal);
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(value);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */