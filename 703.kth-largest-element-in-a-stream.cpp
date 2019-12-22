/*
 * @lc app=leetcode id=703 lang=cpp
 *
 * [703] Kth Largest Element in a Stream
 *
 * https://leetcode.com/problems/kth-largest-element-in-a-stream/description/
 *
 * algorithms
 * Easy (47.59%)
 * Likes:    466
 * Dislikes: 228
 * Total Accepted:    52.8K
 * Total Submissions: 110.7K
 * Testcase Example:  '["KthLargest","add","add","add","add","add"]\n' +
  '[[3,[4,5,8,2]],[3],[5],[10],[9],[4]]'
 *
 * Design a class to find the kth largest element in a stream. Note that it is
 * the kth largest element in the sorted order, not the kth distinct element.
 *
 * Your KthLargest class will have a constructor which accepts an integer k and
 * an integer array nums, which contains initial elements from the stream. For
 * each call to the method KthLargest.add, return the element representing the
 * kth largest element in the stream.
 *
 * Example:
 *
 *
 * int k = 3;
 * int[] arr = [4,5,8,2];
 * KthLargest kthLargest = new KthLargest(3, arr);
 * kthLargest.add(3);   // returns 4
 * kthLargest.add(5);   // returns 5
 * kthLargest.add(10);  // returns 5
 * kthLargest.add(9);   // returns 8
 * kthLargest.add(4);   // returns 8
 *
 *
 * Note:
 * You may assume that nums' length ≥ k-1 and k ≥ 1.
 *
 */

// @lc code=start
class KthLargest
{
    map<int, int> num_map;
    int kth;

public:
    KthLargest(int k, vector<int> &nums)
    {
        kth = k;
        for (auto n : nums)
            add_helper(n);
    }

    int add(int val)
    {
        add_helper(val);
        return search_helper();
    }

    void add_helper(int val)
    {
        if (num_map.find(val) == num_map.end())
            num_map[val] = 0;
        num_map[val] += 1;
    };
    int search_helper()
    {
        int temp = kth;
        auto it = num_map.end();
        while (temp > 0)
        {
            it--;
            temp -= it->second;
        }
        return it->first;
    };
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */
// @lc code=end
