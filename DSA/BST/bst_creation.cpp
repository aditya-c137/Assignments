#include<iostream>

class Tree{
	Tree * right;
	Tree * left;
	public: 
		int data;
		friend Tree* create(Tree* root, int dta);
};

int main(){
	Tree *Root;int dat = 0;
	Root = new Tree;
	std::cout<<"Enter Data: ";
	std::cin>>Root->data;
	Root = create(Root, dat);
	return 0;
}

Tree* create(Tree* root, int dta){
	std::cout<<"Enter next: ";
	std::cin>>dta;
	if(root->data ==0){
		root->data = dta;
	}
	else if(root->data > dta){
		root->right = new Tree;
		root->right = create(root->right, dta);
	}
	else if(root->data<dta){
		root->left = new Tree;
		root->left = create(root->left, dta);
	}
	return root;
}
