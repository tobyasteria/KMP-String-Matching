# Week 1 — KMP Hand-Traced Example

## 1. Input

**Text:** `ABABABAC`  
**Pattern:** `ABABAC`

Text length: `n = 8`  
Pattern length: `m = 6`

Expected match position: `2` (0-based indexing).

## 2. LPS Array

For the pattern `ABABAC`:

| Index | Character | LPS Value | Explanation |
|---|---|---|---|
| 0 | A | 0 | No proper prefix |
| 1 | B | 0 | No matching prefix and suffix |
| 2 | A | 1 | `A` |
| 3 | B | 2 | `AB` |
| 4 | A | 3 | `ABA` |
| 5 | C | 0 | No matching prefix and suffix |

**Final LPS array:** `[0, 0, 1, 2, 3, 0]`

## 3. KMP Search — Step-by-Step Trace

`i` represents the current index in the text.

`j` represents the current index in the pattern and the number of pattern characters already matched.

The table shows the values before each comparison.

| Step | i | j | Comparison | Action |
|---|---:|---:|---|---|
| 1 | 0 | 0 | A = A | Match; i++, j++ |
| 2 | 1 | 1 | B = B | Match; i++, j++ |
| 3 | 2 | 2 | A = A | Match; i++, j++ |
| 4 | 3 | 3 | B = B | Match; i++, j++ |
| 5 | 4 | 4 | A = A | Match; i++, j++ |
| 6 | 5 | 5 | B ≠ C | Set j = LPS[4] = 3 |
| 7 | 5 | 3 | B = B | Match; i++, j++ |
| 8 | 6 | 4 | A = A | Match; i++, j++ |
| 9 | 7 | 5 | C = C | Match; i++, j++ |

After step 9:

- `i = 8`
- `j = 6`
- `j == m`, so a complete match is found.
- Match position = `i - m = 8 - 6 = 2`.
- Set `j = LPS[5] = 0` to allow searching for additional matches.

## 4. How LPS Avoids Repeated Comparisons

At step 6, KMP has matched `ABABA`, but the next characters differ (`B ≠ C`).

Since `LPS[4] = 3`, the matched sequence `ABABA` has a longest proper prefix that is also a suffix: `ABA`.

Instead of restarting the search and comparing earlier text characters again, KMP sets `j = 3` and keeps `i = 5`.

It then compares the same text character `B` against `pattern[3]`, which is also `B`.

This allows KMP to reuse information from previous matches and skip unnecessary comparisons.

## 5. Final Result

**Naive Search:** `[2]`  
**KMP Search:** `[2]`

Both algorithms identify the same occurrence.

KMP avoids restarting character comparisons from earlier positions in the text.

**Conclusion:** The failure function helps KMP maintain previously learned matching information. This is a key reason why KMP achieves O(n + m) total time complexity, including preprocessing.