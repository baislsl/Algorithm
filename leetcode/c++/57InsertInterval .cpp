/**
Given a set of non-overlapping intervals, insert a new interval into the intervals (merge if necessary).

You may assume that the intervals were initially sorted according to their start times.

Example 1:
Given intervals [1,3],[6,9], insert and merge [2,5] in as [1,5],[6,9].

Example 2:
Given [1,2],[3,5],[6,7],[8,10],[12,16], insert and merge [4,9] in as [1,2],[3,10],[12,16].

This is because the new interval [4,9] overlaps with [3,5],[6,7],[8,10].
 */

/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */


#include <bits/stdc++.h>

using namespace std;

struct Interval {
    int start;
    int end;

    Interval() : start(0), end(0) {}

    Interval(int s, int e) : start(s), end(e) {}
};

class Solution {
public:
    vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) {
        vector<Interval> ret;

        int n = intervals.size(), i = 0, start = newInterval.start, end = newInterval.end;
        while (i < n) {
            if (newInterval.start <= intervals[i].end) {
                start = std::min(intervals[i].start, newInterval.start);
                break;
            } else {
                ret.push_back(intervals[i]);
                ++i;
            }
        }
        while (i < n) {
            if (end < intervals[i].start) {
                ret.push_back(Interval(start, end));
                break;
            } else {
                end = std::max(end, intervals[i].end);
                ++i;
            }
        }
        if (i == n) {
            ret.push_back(Interval(start, end));
        }

        while (i < n) {
            ret.push_back(intervals[i]);
            ++i;
        }

        return ret;

    }
};
