struct segmentTree{
    int start, end, sum;
    segmentTree* left, *right;
    segmentTree(int s, int e):start(s), end(e), sum(0), left(nullptr), right(nullptr){}
};

class NumArray {
    segmentTree*root;
public:
    NumArray(vector<int> nums) {
        int n = nums.size();
        root = build(nums, 0, n-1);
    }
    
    void update(int i, int val) {
        modify(i, val, root);
    }
    
    int sumRange(int i, int j) {
        return query(i, j, root);
    }
    
    //nums不用引用会超时
    segmentTree* build(vector<int>& nums, int start, int end) {
        if(start > end) return nullptr;
        segmentTree* root = new segmentTree(start,end);
        if(start == end) {
            root->sum = nums[start];
            return root;
        }
        int mid = start + (end - start) / 2;
        root->left = build(nums,start,mid);
        root->right = build(nums,mid+1,end);
        root->sum = root->left->sum + root->right->sum;
        return root;
    }
    
    void modify(int i, int val, segmentTree* root) {
        if(root == nullptr) return;
        if(root->start == i && root->end == i) {
            root->sum = val;
            return;
        }
        int mid = (root->start + root->end) / 2;
        if(i > mid) {
            modify(i,val,root->right);
        } 
        else {
            modify(i,val,root->left);
        }
        root->sum = root->left->sum + root->right->sum;
    }
    
    int query(int i, int j, segmentTree* root) {
        if(root == nullptr) return 0;
        if(root->start == i && root->end == j) return root->sum;
        int mid = (root->start + root->end) / 2;
        if(i > mid) return query(i,j,root->right);
        if(j <= mid) return query(i,j,root->left);
        return query(i,mid,root->left) + query(mid+1,j,root->right);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray obj = new NumArray(nums);
 * obj.update(i,val);
 * int param_2 = obj.sumRange(i,j);
 */
