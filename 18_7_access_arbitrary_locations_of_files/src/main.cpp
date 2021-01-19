#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>

using namespace std;

int main() {

    const string f_name = "my_file.txt";

    // make file for example
    {
        ofstream ofs(f_name);
        char c = 'a';

        while (c != 'z'){
            ofs << c;
            c++;
        }
        ofs << c;

        ofs.close();
    }

    {
        ifstream ifs(f_name);
        string my_str;

        // seekg(), just watch, don't get it.
        ifs.seekg(3);
        cout << char(ifs.get()) << endl;

        // seek the begin of file
        ifs.seekg(3, ios::beg);
        cout << char(ifs.get()) << endl;

        // seek the end of file
        ifs.seekg(-1, ios::end);
        cout << char(ifs.get()) << endl;

        // tellg, get current cursor location
        ifs.seekg(0, ios::end);
        cout << ifs.tellg() << endl;
    }


    cout << "iofs example" << endl;

    {
        fstream iofs(f_name);

        iofs.seekg(5);
        cout << (char)iofs.get() << endl;
        // f, cursor moves to 6

        iofs.seekg(5);
        // moves again to location 5
        iofs.put('A');
        // put 'A 'at location 5

        iofs.seekg(5);
        cout << (char)iofs.get() << endl;
    }

    return 0;
}