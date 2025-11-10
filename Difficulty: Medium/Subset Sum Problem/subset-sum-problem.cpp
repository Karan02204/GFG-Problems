class Solution {
public:
    bool func(vector<int>& nums, int index, int currentSum, int target) {
        // Base case 1: subset found
        if (currentSum == target)
            return true;

        // Base case 2: reached end or exceeded target (for positive nums)
        if (index >= nums.size() || currentSum > target)
            return false;

        // Include current element
        if (func(nums, index + 1, currentSum + nums[index], target))
            return true;

        // Exclude current element
        if (func(nums, index + 1, currentSum, target))
            return true;

        // No valid subset found
        return false;
    }

    bool isSubsetSum(vector<int>& arr, int sum) {
        return func(arr, 0, 0, sum);
    }
};
