#include <iostream>
#include <queue>
using namespace std;

template <typename T>
class BinaryTreeNode
{
public:
    T data;
    BinaryTreeNode<T> *left;
    BinaryTreeNode<T> *right;

    BinaryTreeNode(T data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

BinaryTreeNode<int> *takeInput()
{
    int rootData;
    cin >> rootData;
    if (rootData == -1)
    {
        return NULL;
    }
    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(rootData);
    queue<BinaryTreeNode<int> *> q;
    q.push(root);
    while (!q.empty())
    {
        BinaryTreeNode<int> *currentNode = q.front();
        q.pop();
        int leftChild, rightChild;
        cin >> leftChild;
        if (leftChild != -1)
        {
            BinaryTreeNode<int> *leftNode = new BinaryTreeNode<int>(leftChild);
            currentNode->left = leftNode;
            q.push(leftNode);
        }

        cin >> rightChild;
        if (rightChild != -1)
        {
            BinaryTreeNode<int> *rightNode =
                new BinaryTreeNode<int>(rightChild);
            currentNode->right = rightNode;
            q.push(rightNode);
        }
    }
    return root;
}

void preOrder(BinaryTreeNode<int> *root)
{
    if (root == NULL)
    {
        return;
    }

    cout << root->data << " ";

    preOrder(root->left);
    preOrder(root->right);
}

BinaryTreeNode<int> *constructHelper(int *input, int start_index, int end_index)
{
    if (start_index > end_index)
    {
        return NULL;
    }
    int mid = (start_index + end_index) / 2;
    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(input[mid]);

    root->left = constructHelper(input, start_index, mid - 1);
    root->right = constructHelper(input, mid + 1, end_index);
    return root;
}

BinaryTreeNode<int> *constructTree(int *input, int n)
{
    return constructHelper(input, 0, n - 1);
}

BinaryTreeNode<int> *deleteData(int data, BinaryTreeNode<int> *node)
{
    if (node == NULL)
    {
        return NULL;
    }
    if (data > node->data)
    {
        node->right = deleteData(data, node->right);
        return node;
    }
    else if (data < node->data)
    {
        node->left = deleteData(data, node->left);
        return node;
    }
    else
    { // found the node
        if (node->left == NULL && node->right == NULL)
        { // Leaf node
            delete node;
            return NULL;
        }
        else if (node->left == NULL)
        { // node having only left child
            BinaryTreeNode<int> *temp = node->right;
            node->right = NULL;
            delete node;
            return temp;
        }
        else if (node->right == NULL)
        { // node having only right child
            BinaryTreeNode<int> *temp = node->left;
            node->left = NULL;
            delete node;
            return temp;
        }
        else
        { // node having both the childs
            BinaryTreeNode<int> *minNode = node->right;
            while (minNode->left != NULL)
            {                            // replacing node with
                minNode = minNode->left; // right subtree’s min
            }
            int rightMin = minNode->data;
            node->data = rightMin;
            // now simply deleting that replaced node using recursion
            node->right = deleteData(rightMin, node->right);
            return node;
        }
    }
}

int deleteElement(int arr[], int n, int x)
{
    int i;
    for (i = 0; i < n; i++)
        if (arr[i] == x)
            break;
    if (i < n)
    {
        // reduce size of array and move all elements on space ahead
        n = n - 1;
        for (int j = i; j < n; j++)
            arr[j] = arr[j + 1];
    }
    return n;
}

int main()
{
    int size;
    cout << "Enter size of data:- " << endl;
    cin >> size;
    cout << "Enter Array:- "<< endl;
    int *input = new int[size];

    for (int i = 0; i < size; i++)
    {
        cin >> input[i];
    }

    BinaryTreeNode<int> *root = constructTree(input, size);
    preOrder(root);
    cout << endl;
    int data;
    cout << "Enter data to be deleted:- " << endl;
    cin >> data;
    deleteData(data, root);
    cout << endl;
    preOrder(root);
    cout << endl;

    // TO DELETE ELEMENT FROM ARRAY
    int n;
    cout << "Enter size of data:- " << endl;
    cin >> n;
    int x;
    cout << "Enter Element to be deleted: - "<< endl;
    cin >> x;
    int *arr = new int[n];
    cout << "Enter Array:- "<< endl;
    for (int i = 0; i < n; i++)
    {
        cin >> input[i];
    }
    deleteElement(arr, n, x);
    
    delete[] input;
}

