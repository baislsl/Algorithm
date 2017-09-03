//
// Created by baislsl on 17-9-3.
//

#include <vector>

class SqInRect {
public:
    static std::vector<int> sqInRect(int lng, int wdth) {
        if (lng == wdth) return std::vector<int>();
        std::vector<int> ans;

        while (lng != 0 && wdth != 0) {
            int cat = std::min(lng, wdth);
            ans.push_back(cat);
            if (lng == cat && wdth != cat) {
                wdth -= cat;
            } else if (lng != cat && wdth == cat) {
                lng -= cat;
            }else if(lng == cat && wdth == cat){
                break;
            }

        }
        return ans;

    }
};
