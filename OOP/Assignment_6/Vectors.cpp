#include<iostream>
#include<vector>

int main(){
    std::vector<int> v;
    int h;
    for(int i = 0;i<5;i++){
        std::cin>>h;
        v.push_back(h);
    }
    for(int i = 0;i<5;i++){
        std::cout<<v[i];
    }
}
