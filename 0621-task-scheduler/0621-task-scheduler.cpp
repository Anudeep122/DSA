class Solution {
public:
    int leastInterval(vector<char>& v, int n) {
        map<char,int> mp;
        for(auto it : v)mp[it]++;

        priority_queue<int> pq;
        for(auto it : mp)pq.push(it.second);

        int ans = 0;
        while(!pq.empty()){
            int batch = n+1;
            stack<int> st;

            while(batch>0){
                if(pq.empty()){
                    if(!st.empty())ans += batch;
                    break;
                }
                int x = pq.top();
                pq.pop();
                ans++;
                x--;
                if(x>0)st.push(x);
                batch--;
            }

            while(!st.empty()){
                pq.push(st.top());
                st.pop();
            }
        }

        return ans;
    }
};