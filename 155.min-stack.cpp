/*
 * @lc app=leetcode id=155 lang=cpp
 *
 * [155] Min Stack
 *
 * https://leetcode.com/problems/min-stack/description/
 *
 * algorithms
 * Easy (39.85%)
 * Likes:    2352
 * Dislikes: 249
 * Total Accepted:    379.9K
 * Total Submissions: 952.3K
 * Testcase Example:  '["MinStack","push","push","push","getMin","pop","top","getMin"]\n' +
  '[[],[-2],[0],[-3],[],[],[],[]]'
 *
 * Design a stack that supports push, pop, top, and retrieving the minimum
 * element in constant time.
 *
 *
 * push(x) -- Push element x onto stack.
 * pop() -- Removes the element on top of the stack.
 * top() -- Get the top element.
 * getMin() -- Retrieve the minimum element in the stack.
 *
 *
 *
 *
 * Example:
 *
 *
 * MinStack minStack = new MinStack();
 * minStack.push(-2);
 * minStack.push(0);
 * minStack.push(-3);
 * minStack.getMin();   --> Returns -3.
 * minStack.pop();
 * minStack.top();      --> Returns 0.
 * minStack.getMin();   --> Returns -2.
 *
 *
 *
 *
 */

// @lc code=start
class MinStack
{
    stack<int> s, min_s;

public:
    /** initialize your data structure here. */
    MinStack()
    {
        min_s.push(INT_MAX);
    }

    void push(int x)
    {
        s.push(x);
        min_s.push(min(x, min_s.top()));
    }

    void pop()
    {
        s.pop();
        min_s.pop();
    }

    int top()
    {
        return s.top();
    }

    int getMin()
    {
        return min_s.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
// @lc code=end
