#include <iostream>
#include "MergeIntervals.cpp"

int main() {
    Solution solution;

    std::vector<std::vector<int>> intervals = {
        {1, 3}, {2, 6}, {8, 10}, {15, 18}
    };

    auto result = solution.merge(intervals);

    for (const auto& interval : result) {
        std::cout << "[" << interval[0]
            << ", " << interval[1] << "] ";
    }

    return 0;
}