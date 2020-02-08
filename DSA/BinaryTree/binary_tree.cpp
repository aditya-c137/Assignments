#include<iostream>

struct tree{
    char data;
    struct tree *left;
    struct tree *right;
    
};

void see_de_tree_inorder(struct tree *ROOT);
void see_de_tree_preorder(struct tree *ROOT);
void see_de_tree_postorder(struct tree *ROOT);
struct tree* plant_de_tree(struct tree *ROOT);

int main(){
    struct tree *root;
    std::cout<<"***********Enter in preorder manner***********";
    root = plant_de_tree(root);
    std::cout<<"\n\nInorder: ";
    see_de_tree_inorder(root);
    std::cout<<"\n\nPreorder: ";
    see_de_tree_preorder(root);
    std::cout<<"\n\nPostorder: ";
    see_de_tree_postorder(root);
    std::cout<<"\n";
    return 0;
}

struct tree* plant_de_tree(struct tree *ROOT){
    ROOT = new tree;
    std::cout<<"Enter data(0 to stop): ";
    std::cin>>ROOT->data;
    if(ROOT->data == '0'){
        return NULL;
    }
    ROOT->left = plant_de_tree(ROOT->left);
    ROOT->right = plant_de_tree(ROOT->right);
    return ROOT;
}

void see_de_tree_inorder(struct tree *ROOT){
    if(ROOT!=NULL){
        see_de_tree_inorder(ROOT->left);
        std::cout<<ROOT->data<<"\t";
        see_de_tree_inorder(ROOT->right);
    }
}

void see_de_tree_postorder(struct tree *ROOT){
    if(ROOT!=NULL){
        see_de_tree_postorder(ROOT->left);
        see_de_tree_postorder(ROOT->right);
        std::cout<<ROOT->data<<"\t";
    }
}

void see_de_tree_preorder(struct tree *ROOT){
    if(ROOT!=NULL){
        std::cout<<ROOT->data<<"\t";
        see_de_tree_preorder(ROOT->left);
        see_de_tree_preorder(ROOT->right);
    }
}
