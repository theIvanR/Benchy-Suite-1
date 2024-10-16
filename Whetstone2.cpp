#include <iostream>
#include <vector>
#include <cmath>
#include <chrono>
#include <type_traits>

template<typename T>
class WhetstoneBenchmark {
    static_assert(std::is_arithmetic<T>::value, "T must be a numeric type");

public:
    WhetstoneBenchmark(long loop_count) : loop_count(loop_count) {
        E1.resize(5);  // Use 1-based indexing; E1[0] is unused
    }

    void run() {
        auto start_time = std::chrono::high_resolution_clock::now();
        perform_benchmark();
        auto end_time = std::chrono::high_resolution_clock::now();

        std::chrono::duration<double> duration = end_time - start_time;
        double time_seconds = duration.count();

        std::cout << "Duration: " << time_seconds << " sec\n";
        double kips = (100.0 * loop_count) / time_seconds;
        std::cout << "Performance: " << (kips >= 1000.0 ? kips / 1000.0 : kips)
                  << (kips >= 1000.0 ? " MIPS\n" : " KIPS\n");
    }

private:
    long loop_count;
    std::vector<T> E1;
    T T_ = static_cast<T>(0.499975);
    T T1 = static_cast<T>(0.50025);
    T T2 = static_cast<T>(2.0);

    void P0() {
        E1[3] = E1[2];
        E1[2] = E1[1];
        E1[1] = E1[3];
    }

    void perform_benchmark() {
        T X1 = 1.0, X2 = -1.0, X3 = -1.0, X4 = -1.0;
        module1_simple_identifiers(X1, X2, X3, X4);

        E1[1] = 1.0; E1[2] = -1.0; E1[3] = -1.0; E1[4] = -1.0;
        module2_array_elements();

        module3_array_as_parameter();
        module4_conditional_jumps();
        module6_integer_arithmetic();
        module7_trigonometric_functions();
        module8_procedure_calls();
        module9_array_references();
        module10_integer_arithmetic();
        module11_standard_functions();
    }

    void module1_simple_identifiers(T& X1, T& X2, T& X3, T& X4) {
        for (long i = 0; i < loop_count; ++i) {
            X1 = (X1 + X2 + X3 - X4) * T_;
            X2 = (X1 + X2 - X3 + X4) * T_;
            X3 = (X1 - X2 + X3 + X4) * T_;
            X4 = (-X1 + X2 + X3 + X4) * T_;
        }
    }

    void module2_array_elements() {
        for (long i = 0; i < 12 * loop_count; ++i) {
            E1[1] = (E1[1] + E1[2] + E1[3] - E1[4]) * T_;
            E1[2] = (E1[1] + E1[2] - E1[3] + E1[4]) * T_;
            E1[3] = (E1[1] - E1[2] + E1[3] + E1[4]) * T_;
            E1[4] = (-E1[1] + E1[2] + E1[3] + E1[4]) * T_;
        }
    }

    void module3_array_as_parameter() {
        for (long i = 0; i < 14 * loop_count; ++i) {
            PA(E1);
        }
    }

    void PA(std::vector<T>& arr) {
        arr[1] = (arr[1] + arr[2] + arr[3] - arr[4]) * T_;
    }

    void module4_conditional_jumps() {
        int J = 1;
        for (long i = 0; i < 345 * loop_count; ++i) {
            J = (J == 1) ? 2 : 3;
            J = (J > 2) ? 0 : 1;
            J = (J < 1) ? 1 : 0;
        }
    }

    void module6_integer_arithmetic() {
        int J = 1, K = 2, L = 3;
        for (long i = 0; i < 210 * loop_count; ++i) {
            J = J * (K - J) * (L - K);
            K = L * K - (L - J) * K;
            L = (L - K) * (K + J);
            E1[L - 1] = J + K + L;
            E1[K - 1] = J * K * L;
        }
    }

    void module7_trigonometric_functions() {
        T X = 0.5, Y = 0.5;
        for (long i = 0; i < 32 * loop_count; ++i) {
            X = T_ * atan(T2 * sin(X) * cos(X) / (cos(X + Y) + cos(X - Y) - 1.0));
            Y = T_ * atan(T2 * sin(Y) * cos(Y) / (cos(X + Y) + cos(X - Y) - 1.0));
        }
    }

    void module8_procedure_calls() {
        T X = 1.0, Y = 1.0, Z = 1.0;
        for (long i = 0; i < 899 * loop_count; ++i) {
            P3(X, Y, Z);
        }
    }

    void P3(T X, T Y, T& Z) {
        Z = (X + Y) * T_;
    }

    void module9_array_references() {
        int J = 1, K = 2, L = 3;
        E1[1] = 1.0; E1[2] = 2.0; E1[3] = 3.0;
        for (long i = 0; i < 616 * loop_count; ++i) {
            P0();
        }
    }

    void module10_integer_arithmetic() {
        int J = 2, K = 3;
        for (long i = 0; i < loop_count; ++i) {
            J = J + K;
            K = J + K;
            J = K - J;
            K = K - J - J;
        }
    }

    void module11_standard_functions() {
        T X = 0.75;
        for (long i = 0; i < 93 * loop_count; ++i) {
            X = sqrt(exp(log(X) / T1));
        }
    }
};

int main(int argc, char* argv[]) {
    long loop_count = 1E6;  // Default to 1E5 iterations

    // Handle command-line arguments safely
    if (argc > 1) {
        try {
            loop_count = std::stol(argv[1]);
            if (loop_count <= 0) {
                std::cerr << "Error: Loop count must be positive.\n";
                return EXIT_FAILURE;
            }
        } catch (const std::exception& e) {
            std::cerr << "Invalid input: " << e.what() << "\n";
            return EXIT_FAILURE;
        }
    }

    //Call functions
    std::cout << "Running Whetstone Benchmark with int:\n";
    WhetstoneBenchmark<int> int_benchmark(loop_count);
    int_benchmark.run();

    std::cout << "\nRunning Whetstone Benchmark with float:\n";
    WhetstoneBenchmark<float> float_benchmark(loop_count);
    float_benchmark.run();

    std::cout << "\nRunning Whetstone Benchmark with double:\n";
    WhetstoneBenchmark<double> double_benchmark(loop_count);
    double_benchmark.run();

    return 0;
}
