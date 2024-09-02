/**
 * @brief factorial and it's modular inverse && 排列組合 shit
 *
 * 用法:
 * 1. 呼叫 init() 初始化
 * 2. 視情況呼叫 comb()、perm() 或 h()
 * 結果:
 * 1. 階乘及其模逆元會存在 fac[] 跟 inv[]
 * 2. comb()、perm() 或 h() 會算出結果
 * 備註: 注意數字大小不能超過 MXN
 *
 */

/**
 * @brief EXGCD 拓展歐基里德法
 * 除了求出最大公因數之外 還幫你找到 ax + by = gcd(a, b) 的一組整數解
 *
 * @param a a
 * @param b b
 * @param x x
 * @param y y
 * @return a 和 b 的最大公因數
 * 備註: x, y 是指標喔 之後得到的一組解會存在裡面
 */

/**
 * @brief 快速傅立葉變換 FFT
 *
 * 功能: 求兩多項式相乘的係數
 * 用法:
 * 1. 不管要幹嘛 先跑 pre_fft()
 * 2. 把兩陣列與長度塞入 mul()
 *    其中 a[i]: 第一個多項式 x^i 項係數, n 為其長度
 *         b[i]: 第二個多項式 x^i 項係數, m 為其長度
 *         ans[i]: 答案的多項式 x^i 項係數
 *
 * 備註: MAXN 一定要是 2 的冪次
 *      我不會工數所以我也不清楚細節 BY SHANC
 *
 */

/**
 * @brief 快速冪取模
 * 計算 x 的 y 次方對 mod 取模之值
 *
 * @param x 底數
 * @param y 指數
 * @param mod 求模的那個東東
 * @return ll x 的 y 次方之值
 */

/**
 * @brief 最小公倍數
 *
 * @param a A
 * @param b B
 * @return ll A 和 B 的最小公倍數
 */

/**
 * @brief 最大公因數
 *
 * @param a A
 * @param b B
 * @return ll A 和 B 的最大公因數
 */

/**
 * @brief Miller-Rabin test for prime test
 * 判斷質數 O(klog^3(n))
 *
 * 用法:
 * 1. 挑選一處 magic 並填入陣列大小S
 * 2. 呼叫miller_rabin(n)
 * 結果: 回傳 n 是否為質數
 * 備註:
 * 1. 要確定要判斷的整數 n 是介於 [2, n - 2]
 * 2. 測試數列 magic 如下:
 *    n < 4,759,123,141, s = 3: {2, 7, 61}
 *    n < 1,122,004,669,633, s = 4: {2, 13, 23, 1662803}
 *    n < 3,474,749,660,383, s = 6: {2, 3, 5, 7, 13}
 *    n < 2^64,
 *    s = 7: {2, 325, 9375, 28178, 450775, 9780504, 1795265022}
 *
 */

/**
 * @brief Pollard's rho Algorithm
 *
 * 用法: 呼叫 fact(n)
 * 結果: ret 存入質因數
 * 複雜度: pollard_rho: O(n^(1/4))
 * 備註:
 * -- ret 需排序
 * -- n是質數時不能用，建議搭配 Miller-Rabin
 *
 */
