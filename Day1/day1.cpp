// Read input.txt and extract left and right lists.
// Part 1
// Order the lists in ascending order.
// Create a new list corresponding (right_list[i] - left_list[i]) for each i.
// Calculate the sum of the new list.
// Part 2
// Find how many times each element of the left list
// appears in the right list.
// Calculate the similatiry score (left_list[i] * n_times[i])
// Calculate the sum of the similarity scores.

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <numeric>

int main() {
    std::ifstream file("input.txt");
    std::vector<int> left_list;
    std::vector<int> right_list;
    int left, right;

    while (file >> left >> right) {
        left_list.push_back(left);
        right_list.push_back(right);
    }

    std::sort(left_list.begin(), left_list.end());
    std::sort(right_list.begin(), right_list.end());
    std::vector<int> diff_list;
    for (int i = 0; i < left_list.size(); i++) {
        if (left_list[i] < right_list[i]) diff_list.push_back(right_list[i] - left_list[i]);
        else diff_list.push_back(left_list[i] - right_list[i]);
    }

    // print the first 10 elements of the (right_list, left_list, diff_list)
    for (int i = 0; i < 10; i++) {
        std::cout << left_list[i] << " " << right_list[i] << " " << diff_list[i] << std::endl;
    }

    int sum = std::accumulate(diff_list.begin(), diff_list.end(), 0);
    
    std::cout << "Part 1 result: " << sum << std::endl;

    // Part 2
    std::vector<int> n_times;
    int similarity_score = 0;

    for (int i = 0; i < left_list.size(); i++) {
        int count = std::count(right_list.begin(), right_list.end(), left_list[i]);
        n_times.push_back(count);
        similarity_score += left_list[i] * count;
    }

    std::cout << "Part 2 result: " << similarity_score << std::endl;

    return 0;
}