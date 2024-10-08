#include <initializer_list>
#include <iostream>

template <typename T>
class SingleLinkedList
{
private:
    class Node
    {
    private:
        T data;
        Node *next = nullptr;
        Node(T _val){data = _val;}

        friend class SingleLinkedList<T>;
    };
    Node* head = nullptr;
    int size = 0;
    Node* currentPos = nullptr;
    void _emptyList();
    void _copy(const SingleLinkedList<T> &_l);
public:
    /// 返回当前位置的值
    T getCurrentVal() const;
    /// 设置当前位置的值
    void setCurrentVal(T &_val);
    /// 如果链表为空，返回 true；否则返回 false
    bool isEmplty() const;

    int getSize() const;
    void emptyList();
    bool find (const T &_val);
    SingleLinkedList(){};
    ~SingleLinkedList(); 
    SingleLinkedList(std::initializer_list<T> _l);
    void printList() const;
    SingleLinkedList(const SingleLinkedList<T> &_l);
    SingleLinkedList<T>& operator=(const SingleLinkedList<T> &_l);

    /// 在 currentPos 后面插入一个元素，数据为 _val
    void insert(T _val); 
    /// 如果找到，返回 ture, currentPos 停留在第一个 _val 的位置。
    /// 否则返回 false, currentPos 不动。
    bool find(const T &_val) const;  
    /// 删除 currentPos 后面的元素
    void remove(); 
    // 删除 currentPos 的元素，currentPos指向原currentPos之后的元素
    void remove_update();                                       
};

template<typename T>
bool SingleLinkedList<T>::find(const T &_val)
{
    Node *p = head;
    while (p != nullptr)
    {
        if (p->data == _val)
        {
            currentPos = p;
            return true;
        }
        p = p->next;    
    }
    return false;
}

template<typename T>
int SingleLinkedList<T>::getSize() const
{
    return size;
}

template <typename T>
SingleLinkedList<T>::SingleLinkedList(std::initializer_list<T> _l)
{
    for (auto i = _l.begin(); i != _l.end(); ++i)
    {
        Node* newNode = new Node(*i);
        if (head == nullptr)
        {
            head = newNode;
            currentPos = head;
        }
        else
        {
            currentPos->next = newNode;
            currentPos = newNode;
        }
        ++size;
    }
}

template <typename T>
void SingleLinkedList<T>::_emptyList()
{
    Node* p = head;
    while (p != nullptr)
    {
        Node* t = p;
        p = p->next; 
        delete t;
    }
}

template <typename T>
void SingleLinkedList<T>::printList() const
{
    Node* p = head;
    while (p != nullptr)
    {
        std::cout << p->data << "\t";
        p = p->next;
    }
    std::cout << std::endl;    
}

template <typename T>
SingleLinkedList<T>::~SingleLinkedList()
{
    _emptyList();
};

template<typename T>
SingleLinkedList<T>::SingleLinkedList(const SingleLinkedList<T> &_l)
{
    _copy(_l);
}

template<typename T>
void SingleLinkedList<T>::emptyList()
{
    _emptyList();
    head = nullptr;
    currentPos = nullptr;
    size = 0;
}

//这段源代码中if(this == _l)是不是写错了？
template<typename T>
SingleLinkedList<T>& SingleLinkedList<T>::operator=(const SingleLinkedList<T> &_l)
{
    if (*this == _l)
        return *this;
    emptyList();
    _copy(_l);
    return *this;
}

template <typename T>
void SingleLinkedList<T>::_copy(const SingleLinkedList<T> &_l)
{
    Node *p = _l.head;
    while (p != nullptr)
    {
        Node* newNode = new Node(p->data);
        if (head == nullptr)
        {
            head = newNode;
            currentPos = head;
        }
        else
        {
            currentPos->next = newNode;
            currentPos = newNode;
        }
        ++size;
        p = p->next;
    }
}

template<typename T>  
T SingleLinkedList<T>::getCurrentVal() const 
{  
    if (currentPos != nullptr) 
    {  
        return currentPos->data;  
    }  
    else
    {
        throw std::runtime_error("当前位置为空，无法获得值");
    }
}

template<typename T>  
void SingleLinkedList<T>::setCurrentVal(T &_val) 
{  
    if (currentPos != nullptr) 
    {  
        currentPos->data = _val;  
    } 
    else 
    {  
        std::cout<<"当前位置为空，无法设置值"<<std::endl;  
    }  
}

template<typename T>  
bool SingleLinkedList<T>::isEmplty() const 
{  
    return head == nullptr;  
}

template<typename T>  
void SingleLinkedList<T>::insert(T _val) {  
    Node* newNode = new Node(_val);  
    if (currentPos == nullptr) {  
        newNode->next = nullptr;  
        head = newNode;  
        currentPos = head;  
    } else 
    {  
        newNode->next = currentPos->next;  
        currentPos->next = newNode;  
    }  
    size++;  
}

template<typename T>  
void SingleLinkedList<T>::remove() 
{  
    if (currentPos == nullptr || currentPos->next == nullptr) 
    {  
        std::cout<<"没有可删除的元素"<<std::endl; 
    }  
    Node* p = currentPos->next;  
    currentPos->next = p->next;  
    delete p;  
    size--;  
} 

template<typename T>  
void SingleLinkedList<T>::remove_update() 
{  
    if (currentPos == nullptr) 
    {  
        std::cout<<"没有可删除的元素"<<std::endl;
    }  
    else if (currentPos == head) 
    {  
        head = head->next;  
        delete currentPos;  
        currentPos = head;  
    } 
    else 
    {  
        Node* pre = head;  
        while (pre != nullptr && pre->next != currentPos)
        {  
            pre = pre->next;  
        }  
        if (pre == nullptr) 
        {  
            std::cout<<"没有可删除的元素"<<std::endl; 
        }  
        pre->next = currentPos->next;  
        delete currentPos;  
        currentPos = pre->next; 
    }  
    size--;  
}  