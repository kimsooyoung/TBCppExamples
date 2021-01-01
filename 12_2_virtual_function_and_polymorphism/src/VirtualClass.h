#pragma once

#include<iostream>

class VirtualA {
public:
    virtual void print(){
        std::cout << "VirtualA" << std::endl;
    }
};

class VirtualB : public VirtualA {
public:
    virtual void print(){
        std::cout << "VirtualB" << std::endl;
    }
};

class VirtualC : public VirtualB {
public:
    virtual void print(){
        std::cout << "VirtualC" << std::endl;
    }
};

class VirtualD : public VirtualC {
public:
    virtual void print(){
        std::cout << "VirtualD" << std::endl;
    }
};
