class MedianFinder {
public:
    priority_queue<int> max; // left side (max-heap)
    priority_queue<int, vector<int>, greater<int>> min; // right side (min-heap)

    MedianFinder() {

    }

    void addNum(int num) {

        if(max.empty() || num <= max.top())
        {
            max.push(num);
        }
        else
        {
            min.push(num);
        }

        if(max.size() > min.size() + 1)
        {
            min.push(max.top());
            max.pop();
        }

        if(min.size() > max.size() + 1)
        {
            max.push(min.top());
            min.pop();
        }
    }

    double findMedian() {

        int m1 = max.size();
        int n1 = min.size();

        if((m1 + n1) % 2 != 0)
        {
            if(max.size() > min.size())
                return max.top();
            else
                return min.top();
        }

        return (max.top() + min.top()) / 2.0;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */