class segmentTree{
	struct Node{
		int mx = 0;
		Node* left = NULL;
		Node* right = NULL;
	};
	void maintain(Node* o){
		int lmx = o->left ? o->left->mx : 0;
        int rmx = o->right ? o->right->mx : 0;
        o->mx = max(lmx, rmx);
	}
	void update(Node* o, int l, int r, int x){
		if(l == r){
			o->mx = x;
			return ;
		}
		int m = l + (r - l) / 2;
		if(m >= x){
			if(!o->left)o->left = new Node();
			update(o->left, l, m, x);
		}
		if(m < x){
			if(!o->right)o->right = new Node();
			update(o->right, m+1, r, x);
		}
		maintain(o);
	}
	int query(Node* o, int l, int r, int ql, int qr){
		if(o==NULL || r<ql || l>qr)return 0;
		if(ql<=l && r<=qr)return o->mx;
		int m = l + (r - l) / 2;
		return max(
			query(o->left, l, m, ql, qr),
			query(o->right, m+1, r, ql, qr)
		);
	}
public:
	int MN,MX;//上下界
	segmentTree(int min, int max):MN(min),MX(max){}
	Node* root = new Node();
	
	void update(int x){
		update(root, MN, MX, x);
	}
	int query(int ql, int qr){
		return query(root, MN, MX, ql, qr);
	}
};