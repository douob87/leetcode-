struct Node{
    Node* child[2]{};
    int leaf = 0;
};
class Trie{
    Node* root = new Node();
    const int WIDTH = 15;
public:
    void put(int x){
        Node* curr = root;
        for(int b=WIDTH-1;b>=0;b--){
            int bit = x>>b & 1;//x 's 第 b 個 bit (0 or 1)
            if(!curr->child[bit]){
                curr->child[bit] = new Node();
            }
            curr = curr->child[bit];
            curr->leaf ++;
        }
    }
    void del(int x){
        Node* curr = root;
        for(int b=WIDTH-1;b>=0;b--){
            int bit = x>>b & 1;
            curr = curr->child[bit];
            curr->leaf --;
        }
    }
    int max_xor(int x){
        int ans = 0;
        Node* curr = root;
        for(int b=WIDTH-1;b>=0;b--){
            int bit = x>>b & 1;
            //先往反向找，0^1 = 1^0 = 1
            if(curr->child[!bit] && curr->child[!bit]->leaf){
                ans |= (1<<b);
                bit = !bit;
            }
            curr = curr->child[bit];
        }
        return ans;
    }
};