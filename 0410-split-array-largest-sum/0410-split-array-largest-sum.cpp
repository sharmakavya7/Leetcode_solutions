class Solution {
public:
    //"isvalid()" is to check if this value , "mid" can be a valid answer for m partitions.
    bool isValid(vector<int> nums,int n, int m, int mid){
        //assignments=1 initially , means can we allocate the values to 1 partition only without violating the condition of having sum <=mid;
        int assn=1; 
        int sum=0;
        for(int i : nums){
            sum+=i;
            if (sum>mid){
                assn++;
                sum=i;
                //if at any instance value is greater than current max sum 
                if (sum>mid) 
                    return false;
            }
            //if we need more than required partitions for the current max ("mid") value we are checking for we return false;
            if (assn>m) 
                return false;
        }
        return true; 
    }
    int splitArray(vector<int>& nums, int m) {
        int n=nums.size(); 
        long long sum=0;
        for(long long  i : nums){
            //Even if you do n partitions you won't be able to reduce this, so simply this will be the max sum.
            if (i==INT_MAX)
                return INT_MAX; 
            sum+=i;
        }
        //if you can't partition it then the max value in the whole array will be the max sum.
        if (m==1) 
            return sum;
        long long low=0;
        
        long high=sum; 
        long long  mid;
        long long  res=INT_MAX;
        while (low<=high){
            mid=low+(high-low)/2;
            if (isValid(nums,n,m,mid)) 
            {
                res=min(res,mid);
                high=mid-1; //even when we find an answer we check for a lesser value;
            }
            else 
                low=mid+1;
            
        }
        return res;
    }
    
};