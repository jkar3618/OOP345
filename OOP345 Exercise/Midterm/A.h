// A.h
#ifndef A_H
#define A_H

struct A {
public:
    double m_val;
public:
    A operator+=(const A& other) {
        this->m_val += other.m_val;
        return *this;
    }
    double getValue() const { return m_val; }
};

// A().getValue() -> ??? double operator+=(....)
decltype(A().getValue()) operator+=(double& val, const A& other);

// #3 compile 
// templates don't support the use of non integral types for its params
// Fix: Remove bc not used in body of func, use an integral type instead of double
template <typename T, double N>
T process(const T* data) {
    T sum{};
    // #2 Compile, it doesn't support the use of range based for loops
    // on point types
    // Fix: Just use a regular idx based for loop
    for (const auto& elem : data) 
        sum += elem;
    return sum;
}
#endif
