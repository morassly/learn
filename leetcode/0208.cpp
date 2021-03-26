class Trie
{
    struct node
    {
        node *child[26];
        bool isword;
        node(bool _isword) : isword(_isword)
        {
            for (int i = 0; i < 26; i++)
                child[i] = nullptr;
        }
    };
    node *root;

public:
    /** Initialize your data structure here. */
    Trie()
    {
        root = new node(false);
    }

    /** Inserts a word into the trie. */
    void insert(string word)
    {
        auto cur = root;
        for (auto i : word)
        {
            int idx = i - 'a';
            if (cur->child[idx] == nullptr)
            {
                cur->child[idx] = new node(false);
            }
            cur = cur->child[idx];
        }
        cur->isword = true;
    }

    /** Returns if the word is in the trie. */
    bool search(string word)
    {
        auto cur = root;
        for (auto i : word)
        {
            int idx = i - 'a';
            if (cur->child[idx] == nullptr)
            {
                return false;
            }
            cur = cur->child[idx];
        }
        return cur->isword;
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix)
    {
        auto cur = root;
        for (auto i : prefix)
        {
            int idx = i - 'a';
            if (cur->child[idx] == nullptr)
            {
                return false;
            }
            cur = cur->child[idx];
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