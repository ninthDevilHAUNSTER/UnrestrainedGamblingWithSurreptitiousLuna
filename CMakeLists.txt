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
        "LeetCode/343. 整数拆分.cpp" "LeetCode/279. 完全平方数.cpp" "LeetCode/91. 解码方法.cpp" "LeetCode/62. 不同路径.cpp" "LeetCode/63. 不同路径 II.cpp" LeetCode/198.打家劫舍.cpp "LeetCode/416. 分割等和子集.cpp" "LeetCode/322. 零钱兑换.cpp" "LeetCode/最大连续1的个数 III.cpp" LeetCode/打家劫舍2.cpp LeetCode/2.两数相加.cpp
        # DFS 系列 // 感叹一下 leetcode都不用我在clion 里面调试了
        "LeetCode/1302. 层数最深叶子节点的和.cpp" "LeetCode/1315. 祖父节点值为偶数的节点和.cpp" "LeetCode/336. 寻找二叉树的叶子节点.cpp" "LeetCode/491. 递增子序列.cpp" "LeetCode/339. 嵌套列表权重和.cpp" "LeetCode/364. 加权嵌套序列和 II.cpp")
