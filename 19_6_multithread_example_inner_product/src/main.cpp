
#include <mutex>
#include <chrono>
#include <vector>
#include <thread>
#include <iostream>
#include <numeric>
#include <random>
#include <atomic>


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
        unsigned long long sum;
        const unsigned num_per_thread = data_size / cpu_num;

        vector<std::thread> t_vec;
        // caution!!! Must have to do resize!!
        t_vec.resize(cpu_num);

        for( auto i = 0; i < cpu_num; i++){
            // t_vec[i] = thread(calcProductMtx, ref(v0), ref(v1), i * num_per_thread, (i + 1) * num_per_thread, ref(sum));
            t_vec[i] = thread(calcProductAtomic, ref(v0), ref(v1), i * num_per_thread, (i + 1) * num_per_thread, ref(sum));
        }

        for (auto &elem : t_vec)
            elem.join();

        const auto tock = std::chrono::steady_clock::now();
        const chrono::duration<double> duration = tock - tick;
        cout << duration.count() << endl;
        cout << sum << endl;
        cout << endl;
    }

    return 0;
}