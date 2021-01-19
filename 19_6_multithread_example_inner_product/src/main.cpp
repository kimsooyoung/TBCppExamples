
#include <mutex>
#include <chrono>
#include <vector>
#include <thread>
#include <iostream>
#include <numeric>
#include <random>
#include <atomic>
#include <future>
#include <functional>
// requires latest gcc Basic gcc in Ubuntu 18.04 doesn't have it
// #include <execution>


using namespace std;

mutex mtx;

void calcProduct(const vector<int>& v0, const vector<int>& v1,
    const unsigned &start, const unsigned &end, unsigned long long &sum){
    
    // cout << start << " " << end << endl;
    for (unsigned i = start; i < end; i++){
        sum += v0[i] * v1[i];
    }
}

void calcProductMtx(const vector<int>& v0, const vector<int>& v1,
    const unsigned &start, const unsigned &end, unsigned long long &sum){
    
    for (unsigned i = start; i < end; i++){
        mtx.lock();
        sum += v0[i] * v1[i];
        mtx.unlock();
    }
}

void calcProductLockGuard(const vector<int>& v0, const vector<int>& v1,
    const unsigned &start, const unsigned &end, unsigned long long &sum){
    
    for (unsigned i = start; i < end; i++){
        lock_guard<mutex> lock(mtx);
        sum += v0[i] * v1[i];

    }
}

void calcProductScopedGuard(const vector<int>& v0, const vector<int>& v1,
    const unsigned &start, const unsigned &end, unsigned long long &sum){
    
    for (unsigned i = start; i < end; i++){
        scoped_lock lock(mtx); // c++ 17
        sum += v0[i] * v1[i];
    }
}

void calcProductAtomic(const vector<int>& v0, const vector<int>& v1,
    const unsigned &start, const unsigned &end, atomic<unsigned long long> &sum){
    
    for (unsigned i = start; i < end; i++){
        sum += v0[i] * v1[i];
    }
}

int calcFuture(const vector<int>& v0, const vector<int>& v1,
    const unsigned &start, const unsigned &end){

    int sum = 0;

    for(unsigned i = start; i < end; i++){
        sum += v0[i] * v1[i];
    }

    return sum;
}

void calcPromise(const vector<int>& v0, const vector<int>& v1,
    const unsigned &start, const unsigned &end, promise<int> &&p){

    int sum = 0;

    for(unsigned i = start; i < end; i++){
        sum += v0[i] * v1[i];
    }

    p.set_value(sum);
}

