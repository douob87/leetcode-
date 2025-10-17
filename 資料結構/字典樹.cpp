struct Node{
    bool isWord = false;
    Node* child[26];
};
class Trie {
public:
    Node* root;
    Trie() {
        root = new Node();
    }
    
    void insert(string word) {
        Node* ptr = root;
        for(const char& c : word){
            if(!ptr->child[c-'a'])ptr->child[c-'a'] = new Node();
            ptr = ptr->child[c-'a'];
        }
        ptr->isWord = true;
    }
    
    bool search(string word) {
        Node* ptr = root;
        for(const char& c : word){
            if(!ptr->child[c-'a'])return false;
            ptr = ptr->child[c-'a'];
        }
        return ptr->isWord;
    }
    
    bool startsWith(string prefix) {
        Node* ptr = root;
        for(const char& c : prefix){
            if(!ptr->child[c-'a'])return false;
            ptr = ptr->child[c-'a'];
        }
        return true;
    }
};