//
// Created by shaob on 2020/2/29.
//

#include <iostream>
#include <algorithm>

using namespace std;
typedef long long LL;

class Fraction {
public:
    LL up;
    LL down;

    Fraction(int _up, int _down) {
        this->up = _up;
        this->down = _down;
    }

    Fraction() {
        this->up = 0;
        this->down = 1;
    }

    void Simplify() {
        // 暂时不考虑特殊情况
        if (this->up == 0) {
            this->down = 1;
        }
        if (this->down < 0) {
            this->up = -this->up;
            this->down = -this->down;
        }
        LL p = gcd(abs(this->up), abs(this->down));
        this->up /= p;
        this->down /= p;
    }

    friend Fraction operator+(const Fraction &f1, const Fraction &f2) {
        Fraction f3;
        f3.down = f1.down * f2.down;
        f3.up = f1.up * f2.down + f2.up * f1.down;
        f3.Simplify();
        return f3;
    }

    friend ostream &operator<<(ostream &output, const Fraction &f) {
        LL z = f.up / f.down;
        if (f.down == 1) {
            output << f.up;
        } else if (z == 0) {
            output << f.up << "/" << f.down;
        } else {
            output << z << " " << abs(f.up) - abs(z) * f.down << "/" << f.down;
        }
        return output;
    }

private:
    static LL gcd(LL a, LL b) {
        return (b == 0) ? a : gcd(b, a % b);
    }
};

int pat_solver() {
    int N = 0;
    scanf("%d", &N);
    LL _, __;
    Fraction f3;
    for (int i = 0; i < N; ++i) {
        scanf("%lld/%lld", &_, &__);
        Fraction f1(_, __);
        f3 = f1 + f3;
    }
    cout << f3;
    return 0;
}