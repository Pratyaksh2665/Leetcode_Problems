class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();
        int total = n1 + n2;

        int i = 0, j = 0;
        int count = 0;

        int ele1 = 0, ele2 = 0;

        int idx1 = (total - 1) / 2;
        int idx2 = total / 2;

        while(i < n1 && j < n2)
        {
            int val;
            if(nums1[i] < nums2[j]) {
                val = nums1[i++];
            } else {
                val = nums2[j++];
            }

            if(count == idx1) ele1 = val;
            if(count == idx2) ele2 = val;

            count++;
        }
        while(i < n1)
        {
            int val = nums1[i++];
            if(count == idx1) ele1 = val;
            if(count == idx2) ele2 = val;
            count++;
        }

        while(j < n2)
        {
            int val = nums2[j++];
            if(count == idx1) ele1 = val;
            if(count == idx2) ele2 = val;
            count++;
        }
        if(total % 2 == 0)
            return (ele1 + ele2) / 2.0;
        return ele2;
    }
};