// Read input.txt -  a list of n elements
// Check each row for safety
// Safety criteria:
// 1. The row is ordered in ascending or descending order.
// 2. Adjacent columns differ by at least 1 and at most 3.
// Count the number of safe rows.

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <sstream>

int check_row(std::vector<int> row) {
    int ascending = 0;
    int descending = 0;
    int levels_check = 0;

    int row_size = row.size();
    for (int j = 0; j < row_size; j++) {
        ascending += (j < row_size-1) ? (row[j] < row[j + 1]) : 0;
        descending += (j < row_size-1) ? (row[j] > row[j + 1]) : 0;
        levels_check += (j < row_size-1) ? (std::abs(row[j + 1] - row[j]) >= 1 && std::abs(row[j + 1] - row[j]) <= 3) : 0;
    }
    return (ascending == row_size-1 || descending == row_size-1) && levels_check == row_size-1;
}



int main() {
    std::ifstream file("input.txt");
    std::vector<std::vector<int>> matrix;
    std::vector<int> row;
    int count = 0;
    int count_part2 = 0;

    // Read from file line an undetermined number of rows
    while (!file.eof()) {
        row.clear();        
        std::string line;

        // Read a line from the file
          if (std::getline(file, line)) {
            std::istringstream iss(line);
            int value;
            while (iss >> value)  row.push_back(value);
        }

        matrix.push_back(row);
    }


    for (int i = 0; i < int(matrix.size()); i++) {
        
        if (check_row(matrix[i]) == 1) {
            count++;
            count_part2++;
        } else {
            for (int j = 0; j < int(matrix[i].size()); j++) {
                // row_copy equals matrix[i] minus the element at index j
                std::vector<int> row_copy = matrix[i];
                row_copy.erase(row_copy.begin() + j);
                if (check_row(row_copy) == 1) {
                    count_part2++;
                    break;
                }
            }
        }
    }

    std::cout << "Number of safe rows (Part 1): " << count << std::endl;        
    std::cout << "Number of safe rows (Part 2): " << count_part2 << std::endl; 

    return 0;
}