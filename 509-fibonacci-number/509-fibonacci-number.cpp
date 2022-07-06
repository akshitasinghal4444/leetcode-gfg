class Solution {
public:
    int fib(int n) {
	double goldenRatio = (1 + sqrt(5)) / 2;
	return round(pow(goldenRatio, n) / sqrt(5));
}
};