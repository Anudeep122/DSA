class MyQueue {
public:
    MyQueue() {
        
    }
    stack<int> st1;
    stack<int> st2;
    void push(int x) {
        st1.push(x);
    }
    
    int pop() {
        if(st2.size()==0){
            while(st1.size()){
                st2.push(st1.top());
                st1.pop();
            }
        }
        
        int y=st2.top();
        st2.pop();
        return y;
    }
    
    int peek() {
        if(st2.size()!=0){
            return st2.top();
        }
        else{
            while(st1.size()){
                st2.push(st1.top());
                st1.pop();
            }
            return st2.top();
        }
    }
    
    bool empty() {
        if(st1.size()==0 && st2.size()==0 ) return true;
        else return false;
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */