class Solution {
public:
    long long countCommas(long long n) {
        long long start = 1000;
        long long totalcommas = 0;
        long long comma = 1;
        while (n >= start) {
            long long nextstart = 1000 * start;
            long long count = min(n, nextstart - 1) - start + 1;
            totalcommas += count * comma;
            if (nextstart / 1000 != start)
                break;
            start = nextstart;
            comma++;
        }
        return totalcommas;
    }
};