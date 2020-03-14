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
        "LeetCode/343. 整数拆分.cpp")
