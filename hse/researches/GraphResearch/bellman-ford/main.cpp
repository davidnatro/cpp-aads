#include <iostream>
#include <vector>
#include <limits>
#include <chrono>
#include <fstream>

const int kInf = std::numeric_limits<int>::max();

// Функция для реализации алгоритма Форда-Беллмана
void BellmanFord(const std::vector<std::vector<int>>& graph, int startNode,
                 std::vector<int>& distances) {
    int numNodes = graph.size();

    // Инициализация расстояний до всех узлов как бесконечность, кроме стартового узла
    distances.assign(numNodes, kInf);
    distances[startNode] = 0;

    // Релаксация ребер (numNodes - 1) раз
    for (int k = 0; k < numNodes - 1; ++k) {
        for (int u = 0; u < numNodes; ++u) {
            for (int v = 0; v < numNodes; ++v) {
                if (graph[u][v] != 0 && distances[u] != kInf &&
                    distances[u] + graph[u][v] < distances[v]) {
                    distances[v] = distances[u] + graph[u][v];
                }
            }
        }
    }
}

int main() {
    std::ifstream inputFile("bellman_ford.txt");

    if (inputFile.is_open()) {
        std::vector<int> numbers;
        int num;
        while (inputFile >> num) {
            numbers.push_back(num);
        }

        inputFile.close();  // Закрываем файл
        int rows = numbers[0];
        int columns = numbers[1];

        std::vector<std::vector<int>> matrix(rows, std::vector<int>(columns));

        int index = 2;
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < columns; ++j) {
                matrix[i][j] = numbers[index];
                index += 1;
            }
        }

        std::vector<int> distances(rows);

        auto start = std::chrono::high_resolution_clock::now();

        BellmanFord(matrix, 0, distances);

        auto elapsed = std::chrono::high_resolution_clock::now() - start;

        int64_t nanoseconds = std::chrono::duration_cast<std::chrono::nanoseconds>(elapsed).count();

        std::cout << nanoseconds;
        return 0;
    }
}