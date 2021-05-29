import matplotlib.pyplot as plt
import math
# line 1 points
x = [5, 10, 15, 20, 25]
y = [math.log(5,10), math.log(10,10), math.log(15,10) ,math.log(20,10) ,math.log(25,10)]


plt.plot(x, y, label = "O(n)")
# naming the x axis

plt.xlabel('N (size)')
# naming the y axis
plt.ylabel('Elapsed Time (ms)')
# giving a title to my graph
plt.title('Theoretical Linear Search Graph (Iterative and Recursive)')

  
# show a legend on the plot

plt.legend()
  
# function to show the plot
plt.show()