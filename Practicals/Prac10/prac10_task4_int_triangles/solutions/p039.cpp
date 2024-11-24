#include <iostream>
#include <cmath>
#include <vector>
#include <map>
#include <tuple>

const int MAX_P = 1000;
const int MAX_N = 1000 / 2;

template <typename SOME_VECTOR>
void myPrint(const SOME_VECTOR& vec) {
    for (const auto& myTuple : vec) {
        std::cout << "(" << std::get<0>(myTuple) << ", " 
                    << std::get<1>(myTuple) << ", " 
                    << std::get<2>(myTuple) << "), "
                    << std::get<3>(myTuple) << "), ";
    }
    std::cout << "\n";
}

int main() {
    std::map<int, std::vector<std::tuple<int, int, int, int>>> res;
    int best_len = 1;
    int best_p = -1;

    for (int a = 1; a <= MAX_N; ++a) {
        for (int b = a; b <= MAX_N; ++b) {
            double c = std::sqrt(a * a + b * b);
            // NOTE! May need to do rounding error check for other similar problems!
            int ic = static_cast<int>(c);  // looks like it works ok in c++.
            if (c == ic) { // Check if c is an integer
                // another way: abs(c-ic) < roundingError
                int p = a + b + ic;
                if (p > MAX_P) {
                    continue;
                }
                res[p].push_back(std::make_tuple(a, b, ic, p));

                int new_len = res[p].size();
                if (new_len > best_len) {
                    best_len = new_len;
                    best_p = p;
                    myPrint(res[p]);
                }
            }
        }
    }

    if (best_p != -1) {
        myPrint(res[best_p]);
        std::cout << "Best length: " << best_len << "\n";
    }

    return 0;
}

// (10, 24, 26), 60), (15, 20, 25), 60), 
// (20, 48, 52), 120), (24, 45, 51), 120), (30, 40, 50), 120), 
// (15, 112, 113), 240), (40, 96, 104), 240), (48, 90, 102), 240), (60, 80, 100), 240), 
// (28, 195, 197), 420), (60, 175, 185), 420), (70, 168, 182), 420), (105, 140, 175), 420), (120, 126, 174), 420), 
// (40, 399, 401), 840), (56, 390, 394), 840), (105, 360, 375), 840), (120, 350, 370), 840), (140, 336, 364), 840), (168, 315, 357), 840), 
// (40, 399, 401), 840), (56, 390, 394), 840), (105, 360, 375), 840), (120, 350, 370), 840), (140, 336, 364), 840), (168, 315, 357), 840), (210, 280, 350), 840), 
// (40, 399, 401), 840), (56, 390, 394), 840), (105, 360, 375), 840), (120, 350, 370), 840), (140, 336, 364), 840), (168, 315, 357), 840), (210, 280, 350), 840), (240, 252, 348), 840), 
// (40, 399, 401), 840), (56, 390, 394), 840), (105, 360, 375), 840), (120, 350, 370), 840), (140, 336, 364), 840), (168, 315, 357), 840), (210, 280, 350), 840), (240, 252, 348), 840), 
// Best length: 8