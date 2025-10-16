// chrono::steady_clock::now().time_since_epoch().count();
mt19937 gen(/*seed*/ hash<string>()("ShanC_orz"));
int randint(int a, int b) {  // [a, b]
  return uniform_int_distribution<int>(a, b)(gen);
}
// srand(time(NULL)), rand() % (b - a + 1) + a;
