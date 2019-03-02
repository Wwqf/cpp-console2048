#ifndef RANDOM_HPP
#define RANDOM_HPP
    
    #include <random>
    using std::default_random_engine;
    using std::uniform_int_distribution;
    using std::uniform_real_distribution;
    using std::bernoulli_distribution;

    class randomCls {
        public: 
            randomCls();
            // 生成[l, r)中的随机整数
            int randomInt(int l, int r);
            // 生成[l, r)中的随机浮点数
            double randomDouble(double l, double r);
            // 生成[0, 1]分布随机数
            int randomZeroOneDistribution(double prob = 0.5);
        private:
            default_random_engine e;
    };


#endif