class Solution {
public:
    int trap(vector<int>& nums) {
        int n=nums.size();
        vector<int> prevM(n,0);prevM[0]=nums[0];
        vector<int> nexM(n,0);nexM[n-1]=nums[n-1];
        for(int i=1;i<n;i++){
            prevM[i]=max(prevM[i-1],nums[i]);
        }
        for(int i=n-2;i>=0;i--){
            nexM[i]=max(nexM[i+1],nums[i]);
        }
        int sum=0;
        for(int i=0;i<n;i++){
            sum=sum+min(prevM[i],nexM[i])-nums[i];
        }
        return sum;
        
    }
};