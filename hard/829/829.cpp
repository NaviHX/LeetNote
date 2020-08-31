/*

O(√n)

2N = (2a + i - 1) * i
2N / i - i must be odd and positive
because i <= sqrt(2N)
so we just check if 2N / i - i is odd

*/
class Solution
{
public:
    int consecutiveNumbersSum(int N)
    {
        int ans = 0;
        N *= 2;
        double s = sqrt(N);
        for (int i = 1; i <= s; i++)
            if (N % i == 0 && (N / i - i) % 2 == 1)
                ans++;
        return ans;
    }
};