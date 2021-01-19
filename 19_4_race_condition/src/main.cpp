#include <iostream>
#include <thread>
#include <atomic>
#include <mutex>
#include <chrono>

using namespace std;

static mutex mtx;

int main() {

    int shared_memory = 0;
    // atomic<int> shared_memory(0);
    
    auto countFunc = [&](){
        for (auto i = 0; i < 1000; i++){
            std::this_thread::sleep_for(std::chrono::milliseconds(1));
            
            // case 1 - mutex lock
            // unlock makes mistakes 
            // mtx.lock();
            // shared_memory++;
            // mtx.unlock();

            // case 2 - atomic and fetch add
            // shared_memory.fetch_add(1);

            // case 3 - lock_guard
            // lock_guard<mutex> lock(mtx);
            // shared_memory++;

            // case 4 - C++17 scoped_lock
            std::scoped_lock lock(mtx);
            shared_memory++;

        }
    };

    std::thread t1 = std::thread(countFunc);
    std::thread t2 = std::thread(countFunc);

    t1.join();
    t2.join();

    cout << shared_memory << endl;

    return 0;
}