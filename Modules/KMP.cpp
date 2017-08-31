//
// Created by baislsl on 17-8-31.
//

#include <cstddef>
#include <string>
#include <vector>
#include <iostream>

class KMP {
private:
    /**
     * 计算前缀函数
     * 
     * @param obj 要寻找的字符串
     * @param pre 前缀函数返回的数组地址， 大小为obj.size() + 1,有效下标为1, 2, ...
     */
    static void computePrefix(const std::string &obj, size_t *pre) {
        pre[1] = 0;
        size_t k = 0;
        pre[0] = 0;
        for (auto iter = ++obj.begin(); iter != obj.end(); ++iter) {
            while (k > 0 && obj[k] != *iter)
                k = pre[k];
            if (obj[k] == *iter) k++;
            pre[iter - obj.begin() + 1] = k;
        }

    }

public:
    /**
     * Knuth-Morris-Pratt(KMP) 算法
     * 在字符串src中寻找obj
     *
     * @return {std::vector<size_t>} src在obj中出现的所有位置首个下标
     */
    static std::vector<size_t> find(const std::string &obj, const std::string &src) {
        size_t m = obj.size();
        size_t pre[m + 1];
        std::vector<size_t> result;
        if (obj.empty()) return result;

        computePrefix(obj, pre);

        size_t q = 0;
        for (auto iter = src.begin(); iter != src.end(); ++iter) {
            while (q > 0 && obj[q] != *iter)
                q = pre[q];
            if (obj[q] == *iter) q++;
            if (q == m) {
                result.push_back(iter - src.begin() - obj.size() + 1);
                q = pre[q];
            }
        }

        return result;
    }

};

int main() {
    std::string obj = "abcab";
    std::string src = "asdabcabcababqwe";

    auto gg = KMP::find(obj, src);
    for (const size_t a : gg) {
        std::cout << a << std::endl;
        std::cout << src.substr(a, obj.size()) << std::endl;
    }

}








