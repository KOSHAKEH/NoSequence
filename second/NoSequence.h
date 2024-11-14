#pragma once
#include <algorithm>
#include <vector>
using namespace std;


template <typename T>
void print(T* begin, T* end, char delimiter = ' ') {
    while (begin != end) {
        cout << *begin++ << delimiter;
    }
    cout << '\n';
}

template <typename T, typename Predicate>
int copy_if(T* srcB, T* srcE, T* destB, T* destE, Predicate pred) {
    int copyCount = 0;
    while (destB != destE && srcB != srcE) {
        if (pred(*srcB)) {
            *destB++ = *srcB;
            ++copyCount;
        }
        ++srcB;
    }
    return copyCount;
}

class NoSequence
{
private:
    int prevEl;
    int consecutiveCount;
    int ignoreCount;

public:
    NoSequence(int ignoreCount = 1) : consecutiveCount(0), ignoreCount(ignoreCount), prevEl(0) {}

    bool operator()(int el) {
        if (el == prevEl) {
            consecutiveCount++;
            if (consecutiveCount >= ignoreCount) {
                return false;
            }
        }
        else {
            consecutiveCount = 0;
        }
        prevEl = el;
        return true;
    }
};

