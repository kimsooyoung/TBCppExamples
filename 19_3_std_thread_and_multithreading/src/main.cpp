#include <thread>
#include <vector> 
#include <iostream>
#include <string>
#include <chrono>
#include <mutex>

using namespace std;

mutex mtx;

int main(){

    // {
    //     cout << std::thread::hardware_concurrency() << endl;

    //     cout << std::this_thread::get_id() << endl;
    // }

    // // make basic thread
    // {
    //     std::thread t1 = std::thread([]() { 
    //         cout << std::this_thread::get_id() << endl;
    //         while(true) {} 
    //     });


    //     t1.join();
    // }

    // multiple threading => See the System Monitor
    // {
    //     std::thread t1 = std::thread([]() { 
    //         cout << std::this_thread::get_id() << endl;
    //         while(true) {} 
    //     });

    //     std::thread t2 = std::thread([]() { 
    //         cout << std::this_thread::get_id() << endl;
    //         while(true) {} 
    //     });
        
    //     std::thread t3 = std::thread([]() { 
    //         cout << std::this_thread::get_id() << endl;
    //         while(true) {} 
    //     });

    //     std::thread t4 = std::thread([]() { 
    //         cout << std::this_thread::get_id() << endl;
    //         while(true) {} 
    //     });


    //     t1.join();
    //     t2.join();
    //     t3.join();
    //     t4.join();
    // }

    // // Multi threading with vector
    // {
    //     const int cpu_num = std::thread::hardware_concurrency();

    //     std::vector<std::thread> t_vec;
    //     t_vec.resize(cpu_num);

    //     for (auto &elem : t_vec){
    //         elem = std::thread([]() {
    //             cout << std::this_thread::get_id() << endl;
    //             while(true){};
    //         });
    //     }

    //     for (auto &elem : t_vec)
    //         elem.join();

    // }

    // mutex
    {
        auto workFunc = [](const string &name_in){
            for (auto i = 0; i < 5; i++){
                std::this_thread::sleep_for(std::chrono::milliseconds(100));

                // mutex lock and unlock
                mtx.lock();
                cout << name_in << " is Working now... Time " << i + 1 << endl;
                mtx.unlock();
            }
        };

        std::thread t1 = std::thread(workFunc, "Mrs. Puff");
        std::thread t2 = std::thread(workFunc, "Patrick Star");

        t1.join();
        t2.join();
    }

    return 0;
}