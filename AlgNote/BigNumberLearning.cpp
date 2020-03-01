//
// Created by shaob on 2020/2/29.
//
#include <iostream>
#include <cstring>
#include <algorithm>
#include <cassert>

using namespace std;
static int MAX_SIZE = 1000;

class BigNumber {
public:
    int num[100]{};
    int len;
    bool positive = true;

    BigNumber() {
        fill(this->num, this->num + 100, 0);
        this->len = 0;
    }

    explicit BigNumber(char a[]) { // explicit 关键字，禁止对象间的隐式转换，常用于构造函数上！
        if (a[0] == '-') {
            this->len = int(strlen(a)) - 1;
            this->positive = false;
            for (int i = 1; i < this->len; i++) {
                this->num[i] = a[this->len - i - 1] - '0'; // 实际上是倒过来的
            }
        } else {
            this->len = strlen(a);
            for (int i = 0; i < this->len; i++) {
                this->num[i] = a[this->len - i - 1] - '0'; // 实际上是倒过来的
            }
        }
    }

    friend bool operator>(BigNumber &a, BigNumber &b) {
        if (a.len != b.len) {
            return a.len > b.len;
        } else {
            for (int i = a.len - 1; i > 0; ++i) {
                if (a.num[i] != b.num[i]) return a.num[i] > b.num[i];
            }
            return a.num[0] > b.num[0];
        }
    }

    friend BigNumber operator+(BigNumber &a, BigNumber &b) {
        assert(a.positive == b.positive);
        BigNumber c;
        int carry = 0;
        for (int i = 0; i < a.len || i < b.len; ++i) {
            c.num[i] = a.num[i] + b.num[i] + carry;
            carry = c.num[i] / 10;
            c.num[i] %= 10;
            c.len++;
        }
        if (carry != 0) {
            c.num[c.len++] = carry;
        }
        return c;
    }

    friend ostream &operator<<(ostream &output, const BigNumber &b) {
        for (int i = b.len - 1; i >= 0; --i) {
            output << b.num[i];
        }
    }

    friend BigNumber operator-(BigNumber a, const BigNumber &b) {
        assert(a.positive == b.positive);
        BigNumber c;
        for (int i = 0; i < a.len || i < b.len; ++i) {
            if (a.num[i] < b.num[i]) {
                /// 不够减的话
                a.num[i + 1]--;
                a.num[i] += 10;
            }
            c.num[c.len++] = a.num[i] - b.num[i];
        }
        while (c.len - 1 >= 1 && c.num[c.len - 1] == 0) c.len--;
        return c;
    }

    friend BigNumber operator*(const BigNumber &a, int b) {
//        assert(a.positive == b.positive);
        BigNumber c;
        int carry = 0;
        for (int i = 0; i < a.len; ++i) {
            int tmp = a.num[i] * b + carry;
            c.num[c.len++] = tmp % 10;
            carry = tmp / 10;
        }
        while (carry != 0) {
            c.num[c.len++] = carry % 10;
            carry /= 10;
        }
        return c;
    }

    friend BigNumber operator/(const BigNumber &a, int b) {
        assert(b > 0);
        BigNumber c;
        c.len = a.len;
        int rest = 0;
        for (int i = a.len - 1; i >= 0; --i) {
            rest = rest * 10 + a.num[i];
            if (rest < b) {
                c.num[i] = 0;
            } else {
                c.num[i] = rest / b;
                rest %= b;
            }
        }
        while (c.len - 1 >= 1 && c.num[c.len - 1] == 0) c.len--; // 规格化
        return c;
    }

    friend int operator%(const BigNumber &a, int b) {
        int rest = 0;
        for (int i = a.len - 1; i >= 0; --i) {
            rest = rest * 10 + a.num[i];
            if (rest >= b)
                rest %= b;
        }
        return rest;
//        while (c.len >= 0 && c.num[c.len - 1] == 0) c.len--;
    }

};

int alg_solver() {
    BigNumber A("10004536");
    BigNumber B("4567890");
    long long a = 10004536;
    long long b = 4567890;
    cout << "[LL]" << a << " + " << b << " = " << a + b << endl;
    cout << "[BN]" << A << " + " << B << " = " << A + B << endl;

    cout << "[LL]" << a << " - " << b << " = " << a - b << endl;
    cout << "[BN]" << A << " - " << B << " = " << A - B << endl;

    cout << "[LL]" << a << " * " << b << " = " << a * b << endl;
    cout << "[BN]" << A << " * " << B << " = " << A * b << endl;

    cout << "[LL]" << a << " / " << b << " = " << a / b << endl;
    cout << "[BN]" << A << " / " << B << " = " << A / b << endl;

    cout << "[LL]" << a << " % " << b << " = " << a % b << endl;
    cout << "[BN]" << A << " % " << B << " = " << A % b << endl;

    return 0;
}
