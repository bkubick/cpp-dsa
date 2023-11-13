#include <iostream>
#include <numeric>

#include "math.hpp"


int leastCommonMultiple(std::vector<int> vals)
{
    if (vals.size() < 2) {
        throw std::invalid_argument("At least two values are required.");
    };

    int mult = std::lcm(vals[0], vals[1]);

    for (int i = 2; i < vals.size(); i++) mult = std::lcm(vals[i], mult);

    return mult;
}


int main()
{
    // Test least common multiple
    std::vector<int> vals = { 2, 4, 6, 8, 10 };
    int lcm = leastCommonMultiple(vals);
    assert (lcm == 120);

    // Test invalid argument
    std::vector<int> vals = { 2 };
    try {
        int lcm = leastCommonMultiple(vals);
    } catch (std::invalid_argument& e) {
        assert (std::string(e.what()) == "At least two values are required.");
    }

    return 0;
}
