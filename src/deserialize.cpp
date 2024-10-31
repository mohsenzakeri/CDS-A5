#include <sdsl/int_vector.hpp>
#include <sdsl/rank_support.hpp>
#include <vector>
#include <string>

int n = 0;
int r = 0;
int sigma = 0;

// The data structures needed for the assignment
sdsl::bit_vector B_F;
sdsl::bit_vector B_L;
std::vector<int> C;
std::vector<char> H_L;
// std::vector<std::unique_ptr<sdsl::bit_vector> > B_X;
std::vector<sdsl::bit_vector> B_X;

void deserialize_data(char *inputFileName) {
    std::ifstream in_file(inputFileName, std::ios::in | std::ios::binary);

    in_file.read(reinterpret_cast<char*>(&n), sizeof(n));
    in_file.read(reinterpret_cast<char*>(&r), sizeof(r));
    in_file.read(reinterpret_cast<char*>(&sigma), sizeof(sigma));
    std::cerr << "n: " << n << "\n";
    std::cerr << "r: " << r << "\n";
    std::cerr << "sigma: " << sigma << "\n";

    H_L.resize(r);
    in_file.read(reinterpret_cast<char*>(&H_L[0]), r*sizeof(H_L[0]));

    C.resize(sigma);
    in_file.read(reinterpret_cast<char*>(&C[0]), sigma*sizeof(C[0]));

    B_L.resize(n);
    B_L.load(in_file);

    B_F.resize(n);
    B_F.load(in_file);

    for (int i = 0; i < sigma; i++) {
        sdsl::bit_vector new_b_vector;
        new_b_vector.load(in_file);
        B_X.push_back(new_b_vector);
    }

    in_file.close();
}

int main(int argc, char** argv) {

    deserialize_data(argv[1]);
    std::cerr << "All the arrays and bit vectors are loaded.\n\n";

    // For inspecting how the vectors look on a small example
    /* std::cerr << "B_L: " << B_L << "\n";
    std::cerr << "B_F: " << B_F << "\n";
    std::cerr << "H_L: ";
    for (int i = 0; i < r; i++)
        std::cerr << H_L[i];
    std::cerr << "\n";
    for (int i = 0; i < sigma; i++) {
        std::cerr << "B_" << i << ": " << B_X[i] << "\n";
    } */

}