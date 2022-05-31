// PracticeBacktracking.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include "PracticeBacktracking.h"

#include <algorithm>
#include <iostream>
#include <vector>
#include <LeetCodeUtil.h>

using namespace std;

//---------------------------------------------------------------------------------------
// 39. Combination Sum
//---------------------------------------------------------------------------------------
void combinationSumHelper(vector<int>& candidates, int target, int start, vector<int>& tempResult, vector<vector<int>>& result)
{
    if (target == 0)
    {
        result.push_back(tempResult);
        return;
    }

    for (int i = start; i < candidates.size(); ++i)
    {
        const int candidate = candidates[i];
        if (candidate > target)
        {
            break;
        }
        else
        {
            tempResult.push_back(candidate);
            combinationSumHelper(candidates, target - candidate, i, tempResult, result);
            tempResult.pop_back();
        }
    }
}

vector<vector<int>> combinationSum(vector<int>& candidates, int target)
{
    vector<vector<int>> result;
    sort(candidates.begin(), candidates.end());

    for (int i = 0; i < candidates.size(); ++i)
    {
        const int candidate = candidates[i];
        if (candidate > target)
        {
            break;
        }
        else if (candidate == target)
        {
            result.push_back({ candidate });
            break;
        }
        else
        {
            vector<int> tempResult(1, candidate);
            combinationSumHelper(candidates, target - candidate, i, tempResult, result);
        }
    }

    return result;
}


int main()
{
    using namespace Backtracking;

    std::cout << "Practice of backtracking!\n";

    TestNQueens();

    // 39. Combination Sum
    // Input: candidates = [2,3,6,7], target = 7
    // Output: [[2, 2, 3], [7]]
    vector<int> candidates;
    LeetCodeUtil::BuildIntVectorFromString("[2,3,6,7]", &candidates);

    cout << "\nResult of Combination Sum:" << endl;
    auto resultVVI = combinationSum(candidates, 7);
    LeetCodeUtil::PrintMatrix(resultVVI);

    cout << endl;
}
