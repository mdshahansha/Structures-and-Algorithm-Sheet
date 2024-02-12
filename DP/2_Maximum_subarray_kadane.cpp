#include <iostream>
#include <vector>

using namespace std;

pair<int, pair<int, int>> maxSubArray(vector<int> &nums)
{
    int n = nums.size();

    if (n == 1)
        return {nums[0], {0, 0}};

    int curr = nums[0];
    int maxTill = nums[0];
    int start = 0;
    int s = 0;
    int end = 0;

    for (int i = 1; i < n; i++)
    {
        if (nums[i] > curr + nums[i])
        {
            curr = nums[i];
            s = i; // subarray ka naya shuruaat
        }
        else
        {
            curr = curr + nums[i];
        }

        if (curr > maxTill)
        {
            maxTill = curr;
            start = s; // subarray ka naya shuruaat
            end = i;   // subarray ka ant
        }
    }

    return {maxTill, {start, end}};
}

int main()
{
    vector<int> nums = {1, 2, 3, -2, 5};

    pair<int, pair<int, int>> result = maxSubArray(nums);

    cout << "Maximum Subarray Sum: " << result.first << endl;
    cout << "Subarray Range: [" << result.second.first << ", " << result.second.second << "]" << endl;

    return 0;
}


// O R
 
vector<int> findMaxSubarray(vector<int>& nums) {
    int maxSum = nums[0];
    int currentSum = nums[0];
    int start = 0, end = 0;
    int currentStart = 0;

    for (int i = 1; i < nums.size(); ++i) {
        if (currentSum < 0) {
            currentSum = nums[i];
            currentStart = i;
        } else {
            currentSum += nums[i];
        }

        if (currentSum > maxSum) {
            maxSum = currentSum;
            start = currentStart;
            end = i;
        }
    }

    vector<int> result(nums.begin() + start, nums.begin() + end + 1);
    return result;
}

// Bilkul, shuru karte hain !Input string 'aabcc' hai.1. `removeDuplicateLetters('aabcc')` call kiya.2. 'a' uthaya aur 'chq' mein store kiya .3. Fir `removeDuplicateLetters('abcc')` call kiya .4. 'a' phir se uthaya aur 'chq' mein store kiya .5. Fir `removeDuplicateLetters('bcc')` call kiya .6. 'b' uthaya aur 'chq' mein store kiya .7. Fir `removeDuplicateLetters('cc')` call kiya .8. 'c' uthaya aur 'chq' mein store kiya .9. Fir `removeDuplicateLetters('c')` call kiya .10. String ki length 0 hai, toh empty string return kiya .11. 'c' ko empty string ke saath joda, output 'c' hua .12. 'b' ko 'c' ke saath joda, output 'bc' hua .13. 'a' ko 'bc' ke saath joda, output 'abc' hua.Is process mein, har recursion step mei pehla character uthaya gaya, phir baaki string ke saath function phir se call kiya gaya.Duplicate characters ko eliminate kiya gaya aur 'abc' ko generate kiya gaya.
