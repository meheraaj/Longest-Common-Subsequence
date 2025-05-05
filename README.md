### 📘 **Longest Common Subsequence (LCS)**

This repository contains a simple C++ implementation of the **Longest Common Subsequence (LCS)** problem using Dynamic Programming.

---

### 🚀 **About the Problem**

Given two strings, the LCS problem is to find the longest subsequence common to both strings. A subsequence is a sequence that appears in the same relative order, but not necessarily contiguous.

---

### 🧠 **Algorithm**

**Input**:
Two strings `X` and `Y` of length `m` and `n`.

**Output**:
The longest common subsequence (LCS) string.

#### **Steps**:

1. Create a 2D array `L[0..m][0..n]` to store LCS lengths.
2. For `i = 0` to `m`:

   * For `j = 0` to `n`:

     * If `i == 0` or `j == 0`:
           `L[i][j] = 0`
     * Else if `X[i-1] == Y[j-1]`:
           `L[i][j] = L[i-1][j-1] + 1`
     * Else:
           `L[i][j] = max(L[i-1][j], L[i][j-1])`
3. Trace back from `L[m][n]` to build the LCS string by checking characters.
4. Return the LCS.

---

### ⏱️ **Time Complexity**

* **Time**: O(m × n)
* **Space**: O(m × n)
  Where `m` and `n` are the lengths of the input strings.

---

### 💻 **Code**

```cpp
#include<bits/stdc++.h>
using namespace std;

void LCS(string x, string y, int xx, int yy) {
    int xy[xx+1][yy+1];

    for(int i = 0; i <= xx; i++) {
        for(int j = 0; j <= yy; j++) {
            if(i == 0 || j == 0)
                xy[i][j] = 0;
            else if(x[i-1] == y[j-1])
                xy[i][j] = xy[i-1][j-1] + 1;
            else
                xy[i][j] = max(xy[i-1][j], xy[i][j-1]);
        }
    }

    int index = xy[xx][yy];
    char final[index + 1];
    final[index] = '\0';

    int i = xx, j = yy;
    while(i > 0 && j > 0) {
        if(x[i-1] == y[j-1]) {
            final[index - 1] = x[i - 1];
            i--; j--; index--;
        }
        else if(xy[i-1][j] > xy[i][j-1])
            i--;
        else
            j--;
    }

    cout << "LCS: " << final << endl;
}

int main() {
    string x, y;
    cin >> x >> y;
    LCS(x, y, x.size(), y.size());
    return 0;
}
```

---

### 🛠️ **How to Run**

```bash
g++ lcs.cpp -o lcs
./lcs
```

Enter two strings when prompted.

---

### 📌 Example

**Input**:

```
abcde
ace
```

**Output**:

```
LCS: ace
```
