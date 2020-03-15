cmake_minimum_required(VERSION 3.5)
project(UnrestrainedGamblingWithSurreptitiousLuna)

set(CMAKE_CXX_STANDARD 14)

add_executable(UnrestrainedGamblingWithSurreptitiousLuna
        main.cpp
        AlgNote/AlgNoteMainHeader.h
        PAT/PATMainHeader.h
        GPLT/GPLTMainHeader.h
        #        "LeetCode/120. 三角形最小路径和.cpp"
        "LeetCode/64. 最小路径和.cpp"
        "LeetCode/343. 整数拆分.cpp" "LeetCode/279. 完全平方数.cpp" "LeetCode/91. 解码方法.cpp" "LeetCode/62. 不同路径.cpp" "LeetCode/63. 不同路径 II.cpp" LeetCode/198.打家劫舍.cpp "LeetCode/416. 分割等和子集.cpp" "LeetCode/322. 零钱兑换.cpp")
