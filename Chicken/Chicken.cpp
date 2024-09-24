#include <iostream>
#include <cstring>

class Chicken
{
    private:
        int age = 24;
        char *name = nullptr;
    public:
        Chicken(){};
        Chicken(int _age) : age(_age) {};
        Chicken(int _age, const char *_name) : age(_age) 
        {
            int len = strlen(_name) + 1;
            name = new char[len];
            for (int i = 0; i < len; i++)
                name[i] = _name[i];
        };

        
        //复制构造函数
        Chicken(const Chicken &other){
        age = other.age;
        if (other.name)  {
            name = new char[strlen(other.name) + 1];
            strcpy(name, other.name); 
        }
        else name = nullptr;     
        };

        // 赋值运算函数
        Chicken &operator=(const Chicken &other){
            if (this == &other) return *this;
            delete[] name;
            age = other.age;
            if (other.name){
                name = new char[strlen(other.name) + 1];
                strcpy(name, other.name);
            }
            else{
                name = nullptr;
            }

            return *this; 
        };

        ~Chicken()
        {
            if (name != nullptr)
                delete[] name;
        }
        void setAge(int _age)
        {
            age = _age;
        }
        void setName(const char *_name)
        {
            int len = strlen(_name) + 1;
            name = new char[len];
            for (int i = 0; i < len; i++)
                name[i] = _name[i];
        }

        const char *getName() const
        {
            return name;
        }

        const int &getAge() const
        {
            return age;
        }
};

int main()
{
    Chicken c(24, "Kunkun");
    std::cout << "c: "<<"Hi, everyone! My name is " << c.getName() << ", I am " << c.getAge() << " years old." << std::endl;
    Chicken A,B;
    A=B=c;
    Chicken D(A);
    std::cout <<"A: "<< "Hi, everyone! My name is " << A.getName() << ", I am " << A.getAge() << " years old." << std::endl;
    std::cout <<"B: "<<"Hi, everyone! My name is " << B.getName() << ", I am " << B.getAge() << " years old." << std::endl;
    std::cout <<"D: "<< "Hi, everyone! My name is " << D.getName() << ", I am " << D.getAge() << " years old." << std::endl;
    return 0;
}

/*请优化这段代码，要求：
1. 给这段代码增加复制操作和赋值操作，要求能实现深度赋值和连续赋值操作；
2. 请检查最后的结果，避免出现内存泄露，消除可能的 bug，并正确使用左值引用、指针和 const 关键字。
完成后请提交到你的 git 目录，命名为 Chicken.cpp 并确保助教能获取。*/
