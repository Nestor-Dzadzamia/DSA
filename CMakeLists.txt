cmake_minimum_required(VERSION 4.0)
project(Codework)

set(CMAKE_CXX_STANDARD 14)

add_executable(Codework
        Algorithms/Algorithms/linear_sieve_algorithm.cpp
        Algorithms/Algorithms/main.cpp
        Algorithms/Algorithms/modified_Eratosthenes_sieve.cpp
        Codeforces/69E.cpp
        Codeforces/Homework.cpp
        Codeforces_Solutions/Codeforces_Solutions/385C.cpp
        Codeforces_Solutions/Codeforces_Solutions/567C.cpp
        Codeforces_Solutions/Codeforces_Solutions/Homework.cpp
        insertion_sort/insertion_sort/main.cpp
        Prefix_sum/Prefix_sum/313B.cpp
        Prefix_sum/Prefix_sum/main.cpp
        Sorting_Algorithms/Sorting_Algorithms/CompSort.cpp
        Sorting_Algorithms/Sorting_Algorithms/main.cpp
        Sorting_Algorithms/Sorting_Algorithms/SelectionSort.cpp
        Stack/Informatics_270.cpp
        Stack/Informatics_171.cpp
        Stack/Informatics_271.cpp
        Stack/320D.cpp
        Fenwick_Tree.cpp
        Codeforces/597C.cpp
        Codeforces/1234D.cpp
        Codeforces/61E.cpp
        Codeforces/140C.cpp
        Codeforces/103B.cpp
        Codeforces/930A.cpp
        Interval_Tree/Interval_tree_Array_implementation.cpp
        Interval_Tree/Interval_tree_Linked_lists.cpp
        LCS/LCS.cpp
        LIS/LIS_Quadratic_time_complexity.cpp
        LIS/LIS_nlogn.cpp
        Graphs/BFS.cpp
        Graphs/DFS.cpp
        MST/Prim.cpp
        MST/Kruskal.cpp
        MST/Topological_Sort.cpp
        Graphs/Djikstra.cpp)
