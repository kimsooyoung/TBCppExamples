#include <iostream> 

int main (){

    using namespace std;
    
    // Case 1
    {
        const int val = 4;
        const int *ptr_val = &val;

        // Error
        // *ptr_val = 5; 

        cout << "*ptr_val : " <<  *ptr_val << endl;
    }  

    // Case 2
    {
        int val = 5;
        const int *ptr_val = &val;

        val = 7;
        // Error
        // *ptr_val = 7;
    }
    
    // Case 3
    {
        int val = 3;
        int val_2 = 4;

        const int *ptr_val = &val;

        // Error
        // *ptr_val = 12; 

        ptr_val = &val_2;
    }

    // Case 4
    {
        int val = 6;
        int val_2 = 66;
        int *const ptr_val = &val;

        *ptr_val = 12;
        
        // Error
        // ptr_val = &val_2;        
    }

    // Case 5
    {
        int val = 5;
        int val_2 = 55;
        const int *const ptr_val = &val;

        // Error
        // ptr_val = &val_2;

        // Error
        // *ptr_val = 34;
    }

    return 0;
}