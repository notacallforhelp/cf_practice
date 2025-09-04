class Solution {
public:
    int sortPermutation(vector<int>& nums) {
        if(is_sorted(nums.begin(),nums.end()))
        {
            return 0;
        }
        int mx = *max_element(nums.begin(),nums.end());
        vector<int> check;
        for(int i=0;i<nums.size();i++)
            {
                if(nums[i]!=i)
                {
                    check.push_back(i);
                }
            }

        int curr = 1;
        int output = 0;

        while(curr<=mx)
            {
                set<int> k;
                for(auto &ele:check)
                    {
                        k.insert(ele&curr);
                    }
                if(k.size()==1)
                {
                    output=max(output,*k.begin());
                }
                curr <<= 1;
            }
        return output;
    }
};©leetcode