// A C++ program that demonstrates multithreading.
// The program uses a counter to increment and decrement.
#include <iostream>
#include <thread>
#include <mutex>

// mutex critical section
std::mutex mtx;

//initializing shared resource counter
int counter = 0;

// function to decrement the counter
void decrement(const std::string& thread_name){
    std::cout << "..........Starting "<<thread_name.c_str()<<".........."<< std::endl;
    // Beginning the lock to avoid share resource interruption in loop
    mtx.lock();
    for (int i = 0; i < 20; i++) {
        //incrementing and displaying counter value in loop
        --counter;
        std::cout << thread_name.c_str() << ": " << counter << std::endl;
    }
    // unlocking the resource
    mtx.unlock();
    // displaying the thread name and success message
    std::cout << thread_name.c_str() <<" Finished";
}

// function to increment the counter
void increment(const std::string& thread_name){
    std::cout << "..........Starting "<<thread_name.c_str()<<".........."<< std::endl;
    // Beginning the lock to avoid share resource interruption in loop
    mtx.lock();
    //line to show initial counter value
    std::cout << thread_name.c_str() << ": " << counter << std::endl;
    for (int i = 0; i < 20; i++) {
        //incrementing and displaying counter value in loop
            ++counter;
            std::cout << thread_name.c_str() << ": " << counter << std::endl;
    }
    // unlocking the resource
    mtx.unlock();
    // displaying the thread name and success message
    std::cout << thread_name.c_str() <<" Finished" << std::endl;

}

// main function
int main(){
    // starting thread using function pointer
    std::thread first(increment, "Thread One");
    // Wait for first thread to finish
    first.join();

    // starting thread using function pointer
    std::thread second(decrement, "Thread Two");
    // Wait for second thread to finish
    second.join();
    //end
    return 0;
}