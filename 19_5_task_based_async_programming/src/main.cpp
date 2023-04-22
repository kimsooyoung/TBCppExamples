#include <future>
#include <iostream>
#include <thread>

using namespace std;

int main() {

  // multi threading
  {
    int result;
    thread t1 = thread([&]() { result = 1 + 2; });

    t1.join();
    cout << result << endl;
  }

  // task-based parallelism
  {
    auto fut = async([]() { return 1 + 2; });

    cout << fut.get() << endl;
  }

  // future with promise
  {
    std::promise<int> prom;
    auto fut = prom.get_future();

    thread t1 =
        thread([](promise<int> &&prom) { prom.set_value(1 + 2); }, move(prom));

    cout << fut.get() << endl;
    t1.join();
  }

  // async vs thread

  // async
  {
    auto fut1 = async([]() {
      cout << "[async] First work started" << endl;
      std::this_thread::sleep_for(std::chrono::seconds(2));
      cout << "[async] First work done.. " << endl;
    });

    auto fut2 = async([]() {
      cout << "[async] Second work started" << endl;
      std::this_thread::sleep_for(std::chrono::seconds(1));
      cout << "[async] Second work done.. " << endl;
    });

    fut1.get();
    fut2.get();
  }

  // same work with thread
  {
    auto t1 = thread([]() {
      cout << "[thread] First work started" << endl;
      std::this_thread::sleep_for(std::chrono::seconds(2));
      cout << "[thread] First work done.. " << endl;
    });

    auto t2 = thread([]() {
      cout << "[thread] Second work started" << endl;
      std::this_thread::sleep_for(std::chrono::seconds(1));
      cout << "[thread] Second work done.. " << endl;
    });

    t1.join();
    t2.join();
  }

  return 0;
}