int main(){

    const auto cpu_num = 4; //std::thread::hardware_concurrency();
    const auto data_size = 10'000'000;

    vector<int> v0, v1;
    v0.reserve(data_size);
    v1.reserve(data_size);

    random_device seed;
    mt19937 engine(seed());

    uniform_int_distribution<> uniformDist (1, 10);

    for (auto i = 0; i < data_size; i++)
    {
        v1.push_back(uniformDist(engine));
        v0.push_back(uniformDist(engine));
    }

    cout << "Built in Function" << endl;
    {
        const auto tick = std::chrono::steady_clock::now();

        const auto sum = std::inner_product(v0.begin(), v0.end(), v1.begin(), 0ull);

        const auto tock = std::chrono::steady_clock::now();
        const chrono::duration<double> duration = tock - tick;
        cout << duration.count() << endl;
        cout << sum << endl;
        cout << endl;
    }

    cout << "Naive" << endl;
    {
        const auto tick = std::chrono::steady_clock::now();
        
        unsigned long long sum = 0;
        const unsigned num_per_thread = data_size / cpu_num;

        vector<std::thread> t_vec;
        // caution!!! Must have to do resize!!
        t_vec.resize(cpu_num);

        for( auto i = 0; i < cpu_num; i++){
            t_vec[i] = thread(calcProduct, ref(v0), ref(v1), i * num_per_thread, (i + 1) * num_per_thread, ref(sum));
        }

        for (auto &elem : t_vec)
            elem.join();

        const auto tock = std::chrono::steady_clock::now();
        const chrono::duration<double> duration = tock - tick;
        cout << duration.count() << endl;
        cout << sum << endl;
        cout << endl;
    }

    cout << "Mutex" << endl;
    {
        const auto tick = std::chrono::steady_clock::now();
        
        // strange :( If I don't reset sum to 0 it is summazed agin
        // MacOS, It doesn't matter ://
        // unsigned long long sum = 0;
        atomic<unsigned long long> sum(0);

        const unsigned num_per_thread = data_size / cpu_num;

        vector<std::thread> t_vec;
        // caution!!! Must have to do resize!!
        t_vec.resize(cpu_num);

        for( auto i = 0; i < cpu_num; i++){
            // Naive : 0.112682
            // t_vec[i] = thread(calcProductMtx, ref(v0), ref(v1), i * num_per_thread, (i + 1) * num_per_thread, ref(sum)); // 1.02458
            // t_vec[i] = thread(calcProductLockGuard, ref(v0), ref(v1), i * num_per_thread, (i + 1) * num_per_thread, ref(sum)); // 1.41518
            // t_vec[i] = thread(calcProductScopedGuard, ref(v0), ref(v1), i * num_per_thread, (i + 1) * num_per_thread, ref(sum)); // 1.14493
            t_vec[i] = thread(calcProductAtomic, ref(v0), ref(v1), i * num_per_thread, (i + 1) * num_per_thread, ref(sum)); // 0.217684
        }

        for (auto &elem : t_vec)
            elem.join();

        const auto tock = std::chrono::steady_clock::now();
        const chrono::duration<double> duration = tock - tick;
        cout << duration.count() << endl;
        cout << sum << endl;
        cout << endl;
    }

    cout << "Future" << endl;
    {
        const auto tick = std::chrono::steady_clock::now();
        
        unsigned long long sum;
        const unsigned num_per_thread = data_size / cpu_num;

        vector<std::future<int>> fut_vec;
        // caution!!! Must have to do resize!!
        fut_vec.resize(cpu_num);

        for( auto i = 0; i < cpu_num; i++){
            fut_vec[i] = std::async(calcFuture, ref(v0), ref(v1), i * num_per_thread, (i + 1) * num_per_thread); // 0.0267306 GREAT!!
        }

        for (auto &elem : fut_vec)
            sum += elem.get();

        const auto tock = std::chrono::steady_clock::now();
        const chrono::duration<double> duration = tock - tick;
        cout << duration.count() << endl;
        cout << sum << endl;
        cout << endl;
    }


    cout << "Promise" << endl;
    {
        const auto tick = std::chrono::steady_clock::now();
        
        unsigned long long sum;
        const unsigned num_per_thread = data_size / cpu_num;

        vector<promise<int>> proms;
        vector<future<int>> futures;
        vector<thread> threads;
        proms.resize(cpu_num);
        futures.resize(cpu_num);
        threads.resize(cpu_num);

        for (auto i = 0; i < cpu_num; i++){
            futures[i] = proms[i].get_future();
            threads[i] = thread(calcPromise, ref(v0), ref(v1), i * num_per_thread, (i + 1) * num_per_thread, std::move(proms[i]));
        }
        
        for (auto i = 0; i < cpu_num; i++){
            threads[i].join();
            sum += futures[i].get();
        }

        const auto tock = std::chrono::steady_clock::now();
        const chrono::duration<double> duration = tock - tick;
        cout << duration.count() << endl;
        cout << sum << endl;
        cout << endl;
    }


    cout << "std::transform_reduce" << endl;
    // {
    //     const auto tick = std::chrono::steady_clock::now();

    //     const auto sum = std::transform_reduce(std::execution::par, v0.begin(), v0.end(), v1.begin(), 0ull);

    //     const auto tock = std::chrono::steady_clock::now();
    //     const chrono::duration<double> duration = tock - tick;
    //     cout << duration.count() << endl;
    //     cout << sum << endl;
    //     cout << endl;
    // }


    return 0;
}