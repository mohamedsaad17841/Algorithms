import java.util.ArrayList;
import java.util.LinkedList;
import java.util.Queue;

public class Main {
    public static void main(String[] args){
        Tree<Integer> t= new Tree<>(1);
        t.left = new Tree<>(5);
        t.left.left = new Tree<>(3);
        t.left.right = new Tree<>(4);
        t.right = new Tree<>(7);
        t.right.right = new Tree<>(1);
        t.right.left = new Tree<>(3);

        System.out.println(digitSum(t));
    }
    static long sum=0;
    private static Long digitSum(Tree<Integer> t){
        dfs(t,t.value);
        return sum;
    }
    private static void dfs(Tree<Integer> node,long curSum){
        if(node.left!=null){
            dfs(node.left , curSum*10 + node.left.value);
        }
        if(node.right!=null){
            dfs(node.right , curSum*10 + node.right.value);
        }
        if(node.left == null && node.right == null){
            sum += curSum;
        }
    }
    static class Tree<T> {
        Tree(T x) {
            value = x;
        }
        T value;
        Tree<T> left=null;
        Tree<T> right=null;
    }
}

