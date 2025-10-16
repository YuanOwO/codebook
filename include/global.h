/**
 * 為了方便讓編輯 Codebook 時也能獲得 Intellisense
 * 的支援， 特此建立此檔案，引入 STL
 * 與常用的巨集、類別、函式等。
 *
 */

#include "gnu/stdc++.h"
#if defined(__clang__) || defined(_MSC_VER)
// Clang 編譯器、MSVC 編譯器不包含 GNU 的內建函式庫
#  include "gnu/builtins.h"
#endif

// Default definitions

#define ll long long
#define ull unsigned long long
#define lll __int128
#define ld long double
#define pii pair<int, int>
#define D double
#define INF 0x7f7f7f7f7f7f7f7fLL
#define REP(i, n) for (int i = 0; i < n; i++)
#define PB push_back
#define SZ(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()
#define MXN 2000005
#define MOD 1000000007

// Namespace

using namespace std;
