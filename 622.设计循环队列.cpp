/*
 * @lc app=leetcode.cn id=622 lang=cpp
 *
 * [622] 设计循环队列
 */

// @lc code=start
// #include <iostream>
// #include <vector>
// #include <algorithm>
// #include <string>
// #include<cstring>
// using namespace std;
class MyCircularQueue {
public:
    struct node
    {
        int value;
        node * pNext;
    };
    MyCircularQueue(int k) {
        front = nullptr;
        end = nullptr;
        len = 0;
        maxLen = k;
    }
    
    bool enQueue(int value) {
        if (len == maxLen)
        {
            return false;
        }
        else if (len == 0)
        {
            front = end = new node();
            front->value = end->value = value;
            front->pNext = end->pNext = front;
        }
        else
        {
            node * t = new node();
            t->value = value;
            end->pNext = t;
            t->pNext = front;
            end = t;
        }
        len++;
        return true;
    }
    
    bool deQueue() {
        if (len == 0)
        {
            return false;
        }
        else if (len == 1)
        {
            delete front;
            front = end = nullptr;
        }
        else
        {
            end->pNext = front->pNext;
            node * t = front;
            front = front->pNext;
            delete t;
        }
        len--;
        return true;
    }
    
    int Front() {
        if (len == 0)
        {
            return -1;
        }
        else
        {
            return front->value;
        }
    }
    
    int Rear() {
        if (len == 0)
        {
            return -1;
        }
        else
        {
            return end->value;
        }

    }
    
    bool isEmpty() {
        if (len == 0)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    
    bool isFull() {
        if (len == maxLen)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
private:
    node * front;
    node * end;
    int len;
    int maxLen;
    
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */
// @lc code=end

