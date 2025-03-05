// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
    public:
        int firstBadVersion(int n) {
            int l=1;
            int r=n;
            while(l<r){
                int mid=l+(r-l)/2;
                if(isBadVersion(mid))
                    r=mid;//保留最後一個bad version
                else 
                    l=mid+1;//找到最後一個good version,下一個就是bad version
                    //所以+1後會等於bad version的位置(l=r)就會跳出迴圈
            }
            return l;
        }
    };