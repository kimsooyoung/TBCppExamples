#include <iostream>
#include <string>

class Son {
private:
    double score_;
    std::string name_;
public:
    Son(const std::string name= "Swimming"){
        name_ = name;
        score_ = 0;
    }

    void setScore(const double& score){
        score_ = score;
    }

    friend class Mother;
};

class Mother {
private:
    std::string name_;
public:
    Mother(const std::string& name= "Mrs. Whang"){
        name_ = name;
    }

    void viewSonScore(const Son& son){
        printf("My Son got %f\n", son.score_);
    }
};


int main(){

    Son son1;
    son1.setScore(70.5);
    Mother mother1;

    mother1.viewSonScore(son1);

    return 0;
}