#include <iostream>
#include <limits>

int main()
{
    std::cout << "Enter some numbers:" << std::endl;
    
    double min = std::numeric_limits<double>::max();
    double max = std::numeric_limits<double>::lowest();
    double d = 0;
    
    while (std::cin >> d) {
        if (d < min) {
            min = d;
        }
        if (d > max) {
            max = d;
        }
    }
    
    std::cout << "Minimum was " << min << '\n';
    std::cout << "Maximum was " << max << '\n';
}