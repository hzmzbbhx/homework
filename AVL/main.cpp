#include <iostream>
#include "Avltree.h" 

void test() {
    AvlTree<int> bst;
    bst.insert(10);
    bst.insert(5);
    bst.insert(15);
    bst.insert(3);
    bst.insert(7);
    bst.insert(12);
    bst.insert(18);

    // 测试删除功能
    bst.remove(7);
    std::cout << "Tree after removing 7:" << std::endl;
    bst.printTree();

    bst.remove(10);
    std::cout << "Tree after removing 10:" << std::endl;
    bst.printTree();

}

int main() {
    test();
    return 0;
}