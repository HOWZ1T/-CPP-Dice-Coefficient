#include "dice.h"
#include <algorithm>

// TODO: CODE COMMENTS

int ngram_count(int n, int str_length)
{
    if (n < 1) { throw std::runtime_error("Invalid gram size: " + std::to_string(n)); }
    return str_length - n + 1;
}

std::vector<std::string> get_ngrams(std::string str, int n)
{
    str.erase(std::remove_if(str.begin(), str.end(), ::isspace), str.end());
    std::transform(str.begin(), str.end(), str.begin(), ::tolower);
    std::vector<std::string> out;

    int gram_count = ngram_count(n, int(str.length()));
    if (gram_count < 1 )
    {
        throw std::runtime_error("Invalid gram size: " + std::to_string(n));
    }
    else if (gram_count == 1)
    {
        out.push_back(str);
        return out;
    }

    for (int i = 0; i <= str.length() - n; i++)
    {
        std::string gram;
        for (int j = i; j < i + n; j++)
        {
            gram += str.at((unsigned long long int)j);
        }
        out.push_back(gram);
    }

    return out;
}

float dice_comp(std::string a, std::string b, int n)
{
    std::vector<std::string> grams_a = get_ngrams(a, n);
    std::vector<std::string> grams_b = get_ngrams(b, n);

    float nt = 0;
    for(std::string ga : grams_a)
    {
        for(std::string gb : grams_b)
        {
            if (ga == gb)
            {
                nt += 1.00f;
            }
        }
    }

    float nx = grams_a.size();
    float ny = grams_b.size();

    return (2 * nt) / (nx + ny);
}