
#include <algorithm>
#include <iostream>
#include <limits>
#include <vector>
#include <unordered_map>
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

std::vector<double> get_mode(const std::vector<double> vec)
{
    if (vec.empty()) {
        return vec; // Return the empty vector
    }

    // This is a hash table mapping doubles->ints
    // It records the number of times we have seen each element
    std::unordered_map<double, int> freqs{};

    // For each entry in the vector, record the frequency
    for (const auto d : vec) {
        freqs[d]++;
    }

    // Next, find the maximum frequency
    int max_freq = 0;

    // Note that when we iterate over a map, the element type is a
    // key-value pair: we are interested in the values, i.e the second
    // element of the pair
    for (const auto& p : freqs) {
        max_freq = std::max(max_freq, p.second);
    }

    // Finally, for every element of the map with *value* equal to
    // max_freq, copy its *key* into a new output vector
    std::vector<double> output{};

    for (const auto& p : freqs) {
        if (p.second == max_freq) {
            output.push_back(p.first);
        }
    }

    return output;
}

int main()
{
    const auto values = read_values();
    
    std::cout << "Minimum was " << get_min(values) << '\n';
    std::cout << "Maximum was " << get_max(values) << '\n';
    std::cout << "Mean was " << get_mean(values) << '\n';
    std::cout << "Median was " << get_median(values) << '\n';

    const auto modes = get_mode(values);
    if (modes.size() == 1) {
        std::cout << "Mode was " << modes[0] << '\n';
    } else {
        std::cout << "Modal values were: ";
        for (const auto m : modes) {
            std::cout << m << ' ';
        }
        std::cout << '\n';
    }
}