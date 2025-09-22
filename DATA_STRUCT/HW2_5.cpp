struct binarytree {
    int key;
    binarytree *left, *right;
    binarytree(int x): key(x), left(NULL), right(NULL){}
    int range_count(int a, int b, binarytree *root){
        if(!root || root->key<a || root->key>b) return 0;
        return 1 + range_count(a, b, root->left) + range_count (a, b, root->right)
    }
};