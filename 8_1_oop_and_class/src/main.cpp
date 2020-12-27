#include <iostream> 
#include <vector>
#include <string>

using namespace std;

// Make Freind : name, address, age, height, weight, ... 
void print(const string &name, const string &address, const int &age, 
    const double &height, const double &weight)
{
    cout << name << " " << address << " " << age << " " << 
        height << " " << weight << endl;
}

// Friend Struct
struct FriendStruct{
    string  name;
    string  address;
    int     age;
    double  height;
    double  weight;

    void print(){
        cout << name << " " << address << " " << age << " " << 
            height << " " << weight << endl;
    }
};

// Friend Class
class FriendClass{
public: // access classifier
    string  m_name;
    string  m_address;
    int     m_age;
    double  m_height;
    double  m_weight;

    void print(){
        cout << m_name << " " << m_address << " " << m_age << " " << 
            m_height << " " << m_weight << endl;
    }
};

using namespace std; 

int main(){

    // Tough Coding
    {
        string name = "Kim";
        string address = "Seoul";
        int age = 22;
        double height = 178.5;
        double weight = 73.5;

        print(name, address, age, height, weight);

        vector<string> name_vec {"Park"};
        vector<string> address_vec {"Cupertino"};
        vector<int> age_vec {25};
        vector<double> height_vec {178.43};
        vector<double> weight_vec {65.4};

        print(name_vec[0], address_vec[0], age_vec[0],
                height_vec[0], weight_vec[0]);
    }

    // Using Struct
    {
        FriendStruct first_friend {"Whang","Pusan",50,160.5,78.4};
        first_friend.print();
    }

    // Using Class
    {
        cout << "==== Using Class ====" << endl;
        FriendClass first_friend {"Whang","Pusan",50,160.5,78.4};
        first_friend.print();
    }

    // Class with vector
    {
        cout << "==== Class with vector ====" << endl;
        vector<FriendClass> friends;
        friends.resize(2);
        
        for (auto &elem : friends)
            elem.print();
    }

    return 0;
}