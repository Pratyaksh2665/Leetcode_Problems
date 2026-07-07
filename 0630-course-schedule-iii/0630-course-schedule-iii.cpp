class Solution {
public:
    int scheduleCourse(vector<vector<int>>& courses) {

        sort(courses.begin(), courses.end(),
             [](auto &a, auto &b){
                 return a[1] < b[1];
             });

        priority_queue<int> pq;
        int total = 0;

        for(auto &c : courses)
        {
            int duration = c[0];
            int deadline = c[1];

            total += duration;
            pq.push(duration);

            if(total > deadline)
            {
                total -= pq.top();
                pq.pop();
            }
        }

        return pq.size();
    }
};