#include <iostream>
#include <memory>

// Resource Class
class Resource {
private:
    int m_arr[100];
public:
    Resource(){
        std::cout << "Resource Constructor" << std::endl;
    }
    
    ~Resource(){
        std::cout << "Resource Destructor" << std::endl;
    }

    void print(){
        std::cout << "Resource Print()" << std::endl;
    }
};

// Similiar to auto_ptr in std
// auto_ptr is deprecated in c++11
template <typename T>
class AutoPtr {
public:
    T *m_ptr = nullptr;
public:
    AutoPtr(T *ptr_in = nullptr) : m_ptr(ptr_in){}
    
    ~AutoPtr(){
        if (m_ptr != nullptr) delete m_ptr; 
    }

    T& operator*()  const { return *m_ptr; }
    T* operator->() const { return m_ptr; }
    bool isNull()   const { return m_ptr == nullptr; }
};


// AutoPtr with Move Semantic
template <typename T>
class AutoPtrWithMS {
public:
    T *m_ptr = nullptr;
public:
    AutoPtrWithMS(T *ptr_in = nullptr) : m_ptr(ptr_in){}
    
    AutoPtrWithMS(AutoPtrWithMS &ptr_in){
        m_ptr = ptr_in.m_ptr;
        ptr_in.m_ptr = nullptr;
    }
    
    ~AutoPtrWithMS(){
        if (m_ptr != nullptr) delete m_ptr; 
    }

    AutoPtrWithMS& operator= (AutoPtrWithMS &ptr_in){
        if (this == &ptr_in )
            return *this;
        
        delete m_ptr;
        m_ptr = ptr_in.m_ptr;
        ptr_in.m_ptr = nullptr;
        return *this;
    }

    T& operator*()  const { return *m_ptr; }
    T* operator->() const { return m_ptr; }
    bool isNull()   const { return m_ptr == nullptr; }
};

void doSomething() { 
    // RAII : Resource Acquisition is Initialization    
    Resource *my_resource = new Resource();
    
    // my_resource must deleted in any function cases 
    if ( false ){
        delete my_resource;
        return ;
    }

    delete my_resource;
}

int main(){

    //
    {
        doSomething();
    }

    std::cout << "=========================" << std::endl;

    // AutoPtr Usage; 
    {
        AutoPtr<Resource> res = new Resource;
    }

    std::cout << "=========================" << std::endl;

    // Limitation of AutoPtr
    {
        // case1
        Resource res_origin;
        AutoPtr<Resource> res;
        
        // res = &res_origin; // Aborted (core dumped)

        // case2
        AutoPtr<Resource> res1(new Resource);
        AutoPtr<Resource> res2;
        
        // std::cout << res1.m_ptr << std::endl;
        // std::cout << res2.m_ptr << std::endl;
        
        // res2 = res1; // Aborted (core dumped)

        // std::cout << res1.m_ptr << std::endl;
        // std::cout << res2.m_ptr << std::endl;
    }

    // solution => move semantic
    {
        AutoPtrWithMS<Resource> res1(new Resource);
        AutoPtrWithMS<Resource> res2;

        std::cout << res1.m_ptr << std::endl;
        std::cout << res2.m_ptr << std::endl;
        
        res2 = res1; 

        std::cout << res1.m_ptr << std::endl;
        std::cout << res2.m_ptr << std::endl;
    }


}