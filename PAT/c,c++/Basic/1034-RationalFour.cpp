/*
* Basic-1034 Rational Four
* 公因数、公倍数
* 先得出结果，再考虑输出格式
* 遇到问题：
* 测试点 2 不过：通过输入时立即约分化简解决
* 测试点 3 不过：两个输入数都是非常大的质数的情况
* 需要降低找最大公因数的时间复杂度：使用欧几里得算法
*/
#include <iostream>
#include <cmath>

using namespace std;

typedef long long LL;
typedef struct RA{
        LL num;
        LL den;
}Ra;

LL maxComFac(LL a, LL b);
LL minComMul(LL a, LL b);
void display(LL num, LL den);
void display(Ra a, Ra b, char op);
void kill(Ra &deci);

int main(void)
{
        Ra a, b;
        scanf("%lld/%lld %lld/%lld", &a.num, &a.den, &b.num, &b.den);
        kill(a); kill(b);

        LL comDen = minComMul(a.den, b.den);

        display(a, b, '+');
        LL addRe = (a.num * (comDen/a.den)) + (b.num * (comDen/b.den));
        display(addRe, comDen);
        cout << endl;

        display(a, b, '-');
        LL subRe = (a.num * (comDen/a.den)) - (b.num * (comDen/b.den));
        display(subRe, comDen);
        cout << endl;

        display(a, b, '*');
        Ra mulRe;
        if(a.num == 0 || b.num == 0) mulRe.num = 0;
        else {
                mulRe.den = a.den * b.den;
                mulRe.num = a.num * b.num;
        }
        display(mulRe.num, mulRe.den);
        cout << endl;

        display(a, b, '/');
        Ra divRe;
        if(a.num == 0) divRe.num = 0;
        else if(b.num == 0) cout << "Inf";
        else {
                divRe.den = a.den * b.num;
                divRe.num = a.num * b.den;
                if(divRe.den < 0 && divRe.num < 0) {
                        divRe.num = -divRe.num;
                        divRe.den = -divRe.den;
                }
                if(divRe.den < 0) {
                        divRe.den = -divRe.den;
                        divRe.num = -divRe.num;
                }
                display(divRe.num, divRe.den);
        }
        return 0;
}

LL maxComFac(LL a, LL b)
{
        if(a < 0) a = -a;
        if(b < 0) b = -b;
        return b == 0 ? a : maxComFac(b, a%b);
}

LL minComMul(LL a, LL b)
{
        return a * b / maxComFac(a, b);
}

void display(LL num, LL den)
{
        if(num == 0) {
                cout << 0;
                return ;
        }
        if(num < 0) {
                cout << "(-";
        }
        LL temp;
        bool flag = 0;
        if((temp = abs(num / den)) > 0) {
                flag = 1;
                cout << temp;
        }
        if((temp = abs(num) - temp * den)) {
                LL comFac = maxComFac(temp, den);
                if(flag) cout << ' ';
                cout << temp/comFac << '/' << den/comFac;
        }
        if(num < 0) cout << ')';
}

void display(Ra a, Ra b, char op)
{
        display(a.num, a.den);
        cout <<' '<< op <<' ';
        display(b.num, b.den);
        cout << " = ";
}

void kill(Ra &deci)
{
        if(deci.num == 0) return ;
        LL comFac = maxComFac(deci.num, deci.den);
        deci.num /= comFac;
        deci.den /= comFac;
}
