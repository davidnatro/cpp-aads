#ifndef LEETCODE_LEETCODE_75_ARRAY_STRING_HEADERS_REVERSE_VOWELS_OF_A_STRING_H_
#define LEETCODE_LEETCODE_75_ARRAY_STRING_HEADERS_REVERSE_VOWELS_OF_A_STRING_H_

// https://leetcode.com/problems/reverse-vowels-of-a-string/

#include <string>
#include <unordered_set>

class ReverseVowelsOfAString {
public:
    ReverseVowelsOfAString();

    std::string reverseVowels(std::string s);

private:
    bool is_vowel(char letter);

    std::unordered_set<char> vowels_;
};

#endif
