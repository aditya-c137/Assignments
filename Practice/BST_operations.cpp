#include<iostream>

using namespace std;


struct node{
	int data;
	struct node *left, *right;
	int level;
};



struct node* create(int data,int level){
	struct node *temp;
	temp = new node;
	temp->data = data;
	temp->level = level;
	temp->left = NULL;
	temp->right = NULL;
	return temp;
}

struct node* insert(struct node *root, int data,int level){
	if(root == NULL)
		return create(data,level);
	else if(root->data < data){
		level++;
		root->right = insert(root->right,data,level);
		level--;
	}
	else if(root->data > data){
		level++;
		root->left = insert(root->left,data,level);
		level--;
	}
	return root;
}

struct node* search(struct node *root,int data){
	if(root == NULL)
		cout<<"not found\n\n";
	else if(root->data == data){
		cout<<"found\n";
		return root;
	}
	else if(root->data > data)
		search(root->left,data);
	else
		search(root->right,data);
	
}
void del(struct node* root, int data){
	struct node* temp;
	
}


int main(){
	struct node *root = NULL;
	int p,level = 0;
	root = insert(root,6,0);
	root = insert(root,4,0);
	root = insert(root,5,0);
	root = insert(root,3,0);
	root = insert(root,10,0);
	root = insert(root,11,0);
	root = insert(root,8,0);
	cout<<root->data<<endl<<root->left<<endl<<root->right<<endl;
	cout<<"\n\nsearch: ";
	cin>>p;
	search(root,p);
	cout<<endl;
	return 0;
}
