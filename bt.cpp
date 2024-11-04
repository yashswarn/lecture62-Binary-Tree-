#include<iostream>
#include<queue>

using namespace std;

class Node{
    public:
    
    int data;
    Node* left;
    Node* right;

            Node(int d){
                this->data=d;
                this->left=NULL;
                this->right=NULL;
            }
};

    Node* binaryTree(Node *root){

        int data;
        cout<<"enter the data:"<<endl;
        cin>>data;

        root=new Node(data);

        if (data==-1)
        {
            return NULL;
        }

        cout<<"enter the data to the left of:"<<data<<endl;
        root->left=binaryTree(root->left);

        cout<<"enter the data to the right of:"<<data<<endl;
        root->right=binaryTree(root->right);

        return root;
    }

void levelOrderTraversal(Node* root){
    queue<Node*> q;
    q.push(root);
    q.push(NULL);

    while (!q.empty())
    {
        Node* temp=q.front();
        q.pop();

        if (temp==NULL)
        {
            // purana level complete traverse ho chuka h
            cout<<endl;

            if (!q.empty())
            {
                // queue still has some child nodes
                q.push(NULL);
            }
        }

        else
        {
            cout<<temp->data<<" ";

            if (temp->left)
            {
                q.push(temp->left);
            }
            
            if (temp->right)
            {
                q.push(temp->right);
            }
        }
    }
}

void inorder(Node* root){
    // base case
    if (root==NULL)
    {
        return ;
    }

    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

void preorder(Node* root){
    // base case
    if (root==NULL)
    {
        return ;
    }

    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);  
}

void postorder(Node* root){
    // base case
    if (root==NULL)
    {
        return ;
    }
    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" "; 
}

void buildFromLevelOrder(Node* &root){
    queue<Node*> q;
    cout<<"enter data for root node:";
    int data;
    cin>>data;

    root=new Node(data);
    q.push(root);

    while (!q.empty())
    {
        Node* temp=q.front();
        q.pop();

        cout<<"enter data for the left of:"<<temp->data<<endl;
        int leftdata;
        cin>>leftdata;

        if (leftdata!=-1)
        {
            temp->left=new Node(leftdata);
            q.push(temp->left);
        }

        cout<<"enter data for the right of:"<<temp->data<<endl;
        int rightdata;
        cin>>rightdata;

        if (rightdata!=-1)
        {
            temp->right=new Node(rightdata);
            q.push(temp->right);
        }        
    } 
}


int main(){

    Node *root=NULL;
    // root=binaryTree(root);


    // 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
    // cout<<"printing the level order traversal output:"<<endl;

    // levelOrderTraversal(root);

    // cout<<"inorder traversal is:";
    // inorder(root);

    // cout<<"preorder traversal is:";
    // preorder(root);

    // cout<<"postorder traversal is:";
    // postorder(root);


    buildFromLevelOrder(root);
    levelOrderTraversal(root);


    
return 0;
}