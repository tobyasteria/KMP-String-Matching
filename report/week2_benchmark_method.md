# Week 2 Benchmark Method

The benchmark compares Naive Search and KMP Search using two types of datasets: Natural Text and Adversarial Text. Natural Text is generated from a repeated English sentence. Adversarial Text consists entirely of the character 'a', while the pattern contains 100 'a' characters followed by 'b'.

For both datasets, three text lengths are tested: 10,000, 50,000, and 100,000 characters. The Natural pattern is "algorithms" (10 characters), and the Adversarial pattern has 101 characters.

For each dataset, both algorithms are run twice as warm-up iterations. The program then measures each algorithm 10 times using `std::chrono::steady_clock`. The average execution time is calculated in microseconds (µs). Dataset generation and console output are excluded from the timed sections.

The program verifies that Naive Search and KMP Search return identical match positions. It also compares their results with an independent reference implementation using `std::string::find()`. The benchmark results are saved to `results/benchmark_week2.csv` for further analysis.