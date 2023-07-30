#include <iostream>
#include <vector>

int main() {
    std::vector<int> myVector = {1, 2, 3, 4, 5};

    try {
        // 正常情况下的使用
        int element = myVector.at(2);
        std::cout << "Element at index 2: " << element << std::endl;

        // 尝试访问越界元素
        int outOfRangeElement = myVector.at(10); // 这里会抛出std::out_of_range异常
    } catch (const std::out_of_range& e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }

    return 0;
}
