import java.util.ArrayList;
import java.util.LinkedList;
import java.util.Queue;

class Solution {
    public static void main(String[] args){
        Tree t= new Tree<>(-1);
        t.left = new Tree<>(5);
        t.right = new Tree<>(7);
        t.right.right = new Tree<>(1);
        ArrayList<Integer> res= largestValues(t);
        for(Integer x:res){
            System.out.println(x);
        }
    }
    // in linkedlist peek gets the first element
    // poll deletes it
    private static ArrayList<Integer> largestValues(Tree<Integer> t){
        Queue<Tree<Integer>> queue=new LinkedList<>();
        queue.add(t);
        ArrayList<Integer> res=new ArrayList<>();
        // bfs
        while(!queue.isEmpty()){
            int sz=queue.size();
            // adding a new level and
            // getting the maximum of the current level
            int mx=queue.peek().value;
            for(int i=0 ; i<sz ; i++){
                Tree cur=queue.peek();
                if(cur.left!=null)queue.add(cur.left);
                if(cur.right!=null)queue.add(cur.right);
                mx=Math.max(queue.poll().value,mx);

            }
            res.add(mx);
        }
        return res;
    }
}
class Tree<T> {
    Tree(T x) {
        value = x;
    }
    T value;
    Tree<T> left=null;
    Tree<T> right=null;
}
