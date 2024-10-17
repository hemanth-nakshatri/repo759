import matplotlib.pyplot as plt

# Data: thread counts and corresponding times in milliseconds
threads = list(range(1, 21))
times = [
    251.983, 124.94, 83.8743, 67.0746, 56.4641, 42.4258, 37.8214, 33.5774, 
    32.3255, 30.2553, 38.9272, 37.4728, 38.7733, 36.1111, 34.6684, 32.1828, 
    30.5802, 28.607, 27.2935, 26.2977
]

# Plotting thread count vs time
plt.figure(figsize=(8, 6))
plt.plot(threads, times, marker='o', linestyle='-', color='b')
plt.title('Threads vs Time for Task 1')
plt.xlabel('Number of Threads')
plt.ylabel('Time (ms)')
plt.grid(True)

# Save the plot as task1.pdf
plt.savefig("./task1.pdf")

# Display the plot
plt.show()
