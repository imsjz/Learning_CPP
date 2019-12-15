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

#include <algorithm>
namespace example4
{
    //############################################//
    //################   例子4   ####################//
    //############################################//
    // Anagram
    // Write a method anagram(s,t) to decide if two strings are anagrams or
    // not.
    // Example
    // Given s="abcd", t="dcab", return true.
    // Challenge
    // O(n) time, O(1) extra space 
    
    bool anagram_1(string s, string t){
        //s: source
        //t: target
        if(s.empty() || t.empty()){
            return false;
        }
        if(s.size() != t.size()){
            return false;
        }
        int letter_count[256] = {0};
        for(int i = 0; i < s.size(); ++i){
            ++letter_count[s[i]];
            --letter_count[t[i]];
        }
        for(int i = 0; i < s.size(); ++i){
            if(letter_count[i] < 0){
                return false;
            }
        }
        return true;

    }
    bool anagram_2(string s, string t){
        if(s.empty() || s.empty()){
            return false; //如果两个都为空默认为false
        }
        if(s.size() != t.size()){
            return false;
        }
        sort(s.begin(), s.end());
        sort(t.begin(), t.end()); //就地操作, 空间复杂度O(1)
        if(s == t){
            return true;
        }
        else{
            return false;
        }
    }
} // namespace example4

#include <vector>
// Find a pair of two elements in an array, whose sum is a given target
// number.
// 最直观的⽅法是再次扫描数组，判断target – array[i]是否存在在数组中。
// 这样做的时间复杂度是O(n^2)
// 如何保存之前的处理结果？可以使⽤hash table “target – array[i]是否存
// 在在数组中
// 复杂度分析：数组中的每个元素进⾏上述hash处理，从头⾄尾扫描数组，判断对
// 应的另⼀个数是否存在在数组中，时间复杂度O(n )
namespace example5
{
    vector<int> addsToTarget(vector<int>& numbers, int target){
        unordered_map<int, int> num_to_index; //first 存数字, second存下标
        vector<int> vi(2);
        for(vector<int>::const_iterator it = numbers.cbegin(); it != numbers.cend(); ++it){
            if(num_to_index.count(target - *it)){
                vi.at(0) = num_to_index[target - *it] + 1; //位置
                vi.at(1) = (int)(it - numbers.cbegin()) + 1;
            }
            num_to_index[*it] = (int)(it - numbers.cbegin());
        }
        return vi;
    }
} // namespace example5

#include <cstring>
namespace example6
{
    //############################################//
    //################   例子6   ####################//
    //############################################//
    //     Reverse Words in String
    // Given input -> "I have 36 books, 40 pens2."; output -> "I evah 36
    // skoob, 40 2snep.”
    // 解题分析：
    // 每个以空格或符号为间隔的单词逆向输出，如果遇到纯数字，则不改变顺序。⾃
    // 然⽽然地，每次处理分为两个步骤： 1)判断是否需要逆向 2)逆向当前单词。这样
    // 就可以分为两个⼦函数：⼀个负责判断，另⼀个负责逆向。然后进⾏分段处理。
    bool isPunctuationOrSpace(char* charactor){
        if(*charactor == ' ' || *charactor == ',' || *charactor == '.'){
            return true;
        }
    }
    bool isNumber(char *charactor){
        if(*charactor >= '0' && *charactor <= '9'){
            return true;
        }
    }

    bool needReverse(char* sentence, int* offset){
        int length = (int)strlen(sentence);
        bool reverse_flag = false;
        *offset = 0;
        //当不是标号和空格, 且偏移小于句子长度时
        while(!isPunctuationOrSpace(sentence + (*offset)) && (*offset) < length){
            //并且不是数字的时候
            if(!isNumber(sentence + (*offset))){
                reverse_flag = true; //把这个标志设为true
            }
            //继续偏移
            (*offset)++;
        }
        return reverse_flag;
    }

    void reverseWord(char* word, int length){
        int i = 0, j = length - 1; //下标从0开始, 所以length需要-1
        while(i < j){
            swap(*(word + i), *(word + j)); //引用交换
            ++i;
            --j;
        }
    }

    char* reverseSentence(char* sentence){
        int length = (int)strlen(sentence);
        int offset;
        for(int i = 0; i < length; ){
            //传入指针
            if(needReverse(sentence + i, &offset)){
                reverseWord(sentence + i, offset);
            }
            i += (offset + 1);
        }
        return sentence;
    }
} // namespace example6

namespace example7
{
    //############################################//
    //################   例子7   ####################//
    //############################################//
    // Rotate String
    // Given a string and an offset, rotate string by offset. (rotate from left to
    // right)
    // Example
    // Given "abcdefg"
    // for offset=0, return "abcdefg"
    // for offset=1, return "gabcdef"
    // 考虑offset大于原先字符串大小的情况：取模
    // 通过分三次逆序，置换前后
    class Solution{
    public:
        string rotateString(string A, int offset){
            if(A.empty() || offset == 0){
                return A;
            }
            int len = A.size();
            //考虑offset可能会大于len，于是取模
            offset %= len;
            my_reverse(A, 0, len - offset - 1);
            my_reverse(A, len - offset, len - 1);
            my_reverse(A, 0, len - 1);
            return A;
        }
    private:
        void my_reverse(string& str, int start, int end){
            while(start < end){
                char temp = str.at(start);
                str.at(start) = str.at(end);
                str.at(end) = temp;
                ++start;
                --end;
            }
        }
    };
    
} // namespace example7





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

    // cout << "str1 str2 " << example3::canCompose(str1, str3) << endl; // true 1
    // time_t start = time(nullptr);
    // cout << example4::anagram_2(str1, str2) << endl;
    // time_t end = time(nullptr);
    // cout << example4::anagram_1("", "") << endl; //0

    // vector<int> array{1,3,7,3,4,5,6};
    // vector<int> result = example5::addsToTarget(array, 10);
    // for(auto e: result){
    //     cout << e << endl;
    // }
    // char str[] = "I have 36 books, 40 pens2."; //用数组,可以修改, 不要用指针指向字符串, 改不动
    // example6::reverseSentence(str);
    // cout << str << endl;
    string str = "i have a pencil";
    example7::Solution* sln = new example7::Solution;
    string offset_str = sln->rotateString(str, 6);
    cout << offset_str << endl;
    

    return 0;
}
