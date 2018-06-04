 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
    int eraseOverlapIntervals(vector<Interval>& intervals) { 
      //  vector <Interval> sortedIntervals;
        if (intervals.size()==0) return 0;
        for (int i=0;i<intervals.size()-1;i++){
            for (int j=i+1;j<intervals.size();j++){
                if (intervals.at(j).end<intervals.at(i).end){
                    mySwap(intervals,i,j);
                    
                }
            }
        }
        vector <Interval> sofar;
        for (int i=0;i<intervals.size();i++){
            if (compatible(intervals.at(i),sofar)) sofar.push_back(intervals.at(i));
        }
        int remove = intervals.size()-sofar.size();
        return remove;
    }
   
    void mySwap (vector <Interval>& intervals,int i,int j){
        Interval temp = Interval();
        temp.start = intervals.at(i).start;
        temp.end = intervals.at(i).end;
        intervals.at(i).start = intervals.at(j).start;
        intervals.at(i).end = intervals.at(j).end;
        intervals.at(j).start = temp.start;
        intervals.at(j).end = temp.end;
    }
    
    bool compatible(Interval& inter,vector <Interval>& intervals){
        for (int i=0;i<intervals.size();i++){
            if (!((inter.start>=intervals.at(i).end && inter.end>=intervals.at(i).end) || 
                 (inter.start<=intervals.at(i).start && inter.end<=intervals.at(i).start))) return false;
        }
        return true;
    }
};
