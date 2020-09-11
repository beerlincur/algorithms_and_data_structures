from matplotlib import pyplot as plt

names = []

compares = []

moves = []

with open("analitics.txt", "r", encoding="utf-8") as file:
    for line in file:
        line_array = line.split()
        names.append(line_array[0])
        compares.append(int(line_array[3]))
        moves.append(int(line_array[4]))

# print(names)
# print(compares)
# print(moves)



xs = [i + 0.1 for i, _ in enumerate(names)]

plt.bar(xs, compares)

plt.ylabel("compares")

plt.xlabel("sorts")

plt.xticks([i + 0.5 for i, _ in enumerate(names)], names)

plt.show()


