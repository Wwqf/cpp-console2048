#include "Random.hpp"

randomCls::randomCls() {
    e.seed((unsigned)time(0));
}

int randomCls::randomInt(int l, int r) {
    uniform_int_distribution<unsigned> u(l, r);
    return u(e);
}

double randomCls::randomDouble(double l, double r) {
    uniform_real_distribution<double> u(l, r);
    return u(e);
}

int randomCls::randomZeroOneDistribution(double prob) {
    bernoulli_distribution b(prob);
    return b(e) ? 2 : 4;
}