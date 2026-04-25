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
        Chicken(const Chicken &other)
        {
            age = other.age;
            if (other.name)  
            {
                name = new char[strlen(other.name) + 1];
                strcpy(name, other.name); 
            }
            else name = nullptr;     
        };

        // 赋值运算函数
        Chicken &operator=(const Chicken &other)
        {
            if (this == &other) return *this;
            delete[] name;
            age = other.age;
            if (other.name)
            {
                name = new char[strlen(other.name) + 1];
                strcpy(name, other.name);
            }
            else
            {
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
        //修改后
        void setName(const char *_name)
        {   
            if(this->name != _name)
            {
                if(name != nullptr)
                    delete[] name;
                int len = strlen(_name) + 1;
                name = new char[len];
                for (int i = 0; i < len; i++)
                    name[i] = _name[i];
            }
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
    /*
    auto print =[] (const Chicken &c){
        std::cout <<"Hi,my name is "<<c.getName()<<". I'm "<<c.getAge()<<" years old. "<<std::endl;   
    };
    Chicken c(24, "Kunkun");
    print (c);

    Chicken d;
    d=c;
    print(d);

    Chicken a=c;
    print(a);

    c.setName("Zju");
    print(c);
    print(a);
    print(d);

    Chicken b;
    b=d=c;
    print(b);
    print(d);

    c.setName(c.getName());
    std::cout<<c.getName();

    return 0;
    */
}