#include<iostream>

using namespace std;


struct node{
	int data;
	struct node *left, *right;
};



struct node* create(int data){
	struct node *temp;
	temp = new node;
	temp->data = data;
	temp->left = NULL;
	temp->right = NULL;
	return temp;
}

struct node* insert(struct node *root, int data){
	if(root == NULL)
		return create(data);
	else if(root->data < data)
		root->right = insert(root->right,data);
	else if(root->data > data)
		root->left = insert(root->left,data);
	return root;
}

void inorder(struct node *root){
	if(root != NULL){
		inorder(root->left);
		cout<<root->data<<'\t';
		inorder(root->right);
	}
}

void postorder(struct node *root){
	if(root != NULL){
		postorder(root->left);
		postorder(root->right);
		cout<<root->data<<'\t';
	}
}

void preorder(struct node *root){
	if(root != NULL){
		cout<<root->data<<'\t';
		preorder(root->left);
		preorder(root->right);
	}
}

int main(){
	struct node *root = NULL;
	int p;
	for(int i = 0; i < 10; i++){
		cin>>p;
		if(p == 0)
			break;
		root = insert(root,p);
	}
	cout<<root->data<<endl<<root->left<<endl<<root->right<<endl;
	preorder(root);
	cout<<endl;
	inorder(root);
	cout<<endl;
	postorder(root);
	cout<<endl;
	return 0;
}
