# Skyline Problem

Find the skyline given a list of building with left, right and height coordinates. Output only the left points of the edges making up the skyline

[Detailed Problem Description at LeetCode](https://leetcode.com/problems/the-skyline-problem/description/)


## Solution Approach 1 : Time Complexity O(n^2)

For each of the left points of the edges that can potentially make up the skyline, iterate over all the buildings and find out the maximum height for that point.


## Solution Approach 2 : Time Complexity O(nlog(n))

For each of the left points of the edges that can potenitally make up the skyline, find the maximum height building. This can be done by using a maxHeap.
