# Week 1 — Self-Explanation Notes

**Prepared as a study outline with AI drafting assistance.** Each team member should read and edit these explanations in their own words before presenting them as a personal understanding.

## 1. How Naive Search Works

Naive Search tries every possible starting index from 0 through `n-m`. At each position, it compares the pattern from its first character onward. If all `m` characters match, it records that starting index. After a match, it still checks the next starting position; this is why overlapping occurrences can be found. If the pattern is empty or longer than the text, our implementation returns an empty vector.

## 2. What LPS Means

For each pattern position, LPS stores the length of the longest prefix that is also a suffix of the pattern segment ending there. The prefix must be proper (not the whole segment). For `ABABAC`, LPS is `[0,0,1,2,3,0]`. When extending a matching prefix fails, `len = lps[len-1]` tries a shorter candidate that we already know could work, instead of recomputing everything from scratch.

## 3. How KMP Uses LPS

KMP uses `i` for the text and `j` for the pattern. On a successful comparison, both advance. On a mismatch with `j > 0`, it sets `j = lps[j-1]` without moving `i` backward. On a mismatch with `j == 0`, it advances `i`. When `j == m`, a full match begins at `i-m`; KMP records this and sets `j = lps[m-1]` so it can find another match, including overlaps.

## 4. Complexity

Naive Search can compare up to `m` pattern characters for many of the `n-m+1` alignments, yielding **O(nm)** worst-case time. LPS preprocessing takes **O(m)**. KMP search takes **O(n)** because text index `i` does not decrease and pattern fallback makes bounded overall progress. Therefore preprocessing plus searching is **O(n+m)**. The LPS array requires **O(m)** extra space, excluding the output match vector.

## 5. Current Limits of Our Evidence

The Week 1 console program compares Naive and KMP result vectors for an entered example. This is only a basic cross-check; a wrong but identical output from both implementations would still print PASS. Week 2 should add explicit expected outputs, empty-input cases, repeated characters, overlapping occurrences, randomized cross-checks, comparison instrumentation, and runtime benchmarks.

## 6. Questions to Be Ready to Explain Orally

- Why is the outer Naive loop bounded by `i <= n-m`?
- Why do we use `lps[len-1]` when building LPS?
- In the hand trace, why does `i` remain 5 while `j` falls from 5 to 3?
- Why reset `j` to `lps[j-1]` after a full match rather than to zero?
- Why does `Verification: PASS` not prove the algorithms are correct?

**Student review note:** Before submission or oral defense, rewrite answers that do not reflect your actual understanding, and be ready to reproduce the example without reading this file.
