// remove_update():删除 currentPos 的元素，currentPos指向原currentPos之后的元素

/*这段源代码中if(this == _l)是不是写错了？
template<typename T>
SingleLinkedList<T>& SingleLinkedList<T>::operator=(const SingleLinkedList<T> &_l)
{
    if (*this == _l)
        return *this;
    emptyList();
    _copy(_l);
    return *this;
} */

#include "LinkedList.h"

int main()
{
    SingleLinkedList<int> link1 {1, 2, 3, 4, 5};
    link1.printList();
    std::cout<<link1.isEmplty()<<std::endl;
    link1.find(3);
    int a=link1.getCurrentVal();
    std::cout<<a<<std::endl;
    int val = 7;
    link1.setCurrentVal(val);
    link1.printList();
    link1.insert(val);
    link1.printList();
    link1.find(4);
    link1.remove();
    link1.printList();
    link1.remove_update();
    link1.printList();
    return 0;
};