/**
 * @brief 計算圓面積
 *
 * 用法:
 * 1. 初始化 init(c) 其中 c 為圓的數量
 * 2. 填入圓心與半徑到 Circle c[N] 之中
 * 3. 算出答案 solve()
 * 結果: Area[i] 為至少包括 i 個圓的覆蓋面積
 *
 * 時間複雜度: O((n^2)logn)
 *
 */

/**
 * @brief 兩圓交點
 *
 * @param o1 圓1的圓心座標
 * @param r1 圓1的半徑
 * @param o2 圓2的圓心座標
 * @param r2 圓2的半徑
 *
 * @return 兩圓的交點
 *
 * 備註: 回傳 vector 如果為空 就是沒交點
 */

/**
 * @brief 凸包 Convex Hull
 *
 * 用法: 呼叫 convex_hull() 傳入 存入所有點的 vector
 * 結果: 獲得凸包逆時針的點
 *
 */

/**
 * @brief 計算幾何一些常用功能
 *
 * 用法: 宣告 Convex 結構時傳入排序好的點陣列
 * 功能:
 * 1. inside() 判斷點是否在凸包裡 0: out, 1: on, 2: in
 * 2. tangent() 傳入一根向量 回傳切點的 idx (close = true: 近)
 * 3. tangent2() 傳入一點 回傳切線與凸包的交點
 * 4. intersect() 傳入一條線 回傳交點 (2點 or 1點 or 沒點)
 *
 * 備註:
 * 1. 注意資料型態
 * 2. Convex 結構宣告時要傳入逆時針的陣列
 *
 */

/**
 * @brief 兩圓公切線
 *
 * @param c1 圓1的結構
 * @param c2 圓2的結構
 * @param sign1 1: 外公切線; -1: 內公切線
 *
 * @return 兩圓的公切線
 *
 * 備註:
 * 回傳的 vector<Line> 中
 * 第一個是圓1的切點
 * 第二個是圓2的切點
 */

/**
 * @brief 皮克定理
 * A = i + b/2 − 1
 * 2A = 2i + b - 2 --- 同乘 2
 * i = A - b/2 + 1
 * A: 面積; b: 圖形內部的點數量; i: 圖形線上的點數量
 *
 * 用法: 先推公式 然後需要哪個就丟哪個函式
 *
 */