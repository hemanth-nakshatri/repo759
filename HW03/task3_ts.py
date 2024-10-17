import matplotlib.pyplot as plt

thresholds = [2**i for i in range(1, 11)]
times_task3 = [
    812.784, 416.864, 198.729, 107.549, 52.0384, 31.8686, 24.6682, 23.9727, 
    21.4145, 21.3718
]


# Plotting threshold vs time for task3 with t=8 threads with xticks as powers of 2
plt.figure(figsize=(8, 6))
plt.plot(thresholds, times_task3, marker='o', linestyle='-', color='r')
plt.title('Threshold vs Time for Parallel Merge Sort (t=8 threads)')
plt.xlabel('Threshold (2^n)')
plt.ylabel('Time (ms)')
plt.xscale('log')

# Set xticks to powers of 2
plt.xticks(thresholds, [f'2^{i}' for i in range(1, 11)])

plt.grid(True)

# Save the plot as task3_1.pdf with updated xticks
plt.savefig("./task3_ts.pdf")

# Display the plot
plt.show()
