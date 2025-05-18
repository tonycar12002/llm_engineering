
#include <iostream>
#include <iomanip>
#include <chrono>

double calculate(int iterations, int param1, int param2) {
    double result = 1.0;
    for (int i = 1; i <= iterations; ++i) {
        double j = static_cast<double>(i * param1 - param2);
        result -= (1.0 / j);
        j = static_cast<double>(i * param1 + param2);
        result += (1.0 / j);
    }
    return result;
}

int main() {
    using namespace std::chrono;
    int iterations = 100000000;
    int param1 = 4;
    int param2 = 1;
    
    auto start_time = high_resolution_clock::now();
    double result = calculate(iterations, param1, param2) * 4;
    auto end_time = high_resolution_clock::now();
    
    duration<double> elapsed = end_time - start_time;

    std::cout << std::fixed << std::setprecision(12) << "Result: " << result << std::endl;
    std::cout << "Execution Time: " << elapsed.count() << " seconds" << std::endl;

    return 0;
}
