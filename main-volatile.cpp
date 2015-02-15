#include <iostream>
#include <atomic>
#include <thread>
#include <chrono>
#include <mutex>

int data = 0;
volatile int data_ready = 0x0;
std::mutex m;

void produce() {
    {
        std::lock_guard<std::mutex> lock(m);
        std::cout << "producer running\n";    
    }

    data = 42;
    data_ready = 1;
}


void consume() {
    {
        std::lock_guard<std::mutex> lock(m);
        std::cout << "consumer running\n";
    }
    
    while (!data_ready);
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