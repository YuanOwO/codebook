#include <bits/stdc++.h>
using namespace std;
mt19937 gen(/*seed*/ hash<string>()("SHIKA"));
chrono::steady_clock::now().time_since_epoch().count();
int randint(int a, int b) {  // [a, b]
  return uniform_int_distribution<int>(a, b)(gen);
}
