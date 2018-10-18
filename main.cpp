
#include <algorithm>
#include <iostream>
#include <limits>
#include <vector>
#include <numeric>

std::vector<double> read_values()
{
    std::cout << "Enter some numbers:" << std::endl;

    double d;
    std::vector<double> values;

    while (std::cin >> d) {
        values.push_back(d);
    }

    return values;
}


double get_min(const std::vector<double> vec)
{
    // Note: we could use std::min_element() here
    // or std::minmax_element() to get both the min and max in a single pass
    auto min = std::numeric_limits<double>::max();
    for (const auto d : vec) {
        if (d < min) {
            min = d;
        }
    }
    return min;
}

double get_max(const std::vector<double> vec)
{
    auto max = std::numeric_limits<double>::lowest();
    for (const auto d : vec) {
        // The function std::max() returns the larger of its two arguments
        // We could also have used std::min() above
        max = std::max(d, max);
    }
    return max;
}

double get_mean(const std::vector<double> vec)
{
    // We cannot calculate the mean of zero elements
    if (vec.empty()) {
        return 0.0;
    }

    // Note: we could use std::accumulate() to calculate the sum, e.g.
    // const double sum = std::accumulate(vec.begin(), vec.end(), 0.0);

    double sum = 0.0;
    for (const auto d : vec) {
        sum += d;
    }
    return sum/vec.size();
}

double get_median(std::vector<double> vec)
{
    // We cannot calculate the median of zero elements
    if (vec.empty()) {
        return 0.0;
    }

    // There are several ways to do this; this is not the most efficient
    std::sort(vec.begin(), vec.end());

    if (vec.size() % 2 != 0) { // odd number of elements
        const auto middle_idx = vec.size()/2;
        return vec[middle_idx];

    } else {
        const auto middle_idx = vec.size()/2;
        return (vec[middle_idx] + vec[middle_idx - 1])/2.0;
    }
}

int main()
{
    const auto values = read_values();
    
    std::cout << "Minimum was " << get_min(values) << '\n';
    std::cout << "Maximum was " << get_max(values) << '\n';
    std::cout << "Mean was " << get_mean(values) << '\n';
    std::cout << "Median was " << get_median(values) << '\n';
}