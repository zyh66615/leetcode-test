static const auto _ = []()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    string intToRoman(int num) {
        const std::string m[4][10] =
            {{"", "M", "MM", "MMM"},
             {"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"},
             {"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"},
             {"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"}};
        const int d[4] = {1000, 100, 10, 1};

        std::string roman;
        for (int i = 0; i < 4; ++i) {
            roman += m[i][num / d[i]];
            num %= d[i];
        }
        return roman;
    }
};