#pragma once
#include <string>
#include<bits/stdc++.h>

int ngram_count(int n, int str_length);
std::vector<std::string> get_ngrams(std::string str, int n);
float dice_comp(std::string a, std::string b, int n = 2);