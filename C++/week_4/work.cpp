#include <iostream>
#include <vector>

void rearrangeOddEven(std::vector<int>& A) {
    int left = 0;
    int right = A.size() - 1;

    while (left < right) {
        // 找到左边的偶数
        while (A[left] % 2 == 1 && left < right) {
            left++;
        }
        // 找到右边的奇数
        while (A[right] % 2 == 0 && left < right) {
            right--;
        }
        // 交换
        if (left < right) {
            std::swap(A[left], A[right]);
        }
    }
}

int main() {
    std::vector<int> A = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    
    rearrangeOddEven(A);

    std::cout << "Rearranged array: ";
    for (int num : A) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}