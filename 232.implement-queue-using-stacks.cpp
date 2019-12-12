/*
 * @lc app=leetcode id=232 lang=cpp
 *
 * [232] Implement Queue using Stacks
 *
 * https://leetcode.com/problems/implement-queue-using-stacks/description/
 *
 * algorithms
 * Easy (46.00%)
 * Likes:    746
 * Dislikes: 124
 * Total Accepted:    178K
 * Total Submissions: 386.5K
 * Testcase Example:  '["MyQueue","push","push","peek","pop","empty"]\n[[],[1],[2],[],[],[]]'
 *
 * Implement the following operations of a queue using stacks.
 *
 *
 * push(x) -- Push element x to the back of queue.
 * pop() -- Removes the element from in front of queue.
 * peek() -- Get the front element.
 * empty() -- Return whether the queue is empty.
 *
 *
 * Example:
 *
 *
 * MyQueue queue = new MyQueue();
 *
 * queue.push(1);
 * queue.push(2);
 * queue.peek();  // returns 1
 * queue.pop();   // returns 1
 * queue.empty(); // returns false
 *
 * Notes:
 *
 *
 * You must use only standard operations of a stack -- which means only push to
 * top, peek/pop from top, size, and is empty operations are valid.
 * Depending on your language, stack may not be supported natively. You may
 * simulate a stack by using a list or deque (double-ended queue), as long as
 * you use only standard operations of a stack.
 * You may assume that all operations are valid (for example, no pop or peek
 * operations will be called on an empty queue).
 *
 *
 */

// @lc code=start
class MyQueue
{
    stack<int> stk;

public:
    /** Initialize your data structure here. */
    MyQueue()
    {
    }

    /** Push element x to the back of queue. */
    void push(int x)
    {
        stk.push(x);
    }

    /** Removes the element from in front of queue and returns that element. */
    int pop()
    {
        stack<int> temp_stk;
        while (!stk.empty())
        {
            temp_stk.push(stk.top());
            stk.pop();
        }
        int v = temp_stk.top();
        temp_stk.pop();
        while (!temp_stk.empty())
        {
            stk.push(temp_stk.top());
            temp_stk.pop();
        }
        return v;
    }

    /** Get the front element. */
    int peek()
    {
        stack<int> temp_stk;
        while (!stk.empty())
        {
            temp_stk.push(stk.top());
            stk.pop();
        }
        int v = temp_stk.top();
        while (!temp_stk.empty())
        {
            stk.push(temp_stk.top());
            temp_stk.pop();
        }
        return v;
    }

    /** Returns whether the queue is empty. */
    bool empty()
    {
        return stk.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
// @lc code=end
