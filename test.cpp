#include <iostream>
#include <cstring>

int main() {
    int myArray[10];
    std::memset(myArray, -1, sizeof(myArray)); // 使用memset将所有元素初始化为1

    for (int i = 0; i < 10; i++) {
        std::cout << myArray[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}
