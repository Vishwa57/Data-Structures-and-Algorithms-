/*
    Your Trie object will be instantiated and called as such:
    Trie* obj = new Trie();
    obj->insert(word);
    bool check2 = obj->search(word);
    bool check3 = obj->startsWith(prefix);
 */

class Node
{
public:
    Node* link[26];
    bool flag = false;
    bool containsKey(char ch)
    {
        return (link[ch-'a']!=NULL);
    }
    void putKey(char ch, Node* node)
    {
        link[ch-'a'] = node;
    }
    Node* nextPos(char ch)
    {
        return link[ch-'a'];
    }
};


class Trie {
    Node* root;
public:
    Trie() {
         root = new Node();
    }
    
    void insert(string word) {
        Node* node = root;
        for(auto i: word)
        {
            if(!node->containsKey(i))
                node->putKey(i, new Node());
            node = node->nextPos(i);
        }
        node->flag = true;
    }
    
    bool search(string word) {
        Node* node = root;
        for(auto i: word)
        {
            if(!node->containsKey(i))
                return false;
            node = node->nextPos(i);
        }
        return node->flag;
    }
    
    bool startsWith(string prefix) {
        Node* node = root;
        for(auto i: prefix)
        {
            if(!node->containsKey(i))
                return false;
            node = node->nextPos(i);
        }
        return true;
    }
};
