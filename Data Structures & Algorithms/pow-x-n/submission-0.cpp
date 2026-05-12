class Solution {
public:

    double myPow(double x, int n) {

        long long nn = n;

        if (nn < 0) {
            x = 1 / x;
            nn = -nn;
        }

        double res = 1;

        while (nn > 0) {

            if (nn % 2 == 1) {
                res *= x;
            }

            x *= x;

            nn /= 2;
        }

        return res;
    }
};