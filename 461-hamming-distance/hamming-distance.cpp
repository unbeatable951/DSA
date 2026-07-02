class Solution {
public:
    int hammingDistance(int x, int y) {
        int dis = x ^ y;
        int count = 0;
        while(dis > 0)
        {
            count += (dis & 1);
            dis >>= 1;
        }
        return count;
    }
};