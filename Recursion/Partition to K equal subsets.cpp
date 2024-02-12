#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    bool help(int i, int bucketNum, int bucketSum, int reqSum, int k, vector<int>& nums, vector<int>& alreadyPicked) {
        if (bucketNum == k + 1)
            return true;

        if (bucketSum == reqSum)
            return help(0, bucketNum + 1, 0, reqSum, k, nums, alreadyPicked);// from here we again start from beigning from the zero , BCZ   the value with zero ,bucketNum and bucketSum is zero ,we are starting from FRESH

        if (bucketSum > reqSum) {
            return false;
        }
        if (i >= nums.size())
            return false;

        if (alreadyPicked[i] == 1) {
            return help(i + 1, bucketNum, bucketSum, reqSum, k, nums, alreadyPicked);
        } else {
            // pick
            if (bucketSum + nums[i] <= reqSum) {
                bucketSum += nums[i];
                alreadyPicked[i] = 1;

                if (help(i + 1, bucketNum, bucketSum, reqSum, k, nums, alreadyPicked))
                    return true;
                    
                bucketSum -= nums[i];
                alreadyPicked[i] = 0;
            }

            // skip
            if (help(i + 1, bucketNum, bucketSum, reqSum, k, nums, alreadyPicked))
                return true;

            return false;
        }
    }

    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> alreadyPicked(n, 0);
        int reqSum = accumulate(nums.begin(), nums.end(), 0);

        if (reqSum % k != 0) {
            return false;
        }
        reqSum /= k;

        return help(0, 1, 0, reqSum, k, nums, alreadyPicked);
    }
};
