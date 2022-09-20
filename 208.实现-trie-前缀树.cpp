/*
 * @lc app=leetcode.cn id=208 lang=cpp
 *
 * [208] 实现 Trie (前缀树)
 */

// @lc code=start
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

class TrieNode
{
public:
    int prefix;
    int count;
    TrieNode * nextTrieNode[26] = {};

    TrieNode()
    {
        prefix = 0;
        count = 0;
    }
};

class Trie {
public:
    TrieNode * root;
    Trie()
    {
        root = new TrieNode();
    }
    
    void insert(string word)
    {
        TrieNode * tRoot = root;
        if (tRoot == nullptr || word.length() == 0)
        {
            return;
        }
        int n = word.length();
        for (int i = 0; i < n; i++)
        {
            if (tRoot->nextTrieNode[word[i] - 'a'] == nullptr)
            {
                tRoot->nextTrieNode[word[i] - 'a'] = new TrieNode();
            }
            tRoot = tRoot->nextTrieNode[word[i] - 'a'];
            tRoot->prefix++;
        }
        tRoot->count++;
    }
    
    bool search(string word)
    {
        TrieNode * tRoot = root;
        if (tRoot == nullptr || word.length() == 0)
        {
            return false;
        }
        int n = word.length();
        for (int i = 0; i < n; i++)
        {
            if (tRoot->nextTrieNode[word[i] - 'a'] == nullptr)
            {
                return false;
            }
            tRoot = tRoot->nextTrieNode[word[i] - 'a'];
        }
        if (tRoot->count == 0)
        {
            return false;
        }
        return true;
    }
    
    bool startsWith(string prefix)
    {
        TrieNode * tRoot = root;
        if (tRoot == nullptr || prefix.length() == 0)
        {
            return false;
        }
        int n = prefix.length();
        for (int i = 0; i < n; i++)
        {
            if (tRoot->nextTrieNode[prefix[i] - 'a'] == nullptr)
            {
                return false;
            }
            tRoot = tRoot->nextTrieNode[prefix[i] - 'a'];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
// @lc code=end

