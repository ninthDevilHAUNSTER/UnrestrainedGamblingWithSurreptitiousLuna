//
// Created by shaob on 2020/2/29.
//

#include <iostream>
#include <algorithm>
#include <cassert>
#include <cmath>

using namespace std;

class Fraction {
public:
    int up;
    int down;

    Fraction(int _up, int _down) {
        this->up = _up;
        this->down = _down;
        this->simplify();
    }

    void simplify() {
        if (this->down < 0) {
            this->up = -this->up;
            this->down = -this->down;
        }
        if (this->up == 0) {
            this->down = 1; // 分子为0 ，分母为1
        }
        int s = gcd(abs(this->up), abs(this->down));
        this->up /= s;
        this->down /= s;
    }

    friend ostream &operator<<(ostream &output, const Fraction &f) {
        output << f.up << " / " << f.down;
        return output;
    }

private:
    static int gcd(int a, int b) {
        // 一行GCD 辗转欧几里得
        return !b ? a : gcd(b, a % b);
    }

    static int lcm(int a, int b) {
        return a / gcd(a, b) * b;
    }
};

int gcd(int a, int b) {
    // 一行GCD 辗转欧几里得
    return !b ? a : gcd(b, a % b);
}

int lcm(int a, int b) {
    return a / gcd(a, b) * b;
}


bool isPrime(int n) {
    /// 判断负数，即在 2,sqrt(N) 中是否存在因数
    assert(n > 0);
    if (n <= 1)return false;
    int sq = int(sqrt(1.0 * n));
    for (int i = 2; i < sq; ++i) {
        if (n % i == 0)return false;
    }
    return true;
}

void makePrimeTable(vector<int> &array, int size = 1) {
    assert(size < 100000);
    bool flag[100000] = {false};
    for (int i = 2; i < size; ++i) {
        if (!flag[i]) {
            array.push_back(i);
            for (int j = 0; j < size; j += i) {
                flag[j] = true;
            }
        }
    }
}


int alg_solver() {

    cout << "最最大公因数" << endl;
    cout << gcd(49, 14) << endl;
    cout << "最小公倍数" << endl;
    cout << lcm(49, 14) << endl;
    cout << "分数表达法" << endl;
    Fraction f(312, 122);
    cout << f << endl;
    cout << "素数相关" << endl;
    cout << isPrime(17) << endl;
    cout << isPrime(28) << endl;
    vector<int> p;
    makePrimeTable(p, 100);
    for (auto a:p) {
        cout << a << " ";
    }
    cout << endl;
    cout << "因式分解" << endl;
}
