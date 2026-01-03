#include "LeetCodeTask.h"

using namespace std;

int main() {
    //Можно быстро затестить, как в примере ниже или протестить вручную:
    //cout<<task.firstUniqChar("asdass");
    try{
    LeetCodeTask task;
    task.FastTestTwoSum();
    task.FastTestUniqChar();
    task.FastTestMoveZeroes();
    task.FastTestIsValid();
    }
    catch(const std::exception& e){
        std::cout<<"Error: "<<e.what()<<std::endl;
        return 1;
    }
    return 0;
}