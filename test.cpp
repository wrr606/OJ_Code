#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

int main() {
    std::string input;
    std::cout << "請輸入一個數字: ";
    
    // 使用getline讀取整行輸入
    std::getline(std::cin, input);
    
    // 使用stringstream來處理字符串
    std::stringstream ss;
    ss << " " + input +" "; // 在頭尾添加空格
    std::string result = ss.str(); // 將stringstream轉換為std::string
    
    std::cout << "輸入的數字為: " << result << std::endl;

    return 0;
}
