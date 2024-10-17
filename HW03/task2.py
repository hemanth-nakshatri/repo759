# Data: thread counts and corresponding times in milliseconds for task2
times_task2 = [
    17.285, 11.6247, 8.20347, 5.65137, 5.32512, 4.36989, 5.11142, 3.0663, 
    3.54016, 4.61154, 3.91825, 3.97608, 3.7847, 3.44939, 3.48989, 3.28919, 
    3.18507, 3.06415, 2.97061, 2.87962
]

# Plotting thread count vs time for task2
plt.figure(figsize=(8, 6))
plt.plot(threads, times_task2, marker='o', linestyle='-', color='g')
plt.title('Threads vs Time for Task 2')
plt.xlabel('Number of Threads')
plt.ylabel('Time (ms)')
plt.grid(True)

# Save the plot as task2.pdf
plt.savefig("./task2.pdf")

# Display the plot
plt.show()
