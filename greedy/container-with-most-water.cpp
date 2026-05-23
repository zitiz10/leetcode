class Solution {
public:
    int maxArea(vector<int>& height) {
        int n=height.size();
        int i=0;
        int j=n-1;
        int maxsum=0;
        while(i<j){
            int sum = (j-i) * min(height[i],height[j]) ;
            if(sum>maxsum) maxsum=sum;
            if(height[i]<height[j]) i++;
            else j--;
        }
        return maxsum;
    }
};