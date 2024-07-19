#include <iostream> // Standard input-output stream
#include <vector> // Standard vector container
#include <algorithm> // Standard algorithms (e.g., sort)
#include <optional> // For optional return types

// Median-of-three pivot selection with constexpr
constexpr int medianOfThree(int a, int b, int c) {
    // Returns the median of three values
    return (a < b) ? ((b < c) ? b : (a < c) ? c : a) : ((a < c) ? a : (b < c) ? c : b);
}

// Partition function to rearrange elements around the pivot
int partition(std::vector<int>& arr, int low, int high) {
    int mid = low + (high - low) / 2; // Find the middle index
    int pivot = medianOfThree(arr[low], arr[mid], arr[high]); // Choose the pivot using median-of-three
    int left = low, right = high - 1; // Initialize left and right pointers
    while (true) {
        // Move left pointer to the right until an element greater than pivot is found
        while (arr[++left] < pivot);
        // Move right pointer to the left until an element less than pivot is found
        while (arr[--right] > pivot);
        if (left >= right) break; // If pointers cross, partitioning is done
        std::swap(arr[left], arr[right]); // Swap elements
    }
    std::swap(arr[left], arr[high - 1]); // Place pivot in the correct position
    return left; // Return the partition index
}

// Optimized quicksort with optional error handling
std::optional<int> quickSort(std::vector<int>& arr, int low, int high) {
    if (low >= high) return std::nullopt; // No sorting needed for single element
    if (low + 10 <= high) {
        int pi = partition(arr, low, high); // Partition the array
        quickSort(arr, low, pi - 1); // Recursively sort the left subarray
        quickSort(arr, pi + 1, high); // Recursively sort the right subarray
    } else {
        std::sort(arr.begin() + low, arr.begin() + high + 1); // Use std::sort for small arrays
    }
    return 0; // Indicate successful sort
}

int main() {
    std::vector<int> arr = {10, 7, 8, 9, 1, 5}; // Example array
    int n = arr.size(); // Size of the array
    if (quickSort(arr, 0, n - 1)) {
        std::cout << "Sorted array: ";
        for (const auto& el : arr) {
            std::cout << el << " "; // Print sorted array
        }
        std::cout << std::endl;
    } else {
        std::cout << "Error sorting the array" << std::endl; // Error handling
    }
    return 0; // Return successful execution
}
