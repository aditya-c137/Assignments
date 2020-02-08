/*
*	Creation not working. Needs major fixes!
*/


#include<iostream>

struct tree{
    int data;
    struct tree *left;
    struct tree *right;
    
};
struct tree* plant_de_tree_ka_root(struct tree *ROOT);
void see_de_tree_inorder(struct tree *ROOT);
void see_de_tree_preorder(struct tree *ROOT);
void see_de_tree_postorder(struct tree *ROOT);
struct tree* plant_de_tree(struct tree *ROOT,int flag);

int main(){
    struct tree *root;
    root = plant_de_tree(root,0);
    std::cout<<"\n\nInorder: ";
    see_de_tree_inorder(root);
    std::cout<<"\n\nPreorder: ";
    see_de_tree_preorder(root);
    std::cout<<"\n\nPostorder: ";
    see_de_tree_postorder(root);
    std::cout<<"\n";
    return 0;
}

struct tree* plant_de_tree_ka_root(struct tree *ROOT){
        ROOT = new tree;
        std::cout<<"enter root: ";
        std::cin>>ROOT->data;
}


struct tree* plant_de_tree(struct tree *ROOT,int flag){
    if(flag == 0){
        ROOT = plant_de_tree_ka_root(ROOT);
    }
    if(flag == 1){
        ROOT = new tree;
    }
    int ooolala_temp;
    std::cout<<"Enter data(0 to stop): ";
    std::cin>>ooolala_temp;
    if(ooolala_temp == 0){
        return NULL;
    }
    if(ROOT->data > ooolala_temp){
        ROOT->left = plant_de_tree(ROOT->left,1);
    }
    if(ROOT->data < ooolala_temp){
        ROOT->right = plant_de_tree(ROOT->right,1);
    }
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
