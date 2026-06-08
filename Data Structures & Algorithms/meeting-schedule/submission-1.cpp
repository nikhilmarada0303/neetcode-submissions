/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    static bool comp(const Interval& a, const Interval& b) {
        return a.start < b.start;
    }

    bool canAttendMeetings(vector<Interval>& intervals) {
        // if (intervals.size() <= 1) return true;

        sort(intervals.begin(), intervals.end(), comp);

        int last = intervals[0].end;

        for (int i = 1; i < intervals.size(); i++) {
            if (intervals[i].start >= last) {
                last = intervals[i].end;
            } else {
                return false;
            }
        }

        return true;
    }
};
