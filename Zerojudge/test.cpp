#include <iostream>
#include <vector>

int main() {
    std::vector<int> vec;

    // 使用范围赋值
    std::vector<int> source = {1, 2, 3, 4, 5};
    vec.assign(source.begin(), source.end());

    // 输出赋值后的 vector
    for (int num : vec) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    // 使用计数和值赋值
    vec.assign(5, 10);

    // 输出赋值后的 vector
    for (int num : vec) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}
