#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

int main(){

    // basic cout and cin
    {
        int x;
        cout << "Type Number : ";
        cin >> x;
        cout << "Your Number : " << x << endl;
    }

    // how buffer works
    {
        // Got Error if user type long string (longer than 5, including null char) 
        // *** stack smashing detected ***: <unknown> terminated
        // Aborted (core dumped)

        char buf[5];
        cout << "Type String : ";
        cin >> setw(5) >> buf;
        cout << "Your String : " << buf << endl;
        
        cin.ignore(32767, '\n'); cin.clear();
    }

    // cin
    {
        // cin ignores white space
        char ch;

        cout << "Type String : ";
        while(cin >> ch){
            if (ch == '!') {
                cout << endl; 
                break;
            }
            cout << ch;
        }
        cin.ignore(32767, '\n'); cin.clear();

        // use get for white space input
        cout << "Type String Again (whitespace allowed) : ";
        while(cin.get(ch)){
            if (ch == '!') {
                cout << endl; 
                break;
            }
            cout << ch;
        }
        cin.ignore(32767, '\n'); cin.clear();
    }

    // gcount, getline
    {
        char buf[5];

        cout << "Type String : ";

        cin.get(buf, 5);
        cout << cin.gcount() << " " << buf << endl;

        cin.get(buf, 5);
        cout << cin.gcount() << " " << buf << endl;

        cin.ignore(32767, '\n'); cin.clear();
    }

    // getline
    {
        char long_buf[100];

        cout << "Type String : ";

        cin.getline(long_buf, 100);
        cout << cin.gcount() << " " << long_buf << endl;

        cin.getline(long_buf, 100);
        cout << cin.gcount() << " " << long_buf << endl;
    }

    // use more comfortable with string buffer
    {
        string buf;
        
        getline(cin, buf);

        cout << cin.gcount() << " " << buf << endl;
    }

    // ignore
    {
        char buf[1024];

        // must be located before cin >>
        cin.ignore(5);

        cin >> buf;
        cout << buf << endl;

        // this is my word 
        // is
    }

    // peek
    {
        char buf[1024]; 

        // just peek, don't get anything from buffer
        cout << (char)cin.peek() << endl;

        cin >> buf;

        // this is my word 
        // t
    }

    // unget
    {
        char buf[1024];

        cin >> buf;
        cout << buf << endl;

        cin.unget();
        cout << buf << endl;

        // this is my word 
        // this
        // this
    }

    // putback
    {
        char buf[10];

        cin.putback('a');

        cin.getline(buf, 10);
        cout << buf << endl;

        // apple
        // a apple
    }

    return 0;
}