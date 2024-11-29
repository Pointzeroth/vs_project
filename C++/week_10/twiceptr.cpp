#include <iostream>  
#include <string>  

using namespace std;  

bool isCommonSubsequence(const string& pattern, const string& str1, const string& str2) 
{  
    int m = pattern.length();
    int n = str1.length();
    int k = str2.length();  

    // 遍历模式字符串的每个字符  
    for (char p : pattern) {  
        // 定义两个指针  
        int i = 0, j = 0;  
        bool found = false;  

        // 尝试在 str1 或 str2 中找到字符 p  
        while (i < n || j < k) {  
            if (i < n && str1[i] == p) {  
                found = true;  // 在 str1 找到  
                i++;           // 移动指针 i  
                break;        // 找到了，跳出循环  
            }  
            if (j < k && str2[j] == p) {  
                found = true;  // 在 str2 找到  
                j++;           // 移动指针 j  
                break;        // 找到了，跳出循环  
            }  
            // 否则，移动指针  
            if (i < n) i++;  
            if (j < k) j++;  
        }  

        // 如果在两个字符串中都没有找到该字符  
        if (!found) {  
            return false; // 当前字符无法在 str1 或 str2 中找到  
        }  
    }  
    return true;  
}

int main() {  
    string str1 = "abc";  
    string str2 = "ac";  
    string pattern = "ac";  

    bool result = isCommonSubsequence(pattern, str1, str2);  
    cout << "Pattern is common subsequence: " << (result ? "true" : "false") << endl;  

    return 0;  
}