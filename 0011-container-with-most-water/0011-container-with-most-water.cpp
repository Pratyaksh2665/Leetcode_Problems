class Solution {
public:
    int maxArea(vector<int>& arr) {
        int n=arr.size();

        int i=0;
        int j=n-1;
        int maxm=INT_MIN;

        while(i<=j)
        {
            if(arr[i] <= arr[j])
            {
                int area=((j-i)*arr[i]) ;
                i++;

                maxm=max(maxm , area);
            }
            else
            {
                int area=((j-i)*arr[j]) ;
                j--;

                maxm=max(maxm , area);
            }
        }

        return maxm;

    }
};