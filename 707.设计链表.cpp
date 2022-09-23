/*
 * @lc app=leetcode.cn id=707 lang=cpp
 *
 * [707] 设计链表
 */

// @lc code=start
class MyLinkedList {
public:
    struct ListNode
    {
        int val;
        ListNode * next;
        ListNode(int val):val(val), next(nullptr){}
    };
    MyLinkedList() {
        pHead = new ListNode(-1);
        pHead->next = nullptr;
    }
    
    int get(int index) {
        if (index < 0) return -1;
        ListNode * p;
        int i;
        for (p = pHead, i = 0; p->next != nullptr && i < index; p = p->next, i++);
        if (p->next == nullptr) return -1;
        else return p->next->val;
    }
    
    void addAtHead(int val) {
        ListNode * pVal = new ListNode(val);
        pVal->next = pHead->next;
        pHead->next = pVal;
    }
    
    void addAtTail(int val) {
        ListNode * p;
        for (p = pHead; p->next != nullptr; p = p->next);
        ListNode * pVal = new ListNode(val);
        p->next = pVal;
    }
    
    void addAtIndex(int index, int val) {
        if (index < 0) addAtHead(val);
        ListNode * p;
        int i;
        for (p = pHead, i = 0; p->next != nullptr && i < index; p = p->next, i++);
        if (i == index) 
        {
            ListNode * pVal = new ListNode(val);
            pVal->next = p->next;
            p->next = pVal;
        }
    }
    
    void deleteAtIndex(int index) {
        if (index < 0) return;
        ListNode * p;
        int i;
        for (p = pHead, i = 0; p->next != nullptr && i < index; p = p->next, i++);
        if (p->next != nullptr) 
        {
            ListNode * t = p->next;
            p->next = p->next->next;
            delete t;
        }
    }
private:
    ListNode * pHead;
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */
// @lc code=end

