/*
 * @Author: sanjayzhong
 * @Github: https://github.com/sanjayzzzhong
 * @Date: 2019-12-07 18:33:28
 */
#include <iostream>
#include <string>
using namespace std;



//############################################//
//################   例子1   ####################//
//############################################//
// Determine if all characters of a string are unique.
// ⼀般来说，⼀旦出现“unique”，就落⼊使⽤hash table或者bitset来判断元素出
// 现与否的范畴
#include <bitset>

bool isUnique(string input){
    bitset<256> hash_map; //可显示字符只有256个
    for(int i = 0; i < input.length(); ++i){
        if(hash_map[(int)input[i]]){
            return false;
        }
        //否则给对应位置标记为1
        hash_map[(int)input[i]] = 1;
    }
    return true;
}

//############################################//
//################   例子2   ####################//
//############################################//
// Given two strings, determine if they are permutations of each other.
// 置换的特性：⽆论如何变化，每个字符出现的次数⼀定相同。 ⼀旦需要统计⼀个
// 元素集中元素出现的次数，我们就应该想到hash table。
// hash table 需要扫描整个string，平均时间复杂度都是O(n)。最后⽐较两个hash
// 是否相同，每个合法字符都有可能出现，假设字符集⼤⼩为m，则需要的时间复
// 杂度是O(m)，故总的时间复杂度O(m+n)。空间上，平均空间是O(m)。
// 解法2:
// 对每个string中的字符按照ASCII编码顺序进⾏排序。如果是⼀个置换，那么排序
// 完的两个string应该相等。这样做的时间复杂度是O(n log n)，空间复杂度是
// O(n)
#include <unordered_map>
namespace example2
{
    bool isPermutation(string stringA, string stringB){
        if(stringA.length() != stringB.length()){
            return false;
        }
        unordered_map<char, int> hashMapA;
        unordered_map<char, int> hashMapB;
        for(int i = 0; i < stringA.length(); ++i){
            hashMapA[stringA[i]]++;
            hashMapB[stringB[i]]++;
        }
        if(hashMapA.size() != hashMapB.size()){
            return false;
        }
        for(auto it = hashMapA.cbegin(); it != hashMapA.cend(); ++it){
            if(it->second != hashMapB[it->first]){
                return false;
            }
        }
        return true;
    }
} // namespace example2


//############################################//
//################   例题3    ####################//
//############################################//
// Given a newspaper and message as two strings, check if the message
// can be composed using letters in the newspaper.
// 解题分析： message中⽤到的字符必须出现在newspaper中。其次， message中
// 任意字符出现的次数⼀定少于其在newspaper中出现的次数。 统计⼀个元素集中
// 元素出现的次数，我们就应该想到hash table
// 复杂度分析：假设message长度为m ， newspaper长度为n，我们的算法需要
// hash整条message和整个newspaper，故时间复杂度O(m+n)。假设字符集⼤⼩
// 为c，则平均空间是O(c)
namespace example3
{
    bool canCompose(string newspaper, string letter){
        //用一个hash map来存储newpaper的值
        unordered_map<char, int> hashMap;

        if(newspaper.length() < letter.length()){
            return false;
        }

        for(int i = 0; i < newspaper.length(); ++i){
            ++hashMap[newspaper[i]];
        }

        //遍历letter, char对应的就--
        for(int i = 0; i < letter.length(); ++i){
            if(hashMap[letter[i]] == 0){
                return false;
            }
            if(--hashMap[letter[i]] < 0){
                return false;
            }
        }
        return true;
    }
} // namespace example3


int main(int argc, char const *argv[])
{
    // string str = "helo";
    // bool result = isUnique(str);
    // cout << result << endl;

    string str1 = "hello";
    string str2 = "lloeh";
    string str3 = "hel";

    // cout << "str1 vs str2 " << example2::isPermutation(str1, str2) << endl;
    // cout << "str1 v2 str3 " << example2::isPermutation(str1, str3) << endl;

    cout << "str1 str2 " << example3::canCompose(str1, str3) << endl; // true 1
    return 0;
}
