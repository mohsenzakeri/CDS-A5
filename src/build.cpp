#include <sdsl/int_vector.hpp>

#define LENGTH 100

int main() {
    sdsl::bit_vector bits;
    bits = sdsl::bit_vector(LENGTH, 0);
    std::cerr << "bits: " << bits << "\n";
    bits[10] = 1;
    std::cerr << "bits: " << bits << "\n";
    // sdsl::rank_support_v<> rbits;
}