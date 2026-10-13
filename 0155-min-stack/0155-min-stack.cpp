
class MinStack {
public:
    long long minm = LLONG_MAX;
    stack<long long> st;

    MinStack() {
    }

    void push(int value) {
        if(st.empty()) {
            st.push(value);
            minm = value;
        }
        else if(value < minm) {
            long long x = 2LL * value - minm;
            st.push(x);
            minm = value;
        }
        else {
            st.push(value);
        }
    }

    void pop() {
        if(st.empty()) return;

        if(st.top() < minm) {
            minm = 2LL * minm - st.top();
        }

        st.pop();

        if(st.empty()) {
            minm = LLONG_MAX;
        }
    }

    int top() {
        if(st.empty()) return -1;

        if(st.top() < minm) {
            return (int)minm;
        }

        return (int)st.top();
    }

    int getMin() {
        if(st.empty()) return -1;
        return (int)minm;
    }
};
