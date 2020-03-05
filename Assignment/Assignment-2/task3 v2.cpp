#include <iostream>
using namespace std;

template <class T>
class Tree
{
public:
    Tree() {value = 0; left = right = NULL;};
    Tree(T x) {
        value = x;
        left = right = NULL;
    }
    T value;
    Tree<T> *left;
    Tree<T> *right;
};

string num;
template <class T>
void traverse(Tree<T> *node, long& sum)
{
    num += to_string(node->value);
    if(node->left == NULL && node->right == NULL)
    {
        cout << "num = " << num << endl;
        sum += stoi(num);
        return;
    }
    if(node->left != NULL) traverse(node->left, sum);
    num.pop_back();
    if(node->right != NULL) traverse(node->right, sum);
    num.pop_back();
}

long digitSum(Tree<int> * node)
{
    long sum = 0;
    traverse(node, sum);
    return sum;
}
int main() {
    Tree<int> *node = new Tree<int>(1);
    node->left = new Tree<int> (0);
    node->left->left = new Tree<int>(3);
    node->left->right = new Tree<int>(1);
    node->right = new Tree<int>(4);

    long res = digitSum(node);
    cout << "res = " << res << endl;
    return 0;
}
