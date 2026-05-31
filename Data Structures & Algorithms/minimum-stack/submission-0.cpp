class MinStack {
    stack<int> m_stack;
    stack<int> r_stack;
public:
    MinStack() {}
    
    void push(int val) {
        if(m_stack.empty()){
            m_stack.push(val);
            r_stack.push(val);
        }
            
        else{
            r_stack.push(min(r_stack.top(), val));
            m_stack.push(val);
        }
    }
    
    void pop() {
        m_stack.pop();
        r_stack.pop();
        
    }
    
    int top() {
        return m_stack.top();
    }
    
    int getMin() {
        return r_stack.top();
    }
};