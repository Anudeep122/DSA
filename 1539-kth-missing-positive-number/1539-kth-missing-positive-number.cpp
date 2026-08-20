class Solution {
public:
    // bool checker(vector<int>& arr,int k,int mid){
    //     int n=arr.size();
    //     auto it=lower_bound(arr.begin(),arr.end(),mid);
    //     int index=it-arr.begin();int val=*it;
    //     if(val-index<k) return true;
    //     else return false;
    // }
    bool find(vector<int>& arr,int el){
        int low=0,high=arr.size()-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(arr[mid]==el) return true;
            else if(arr[mid]<el) low=mid+1;
            else high=mid-1;
        }
        return false;
    }

    int findKthPositive(vector<int>& arr, int k) {
        int n=arr.size();
        int low=1,high=*max_element(arr.begin(),arr.end())+k;
        // int ans=0;
        // while(low<=high){
        //     int mid=low+(high-low)/2;
        //     if(checker(arr,k,mid)){
        //         ans=mid;
        //         low=mid+1;
        //     }
        //     else high=mid-1;
        // }
        // return ans;
        vector<int> miss;
        for(int i=1;i<=high;i++){
            if(find(arr,i)) continue;
            else{
                miss.push_back(i);
            }
        }
        return miss[k-1];
    }
};