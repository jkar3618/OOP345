/*
Problem 1: Print "Hello from Thread"
Task: Create a new thread that prints "Hello from thread!". In the main thread, print "Hello from main!".
*/

#include <iostream>
#include <thread>

void threadFunction() {
    std::cout << "Hello from thread!" << std::endl;
}

int main() {
    // Create a new thread that runs threadFunction
    std::thread t1(threadFunction);
    // Print message from the main thread
    std::cout << "Hello from main!" << std::endl;

    // Wait for the thread to finish
    t1.join();

    return 0;
}

/*
Problem 2: Number Printing with Threads
Task: Create two threads.
The first thread should print numbers from 1 to 5.
The second thread should print numbers from 6 to 10.
*/

#include <iostream>
#include <thread>

void printNumbers(int start, int end) {
    // Print numbers from start to end
    for (size_t i = start; i < end; i++)
    {
        std::cout << i;
    }

}

int main() {
    // Create two threads t1, t2
    std::thread t1(printNumbers, 1, 2);
    std::thread t2(printNumbers, 4, 5);

    // Wait for both threads to finish
    t1.join();
    t2.join();

    // Print a newline character
    std::cout << std::endl;

    return 0;
}

/*
Problem 3: Use std::promise and std::future to Pass Data
Task: In a thread, compute the square of a number and pass
the result back to the main thread using std::promise and std::future.
In the main thread, print the result.
*/

#include <iostream>
#include <thread>
#include <future>

void computeSquare(std::promise<int>&& p, int x) {
    int result = x * x;
    // Set the result in the promise
    p.set_value(result);
}

int main() {
    int number = 5;

    // Create a promise and obtain its future
    std::promise<int> p1;
    std::future<int> f1 = p1.get_future();

    std::thread t1(computeSquare, std::ref(p1), 10); // ref ¶Ç´Â move·Î
    

    // Start a thread and move the promise into it
    
    // Get the result from the future
    int square = f1.get();
        std::cout << "The square of " << number << " is " << square << std::endl;

    t1.join();
    return 0;
}

/*
Problem 4: Compute Factorial with std::async
Task: Use std::async to compute the factorial of a number asynchronously.
In the main thread, get the result and print it.
*/

#include <iostream>
#include <future>

int factorial(int n) {
    int result;

    for (size_t i = n - 1; i > 1; i--)
    {
        result += i * n;
    }
    return result;

    // n <= 1 ? n * factorial(n-1);
}

int main() {
    int number = 5;

    // Launch factorial asynchronously
    std::future<int> f1 = std::async(factorial, 10);

    // Do other work if needed
    std::cout << "Loading..." << std::endl;

    // Get the result from the future
    int result = f1.get();
    std::cout << "Factorial of " << number << " is " << result << std::endl;

    return 0;
}

/*
Problem 5: Use std::promise and std::future for Thread Communication
Task: Create two threads. Each thread should perform a simple calculation (e.g., multiply a number by 2)
and use a std::promise to pass the result back to the main thread.
In the main thread, retrieve the results using the associated std::future objects,
add the results together, and print the total sum..
*/

#include <iostream>
#include <thread>
#include <future>

// First thread function
void computeValue1(std::promise<int>& p) {
    int result = 10 * 2; // Perform a simple calculation
    // Set the result in the promise
    p.set_value(result);
}

// Second thread function
void computeValue2(std::promise<int>& p) {
    int result = 20 * 2; // Perform a simple calculation
    // Set the result in the promise
    p.set_value(result);

}

int main() {
    // Create promises(p1, p2) and futures (f1, f2) 
    std::promise<int> p1, p2;

    std::future<int> f1 = p1.get_future();
    std::future<int> f2 = p2.get_future();

    std::thread t1(computeValue1, std::ref(p1));
    std::thread t2(computeValue2, std::ref(p2));


    // Start threads and pass the promises by reference
    int value1 = f1.get();
    int value2 = f2.get();


    // Retrieve the results from the futures




    // Calculate the total sum
    int total = value1 + value2;

    std::cout << "Total sum: " << total << std::endl;

    // Wait for the threads to finish
    t1.join();
    t2.join();


    return 0;
}

