#ifndef LEETCODETASK_H
#define LEETCODETASK_H

#include "HashMap.h"
#include "String.h"
#include "Stack.h"

class LeetCodeTask{
private:
    int countTest = 1;
    void PrintResultForTwoSum(Vector<int>& test,Vector<int>& res, int target);
    void PrintResultForUniqChar(int res, const String& test);
    void PrintResultForMoveZeroes(const Vector<int>& test);
    void PrintResultForIsValid(String& str, bool res);
public:
    Vector<int> TwoSum(Vector<int>& nums, int target);
    int firstUniqChar(const String& s);
    void moveZeroes(Vector<int>& nums);
    bool isValid(const String& s);

    void FastTestTwoSum();
    void FastTestUniqChar();
    void FastTestMoveZeroes();
    void FastTestIsValid();
};

#endif 