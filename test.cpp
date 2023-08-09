// C++程式碼，演示使用BIT進行範圍更新和範圍查詢
#include <bits/stdc++.h>
using namespace std;

// 返回 arr[0..index] 的總和。該函數假設陣列已經預處理，並且部分元素的總和存儲在BITree[]中。
int getSum(int BITree[], int index)
{
    int sum = 0; // 初始化結果

    // 在BITree[]中的索引比arr[]中的索引大1
    index = index + 1;

    // 遍歷BITree[index]的祖先
    while (index > 0) {
        // 將BITree的當前元素添加到總和中
        sum += BITree[index];

        // 在getSum視角中，將索引移動到父節點
        index -= index & (-index);
    }
    return sum;
}

// 更新二進制索引樹（BITree）中給定索引處的節點。
// 將給定值 'val' 添加到BITree[i]及其所有祖先中。
void updateBIT(int BITree[], int n, int index, int val)
{
    // 在BITree[]中的索引比arr[]中的索引大1
    index = index + 1;

    // 遍歷所有祖先並添加 'val'
    while (index <= n) {
        // 將 'val' 添加到當前BI樹節點
        BITree[index] += val;

        // 在更新視角中，將索引更新為父節點的索引
        index += index & (-index);
    }
}

// 返回從 [0, x] 的陣列總和
int sum(int x, int BITTree1[], int BITTree2[])
{
    return (getSum(BITTree1, x) * x) - getSum(BITTree2, x);
}

void updateRange(int BITTree1[], int BITTree2[], int n,
                 int val, int l, int r)
{
    // 同時更新兩個二進制索引樹
    // 如文章所討論

    // 更新BIT1
    updateBIT(BITTree1, n, l, val);
    updateBIT(BITTree1, n, r + 1, -val);

    // 更新BIT2
    updateBIT(BITTree2, n, l, val * (l - 1));
    updateBIT(BITTree2, n, r + 1, -val * r);
}

int rangeSum(int l, int r, int BITTree1[], int BITTree2[])
{
    // 從 [0,r] 計算總和，然後減去 [0,l-1] 的總和以計算 [l,r] 的總和
    return sum(r, BITTree1, BITTree2) - sum(l - 1, BITTree1, BITTree2);
}

int* constructBITree(int n)
{
    // 創建並初始化BITree[]為0
    int* BITree = new int[n + 1];
    for (int i = 1; i <= n; i++)
        BITree[i] = 0;

    return BITree;
}

// 主程式
int main()
{
    int n = 5;

    // 構建兩個BIT
    int *BITTree1, *BITTree2;

    // BIT1 用於在陣列中獲取任何索引處的元素
    BITTree1 = constructBITree(n);

    // BIT2 維護需要減去的額外項
    BITTree2 = constructBITree(n);
    updateBIT(BITTree1,n,1,10);
    updateBIT(BITTree2,n,1,10);

    // 將[0,4]範圍內的所有元素增加5
    int l = 1, r = 4, val = 5;
    updateRange(BITTree1, BITTree2, n, val, l, r);

    // 將[2,4]範圍內的所有元素增加10
    l = 1, r = 4, val = 10;
    updateRange(BITTree1, BITTree2, n, val, l, r);

    // 計算[1,4]範圍內所有元素的總和
    l = 3, r = 3;
    cout << "[" << l << "," << r << "] 範圍內元素的總和為 ";
    cout << rangeSum(l, r, BITTree1, BITTree2) << "\n";

    return 0;
}
