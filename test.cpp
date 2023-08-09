// C++�{���X�A�t�ܨϥ�BIT�i��d���s�M�d��d��
#include <bits/stdc++.h>
using namespace std;

// ��^ arr[0..index] ���`�M�C�Ө�ư��]�}�C�w�g�w�B�z�A�åB�����������`�M�s�x�bBITree[]���C
int getSum(int BITree[], int index)
{
    int sum = 0; // ��l�Ƶ��G

    // �bBITree[]�������ޤ�arr[]�������ޤj1
    index = index + 1;

    // �M��BITree[index]������
    while (index > 0) {
        // �NBITree����e�����K�[���`�M��
        sum += BITree[index];

        // �bgetSum�������A�N���޲��ʨ���`�I
        index -= index & (-index);
    }
    return sum;
}

// ��s�G�i����޾�]BITree�^�����w���޳B���`�I�C
// �N���w�� 'val' �K�[��BITree[i]�Ψ�Ҧ��������C
void updateBIT(int BITree[], int n, int index, int val)
{
    // �bBITree[]�������ޤ�arr[]�������ޤj1
    index = index + 1;

    // �M���Ҧ������òK�[ 'val'
    while (index <= n) {
        // �N 'val' �K�[���eBI��`�I
        BITree[index] += val;

        // �b��s�������A�N���ާ�s�����`�I������
        index += index & (-index);
    }
}

// ��^�q [0, x] ���}�C�`�M
int sum(int x, int BITTree1[], int BITTree2[])
{
    return (getSum(BITTree1, x) * x) - getSum(BITTree2, x);
}

void updateRange(int BITTree1[], int BITTree2[], int n,
                 int val, int l, int r)
{
    // �P�ɧ�s��ӤG�i����޾�
    // �p�峹�ҰQ��

    // ��sBIT1
    updateBIT(BITTree1, n, l, val);
    updateBIT(BITTree1, n, r + 1, -val);

    // ��sBIT2
    updateBIT(BITTree2, n, l, val * (l - 1));
    updateBIT(BITTree2, n, r + 1, -val * r);
}

int rangeSum(int l, int r, int BITTree1[], int BITTree2[])
{
    // �q [0,r] �p���`�M�A�M���h [0,l-1] ���`�M�H�p�� [l,r] ���`�M
    return sum(r, BITTree1, BITTree2) - sum(l - 1, BITTree1, BITTree2);
}

int* constructBITree(int n)
{
    // �Ыبê�l��BITree[]��0
    int* BITree = new int[n + 1];
    for (int i = 1; i <= n; i++)
        BITree[i] = 0;

    return BITree;
}

// �D�{��
int main()
{
    int n = 5;

    // �c�ب��BIT
    int *BITTree1, *BITTree2;

    // BIT1 �Ω�b�}�C�����������޳B������
    BITTree1 = constructBITree(n);

    // BIT2 ���@�ݭn��h���B�~��
    BITTree2 = constructBITree(n);
    updateBIT(BITTree1,n,1,10);
    updateBIT(BITTree2,n,1,10);

    // �N[0,4]�d�򤺪��Ҧ������W�[5
    int l = 1, r = 4, val = 5;
    updateRange(BITTree1, BITTree2, n, val, l, r);

    // �N[2,4]�d�򤺪��Ҧ������W�[10
    l = 1, r = 4, val = 10;
    updateRange(BITTree1, BITTree2, n, val, l, r);

    // �p��[1,4]�d�򤺩Ҧ��������`�M
    l = 3, r = 3;
    cout << "[" << l << "," << r << "] �d�򤺤������`�M�� ";
    cout << rangeSum(l, r, BITTree1, BITTree2) << "\n";

    return 0;
}
