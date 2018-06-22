#include <queue>
#include <stack>
using namespace std;

struct node
{
    int key;
    struct node *left,*right;
};

// create new node
struct node *newNode(int data)
{
    struct node *temp = new node;
    temp->key = data;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

struct node *insert(struct node *node, int data)
{
    if (NULL == node)
       return newNode(data);
    if (node->key < data)
    {
        node->right = insert(node->right, data);
    }
    else if (node->key > data)
    {
        node->left = insert(node->left, data);
    }
    return node;
}

void postorder(struct node *node)
{
    if (NULL == node)
        return;
    postorder(node->left);
    postorder(node->right);
    cout << node->key << " " << endl;
}

void postorder_2(struct node *node)
{
    if (NULL == node)
        return;
    stack <struct node *> s1;
    stack <struct node *> s2;
    s1.push(node);
    struct node *p = NULL;
    while (!s1.empty())
    {
        p = s1.top();
        s2.push(p);
        s1.pop();
        if(p->left)
            s1.push(p->left);
        if(p->right)
            s1.push(p->right);
    }
    while (!s2.empty())
    {
        p = s2.top();
        s2.pop();
        cout<<p->key << " " << endl;
    }
}


void inorder(struct node *node)
{
    if (NULL == node)
        return;
    inorder(node->left);
    cout << node->key << " " << endl;
    inorder(node->right);
}

void inorder_2(struct node *node)
{
    stack <struct node *> s;
    struct node *p = node;
    while (p!=NULL || !s.empty())
    {
        while(p != NULL)
        {
            s.push(p);
            p = p->left;
        }
        if (!s.empty())
        {
            p = s.top();
            s.pop();
            cout<<p->key<<" " << endl;
            p = p->right;
        }

    }
}

void preorder(struct node *node)
{
    if (NULL != node)
    {
        cout << node->key << " " << endl;
        preorder(node->left);
        preorder(node->right);
    }
}


void preorder_2(struct node *node)
{
    stack <struct node *> s;
    struct node *p = node;
    while (p != NULL || !s.empty())
    {
        while(p != NULL)
        {
            cout << p->key << " " << endl;
            s.push(p);
            p = p->left;
        }
        if (!s.empty())
        {
            p = s.top();
            s.pop();
            p = p->right;
        }
    }
}

void levelorder(struct node *node)
{
    if (NULL == node)
    {
        return;
    }
    queue<struct node *> q;
    stack<struct node *> s;
    struct node * p;
    q.push(node);
    s.push(node);
    while(!q.empty())
    {
        p = q.front();
        q.pop();
        cout << p->key <<" " << endl;
        if (p->left != NULL)
        {
            q.push(p->left);
            s.push(p->left);
        }
        if (p->right != NULL)
        {
            q.push(p->right);
            s.push(p->right);
        }
    }
    struct node * p2;
    cout << "----------------stack" << endl;
    while(!s.empty())
    {
        p2 = s.top();
        cout << p2->key <<" " << endl;
        s.pop();
    }
}

int height(struct node *node)
{
    if (NULL == node)
    {
        return 0;
    }
    else
    {
        int left_height = height(node->left);
        int right_height = height(node->right);
        if (left_height > right_height)
            return left_height + 1;
        else
            return right_height + 1;
    }
}

int search(struct node *node, int data)
{
    if (NULL == node)
    {
        cout << " no found! " << endl;
        return 0;
    }
    if (data == node->key)
    {
        cout << "yes, found!" << endl;
        return 1;
    }
    else if (data < node->key)
        search(node->left, data);
    else
        search(node->right, data);
}



int main()
{
    struct node *node = NULL;
    node = insert(node, 66);
    insert(node, 44);
    insert(node, 33);
    insert(node, 22);
    insert(node, 99);
    insert(node, 77);
    insert(node, 111);
    insert(node, 45);
    cout << "----postorder----" <<endl;
    postorder(node);
    cout << "----postorder-2----" <<endl;
    postorder_2(node);

    cout <<"----inorder----" <<endl;
    inorder(node);
    cout <<"----inorder-2----" <<endl;
    inorder_2(node);

    cout << "----preorder----"<<endl;
    preorder(node);
    cout << "----preorder-2----"<<endl;
    preorder_2(node);

    cout << "----levelorder---"<<endl;
    levelorder(node);
    cout << "max_height = " << height(node) << endl;
    search(node, 222);
}










