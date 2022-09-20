/*
 * @lc app=leetcode.cn id=232 lang=cpp
 *
 * [232] 用栈实现队列
 */

// @lc code=start
#include <stack>
#include <iostream>
using namespace std;
class MyQueue {
private:
    stack<int> s1;
    stack<int> s2;
    int front;
public:
    MyQueue()
    {
    
    }
    
    void push(int x)
    {
        if (s1.empty())
        {
            front = x;
        }
        s1.push(x);
        // s1.push(x);
    }
    
    int pop()
    {
        int t;
        if (s2.empty())
        {
            while (!s1.empty())
            {
                t = s1.top();
                s1.pop();
                s2.push(t);
            }
        }
        t = s2.top();
        s2.pop();
        return t;
        // int t;
        // int ans;
        // while (!s1.empty())
        // {
        //     t = s1.top();
        //     s1.pop();
        //     s2.push(t);
        // }
        // if (!s2.empty())
        // {
        //     ans = s2.top();
        //     s2.pop();
        // }
        // while (!s2.empty())
        // {
        //     t = s2.top();
        //     s2.pop();
        //     s1.push(t);
        // }
        // return ans;
    }
    
    int peek()
    {
        if (!s2.empty())
        {
            return s2.top();
        }
        return front;
        // int t;
        // int ans;
        // while (!s1.empty())
        // {
        //     t = s1.top();
        //     s1.pop();
        //     s2.push(t);
        // }
        // if (!s2.empty())
        // {
        //     ans = s2.top();
        // }
        // while (!s2.empty())
        // {
        //     t = s2.top();
        //     s2.pop();
        //     s1.push(t);
        // }
        // return ans;
    }
    
    bool empty()
    {
        return (s1.empty() && s2.empty());
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

