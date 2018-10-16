#include <iostream>
#include <limits>
#include <vector>

double get_min(std::vector<double> vec)
{
    auto min = std::numeric_limits<double>::max();
    for (auto d : vec) {
        if (d < min) {
            min = d;
        }
    }
    return min;
}

double get_max(std::vector<double> vec)
{
    auto max = std::numeric_limits<double>::lowest();
    for (auto d : vec) {
        if (d > max) {
            max = d;
        }
    }
    return max;
}

double get_mean(std::vector<double> vec)
{
    double sum = 0.0;
    for (auto d : vec) {
        sum += d;
    }
    return sum/vec.size();
}

int main()
{
    std::cout << "Enter some numbers:" << std::endl;

    double d;
    std::vector<double> values;

    while (std::cin >> d) {
        values.push_back(d);
    }
    
    std::cout << "Minimum was " << get_min(values) << '\n';
    std::cout << "Maximum was " << get_max(values) << '\n';
    std::cout << "Mean was " << get_mean(values) << '\n';
}