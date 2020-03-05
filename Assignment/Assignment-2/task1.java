
// got AC on leetcode
class Solution {
    public boolean isSymmetric(Tree root) {
        return isSym(root,root);
    }
    public boolean isSym(Tree node1,Tree node2){
        if(node1==null && node2==null)return true;
        if(node1==null || node2==null)return false;

        if(node1.value!=node2.value)return false;

        return isSym(node1.left,node2.right) &&
                isSym(node1.right,node2.left);
    }
}
class Tree<T> {
    Tree(T x) {
        value = x;
    }
    T value;
    Tree<T> left;
    Tree<T> right;
}
