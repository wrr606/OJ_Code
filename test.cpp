#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

int main() {
    std::string input;
    std::cout << "�п�J�@�ӼƦr: ";
    
    // �ϥ�getlineŪ������J
    std::getline(std::cin, input);
    
    // �ϥ�stringstream�ӳB�z�r�Ŧ�
    std::stringstream ss;
    ss << " " + input +" "; // �b�Y���K�[�Ů�
    std::string result = ss.str(); // �Nstringstream�ഫ��std::string
    
    std::cout << "��J���Ʀr��: " << result << std::endl;

    return 0;
}
