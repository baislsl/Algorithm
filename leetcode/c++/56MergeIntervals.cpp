/**
    Given a collection of intervals, merge all overlapping intervals.

    For example,
    Given [1,3],[2,6],[8,10],[15,18],
    return [1,6],[8,10],[15,18].


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

struct one {
    int num;
    bool isS;
};

class Solution {
public:
    vector<Interval> merge(vector<Interval> &intervals) {
        int n = intervals.size(), index = 0;

        sort(intervals.begin(), intervals.end(),
             [](const Interval &a, const Interval &b) -> bool {
                 return a.start < b.start;
             });
        vector<Interval> ret;

        int lastBegin, i = 0;
        int start, end;
        while (i < n) {
            start = intervals[i].start;
            end = intervals[i].end;
            while (i + 1 < n) {
                if (end < intervals[i + 1].start) {
                    break;
                } else {
                    end = std::max(intervals[i + 1].end, end);
                    i++;
                }
            }
            ++i;
            Interval add(start, end);
            ret.push_back(add);
        }
        return ret;

    }
};












