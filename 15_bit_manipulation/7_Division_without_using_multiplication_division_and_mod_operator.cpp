#include <iostream>
#include <climits>
#include <cstdlib>

using namespace std;

class Solution {
public:
    long long divide(long long dividend, long long divisor) {
        if (dividend == 0) return 0;
        int sign = ((dividend < 0) ^ (divisor < 0)) ? -1 : 1;

        unsigned long long dvd = llabs(dividend);
        unsigned long long dvs = llabs(divisor);
        unsigned long long quotient = 0;

        for (int i = 31; i >= 0; i--) {
            if ((dvs << i) <= dvd) {
                dvd -= (dvs << i);
                quotient += (1ULL << i);
            }
        }
        return sign * (long long)quotient;
    }
};

int main() {
    Solution sol;
    cout << "10 / 3 = " << sol.divide(10, 3) << endl;
    cout << "43 / -8 = " << sol.divide(43, -8) << endl;
    return 0;
}
