#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::vector<int> vec = {10, 20, 30, 40, 50};

    int target = 30;
    
    auto lower_it = std::lower_bound(vec.begin(), vec.end(), target);
    auto upper_it = std::upper_bound(vec.begin(), vec.end(), target);

    if (lower_it != vec.end()) {
        std::cout << "lower_bound: " << *lower_it << " at index " << std::distance(vec.begin(), lower_it) << std::endl;
    } else {
        std::cout << "lower_bound not found" << std::endl;
    }

    if (upper_it != vec.end()) {
        std::cout << "upper_bound: " << *upper_it << " at index " << std::distance(vec.begin(), upper_it) << std::endl;
    } else {
        std::cout << "upper_bound not found" << std::endl;
    }

    return 0;
}
