#include "List.h"
#include <iostream>

int main()
{   
    //push_back,pop_backpop_front,push_front
    std::cout<<"push_back,pop_backpop_front,push_front"<<std::endl;
    List<int> lst1;
    for (int i = 0; i < 10; ++i)
    {
        lst1.push_back(i);
    }

    lst1.pop_back();
    lst1.pop_front();
    lst1.push_front(10);

    for (auto it : lst1)
    {
        std::cout << it << "\t";
    }
    std::cout<<"\n"<<std::endl;
  

    // for (auto it = lst.begin(); it != lst.end(); ++it)
    // {
    //     std::cout << *it << std::endl;
    // }

    //big5
    std::cout<<"big5"<<std::endl;
    List<int> lst2 {1, 2, 3, 4, 5};
    lst2.print();

    List<int> lst3(lst2);
    lst3.print();

    List<int> lst4(std::move(lst2));
    lst4.print();

    List<int> lst5 = lst3;
    lst5.print();

    List<int> lst6 = std::move(lst3);
    lst6.print();

    std::cout<<"\n"<<std::endl;


    //size,empty,clear
    std::cout<<"size,empty,clear"<<std::endl;
    std::cout <<"size of lst1:"<<lst1.size()<< std::endl;
    std::cout <<"is lst1 empty?"<<lst1.empty()<< std::endl;
    lst1.clear();
    std::cout <<"is lst1 empty?"<<lst1.empty()<< std::endl;

    std::cout<<"\n"<<std::endl;

    //back,front
    std::cout<<"back,front"<<std::endl;
    lst1=lst6;
    std::cout <<"back:"<<lst1.back()<<" "<<"front:"<<lst1.front()<< std::endl;

    std::cout<<"\n"<<std::endl;

    //insert,erase
    std::cout<<"insert,erase"<<std::endl;
    auto it1 = ++lst1.begin();
    lst1.insert(it1,11);
    lst1.print();

    auto it2 = --lst1.end();
    lst1.erase(it2);
    lst1.print();

    auto it3 = --lst1.end();
    lst1.erase(it1,it3);
    lst1.print();


















// //    List<int> lst2 = std::move(lst);
//     List<int> lst2 = List<int> {5, 6};
//     for (auto &x : lst2)
//     {
//         std::cout << x << "\t";
//     }
//     std::cout << std::endl;

//     lst2 = std::move(lst);
//     for (auto &x : lst2)
//     {
//         std::cout << x << "\t";
//     }
//     std::cout << std::endl;

    return 0;
}
