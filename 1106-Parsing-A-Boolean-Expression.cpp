class Solution {
public:
    bool parseBoolExpr(string expression) {
        stack<char> st;
        bool ans = false;
        for (auto& i : expression) {
            if (i != ')')
                st.push(i);
            else {
                int cnt_f = 0, cnt_ = 0;
                while (!st.empty() && st.top() != '(') {
                    if (st.top() == 'f')
                        cnt_f += 1;
                    else if (st.top() == 't')
                        cnt_ += 1;
                    st.pop();
                }
                if (!st.empty()) {
                    if (st.top() == '(')
                        st.pop();
                    if (st.empty())
                        continue;
                    if (st.top() == '|') {
                        st.pop();
                        if (cnt_ >= 1) {
                            st.push('t');
                        } else {
                            st.push('f');
                        }
                    } else if (st.top() == '&') {
                        st.pop();
                        if (cnt_ >= 1 && cnt_f == 0) {
                            st.push('t');
                        } else {
                            st.push('f');
                        }
                    } else {
                        if (st.top() == '!') {
                            st.pop();
                            if (cnt_f == 1 && cnt_ == 0) {
                                st.push('t');
                            } else {
                                st.push('f');
                            }
                        }
                    }
                }
            }
        }
        
        return st.top()== 't' ? true : false;
    }
};