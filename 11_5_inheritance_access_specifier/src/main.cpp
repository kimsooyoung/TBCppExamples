#include <iostream> 

class Base {
private:
    int m_private;
protected:
    int m_protected;
public:
    int m_public;
};

class PrivateDerived : private Base {
public:
    PrivateDerived(){
        // Base::m_private;
        Base::m_protected = 123;
        Base::m_public = 123;
    }
};

class GrandChild : public PrivateDerived{
public:
    GrandChild()
    {
        // PrivateDerived::m_public = 123;
        // PrivateDerived::m_protected = 123;
    }
}

class ProtectedDerived : protected Base {
public:
    ProtectedDerived(){
        // Base::m_private;
        Base::m_protected;
        Base::m_public;
    }
};

class PublicDerived : public Base {
public:
    PublicDerived(){
        // Base::m_private;
        Base::m_protected;
        Base::m_public;
    }
};

int main(){

    Base base;
    // base.m_private;
    // base.m_protected;
    base.m_public;

    PrivateDerived pri_d;
    // pri_d.m_private;
    // pri_d.m_protected;
    // pri_d.m_public;

    ProtectedDerived pro_d;
    // pro_d.m_private;
    // pro_d.m_protected;
    // pro_d.m_public;

    PublicDerived pub_d;
    // pub_d.m_private;
    // pub_d.m_protected;
    pub_d.m_public;


    return 0;
}