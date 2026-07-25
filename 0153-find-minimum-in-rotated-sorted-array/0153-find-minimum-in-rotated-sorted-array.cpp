class Solution {
public:
    int findMin(vector<int>& arr) {
        int n=arr.size();
        if(n==1) return arr[0];
        int low=0;
        int high=n-1;
        int minm=INT_MAX;
        while(low<=high)
        {
            int mid=(low+high)/2;
            if(arr[mid]>arr[high])// mtlb right side unsorted h 
            {
                minm=min(minm,arr[low]);
                low=mid+1;
              
            }
            else
            {
                minm=min(minm,arr[mid]);
                high=mid-1;   
            }
        }
        return minm;
    }
};