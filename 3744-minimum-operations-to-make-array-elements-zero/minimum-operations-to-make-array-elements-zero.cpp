class Solution {
public:

    long long fn(int num){
        if(num<=0)return 0;
        if(num<=3)return num;
        int cnt=2;
        int pre=3;
        long long ans=3;
        for(int i=4;i<=num;i*=4){
            long long up=1LL*i*4-1;
            long long range=0;
            if(up>=num){
                range=num-pre;
            }else{
                range=up-pre;
            }
            pre=up;
           
            ans+=(1LL*range*cnt);
            cnt++;
        }
        return ans;
    }

    long long minOperations(vector<vector<int>>& queries) {
        long long ans=0;

        for(auto q:queries){
            int left=q[0],right=q[1];

            long long val1=fn(right);
            long long val2=fn(left-1);
            
            long long diff=val1-val2;
            if(diff%2)diff++;
            ans+=(diff/2);
        }
        return ans;
    }
};