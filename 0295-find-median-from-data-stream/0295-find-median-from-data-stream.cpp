class MedianFinder {
private:
    priority_queue<int> ma_pq; // max heap
    priority_queue<int, vector<int>, greater<int>> mi_pq; // min heap
    int cnt;

public:
    MedianFinder() {
        cnt = 0;
    }
    
    void addNum(int num) {
        cnt++;

        if (!mi_pq.empty() && mi_pq.top() <= num)
            mi_pq.push(num);
        else
            ma_pq.push(num);

        while (ma_pq.size() > mi_pq.size() + 1) {
            mi_pq.push(ma_pq.top());
            ma_pq.pop();
        }

        while (mi_pq.size() > ma_pq.size()) {
            ma_pq.push(mi_pq.top());
            mi_pq.pop();
        }
    }
    
    double findMedian() {
        if (cnt % 2 == 0) {
            return (double)(ma_pq.top() + mi_pq.top()) / 2.0;
        }
        else {
            return 1.0 * ma_pq.top();
        }
    }
};