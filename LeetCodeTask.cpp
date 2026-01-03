#include "LeetCodeTask.h"

Vector<int> LeetCodeTask::TwoSum(Vector<int>& nums, int target){
    HashMap<int, int> seen;
    if(nums.empty()) return {};

    for(int i = 0; i < nums.size(); ++i){
        int current = nums[i];
        int complement = target - current;
        if(seen.contains(complement)){
            return{seen[complement], i};
        }
        seen.put(current, i); 
    }
    return {};
}

int LeetCodeTask::firstUniqChar(const String& s){
    HashMap<char, int> countForSymbol;
    for(int i = 0; i < s.length(); ++i){
        countForSymbol[s[i]] += 1;
    }
    for(int i = 0; i < s.length(); ++i){
        if(countForSymbol[s[i]] == 1) return i;
    }
    return -1;
}

void LeetCodeTask::moveZeroes(Vector<int>& nums){
    int pos = 0;
    int size = nums.size();
    
    for(int i = 0; i < size; ++i){
        if(nums[i] != 0){
            MyStd::swap(nums[i], nums[pos]);
            pos++;
        }
    }
}

bool LeetCodeTask::isValid(const String& s){
    Stack<char> st;
    for(const char& a : s){
        if(a == '(' || a == '{' || a == '['){
            st.push(a);
        }
        else{
            if(st.empty()) return false;
            char last = st.top();

            if(a == ')' && last == '(') {
                st.pop(); 
            }
            else if(a == '}' && last == '{') {
                st.pop();
            }
            else if(a == ']' && last == '[') {
                st.pop();
            }
            else {
                return false;
            }
        }
    }
    return st.empty();
}

void LeetCodeTask::FastTestTwoSum(){
    Vector<int> test1 = {2, 7, 11, 15};
    Vector<int> test2 = {1, 1};
    Vector<int> test3 = {1, 2, 3, 4, 5};
    Vector<int> test4 = {1, 4, 9, 3};
    Vector<int> res1, res2, res3, res4;
    res1 = TwoSum(test1, 9);
    res2 = TwoSum(test2, 2);
    res3 = TwoSum(test3, 7);
    res4 = TwoSum(test4, 10);
    std::cout<<"\nPrint result for TwoSum: \n";
    PrintResultForTwoSum(test1, res1, 9);
    PrintResultForTwoSum(test2, res2, 2);
    PrintResultForTwoSum(test3, res3, 7);
    PrintResultForTwoSum(test4, res4, 10);
    countTest = 1;
}

void LeetCodeTask::PrintResultForTwoSum(Vector<int>& test, Vector<int>& res, int target){
    std::cout<<"Result for test " << countTest <<" ( ";
    for(int& i : test){
        std::cout<<i<<" ";
    }
    std::cout<<") target - "<<target<<":\n";
    for(int i = 0; i < res.size(); ++i) {
        std::cout<<res[i]<<" ";
    }
    std::cout<<std::endl;
    countTest++;
}

void LeetCodeTask::FastTestUniqChar(){
    String test1 = "llaaajjdassq";
    String test2 = "koloasdas";
    String test3 = "aaaaaaaaasssssssss";
    String test4 = "lololhtto";

    std::cout<<"\nPrint result for first unique char:\n";
    PrintResultForUniqChar(firstUniqChar(test1), test1);
    PrintResultForUniqChar(firstUniqChar(test2), test2);
    PrintResultForUniqChar(firstUniqChar(test3), test3);
    PrintResultForUniqChar(firstUniqChar(test4), test4);
    countTest = 1;
}

void LeetCodeTask::PrintResultForUniqChar(int res, const String& test){
    std::cout<<"Result for test "<<countTest<<" ("<<test<<"): "<<res<<std::endl;
    countTest++;
}

void LeetCodeTask::FastTestMoveZeroes() {

    Vector<int> nums1 = {0, 1, 0, 3, 12};
    moveZeroes(nums1);
    
    Vector<int> nums2 = {0, 0, 0};
    moveZeroes(nums2);

    Vector<int> nums3 = {1, 2, 3};
    moveZeroes(nums3);
    
    Vector<int> nums4 = {0, 0, 1, 2, 3};
    moveZeroes(nums4);
    
    Vector<int> nums5 = {1, 2, 3, 0, 0};
    moveZeroes(nums5);

    std::cout<<"\nPrint result for move zero:\n";
    PrintResultForMoveZeroes(nums1);
    PrintResultForMoveZeroes(nums2);
    PrintResultForMoveZeroes(nums3);
    PrintResultForMoveZeroes(nums4);
    PrintResultForMoveZeroes(nums5);
    countTest = 1;
}

void LeetCodeTask::PrintResultForMoveZeroes(const Vector<int>& test){
    std::cout<<"Result for test "<<countTest<<":\n";
    for(const int& a : test){
        std::cout<<a<<" ";
    }
    std::cout<<std::endl;
    countTest++;
}

void LeetCodeTask::FastTestIsValid(){
    String str1 = "([])";
    String str2 = "{[}]";
    String str3 = "([)]";
    String str4 = "()[]{}";

    std::cout<<"\nPrint result for is valid:\n";
    PrintResultForIsValid(str1, isValid(str1));\
    PrintResultForIsValid(str2, isValid(str2));
    PrintResultForIsValid(str3, isValid(str3));
    PrintResultForIsValid(str4, isValid(str4));
}

void LeetCodeTask::PrintResultForIsValid(String& str, bool res){
    std::cout<<"Res for str "<<str<<": ";
    if(res) std::cout<<"true\n";
    else std::cout<<"else\n";
}