class Solution {
public:
    string removeKdigits(string num, int k) {
        int n=num.length();
        int i=0;
        stack <int> st;
        while(i<n){
            while(!st.empty() && k>0 && (st.top()>(num[i]-'0'))){
                st.pop();
                k--;
            }
            if(i<n) st.push(num[i]-'0');
            i++;
        }
        while(!st.empty() && k>0 ) {st.pop();k--;}

        string s="";
        while(!st.empty()){
            s.push_back(char(st.top()+'0'));
            st.pop();
        }
        if(s.size()==0 ) return "0";
        int j=s.size()-1;
        while(s[j]=='0' && s.length()!=1){
            s.pop_back();j--;
        }
        reverse(s.begin(),s.end());
        return s;

    }
};