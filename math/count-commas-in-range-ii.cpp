class Solution {
public:
    long long countCommas(long long n) {
        long long totalCommas = 0;
        long long start = 1000;
        long long commaCount = 1;

        while (n >= start) {
            // End boundary for the current comma bracket
            long long nextStart = start * 1000;
            long long count = min(n, nextStart - 1) - start + 1;
            
            totalCommas += count * commaCount;

            // Overflow protection for large powers of 10
            if (nextStart / 1000 != start) break;
            
            start = nextStart;
            commaCount++;
        }

        return totalCommas;
    }
};