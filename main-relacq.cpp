#include <iostream>
#include <atomic>
#include <thread>
#include <chrono>
#include <mutex>

int data = 0;
std::atomic<bool> data_ready(false);
std::mutex m;

void produce() {
    {
        std::lock_guard<std::mutex> lock(m);
        std::cout << "producer running\n";    
    }

    data = 42;
    // ^^^^^^^^^^^^^^^^^^^^^^^^^^^
    // data = 42 will became visible to other threads
    // doing the acquire
    data_ready.store(true, std::memory_order_release);
}


void consume() {
    {
        std::lock_guard<std::mutex> lock(m);
        std::cout << "consumer running\n";
    }
    
    while (!data_ready.load(std::memory_order_acquire));
    data++;
}

int main(int argc, char* argv[]) {
    std::thread producer(produce);
    std::thread consumer(consume);

    producer.join();
    consumer.join();
    std::cout << data << "\n";
    return data;
}
