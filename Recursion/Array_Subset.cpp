#include <iostream>
#include <vector>
using namespace std;

void generateSubsets(const std::vector<int>& nums, std::vector<std::vector<int>>& subsets, int index, std::vector<int>& current) {
    // Yahaan par hum current subset ko subsets vector mein daalte hain
    subsets.push_back(current);

    // Ab hum loop chalate hain diye gaye index se lekar numbers ke size tak
    for (int i = index; i < nums.size(); ++i) {
        // Yahaan par hum current element ko include karte hain
        current.push_back(nums[i]);

        // Fir se call karte hain function ko, lekin next index se (i + 1) aur usme include karte hain current element ko
        generateSubsets(nums, subsets, i + 1, current);

        // Yahaan par hum current element ko exclude karte hain (backtrack)
        current.pop_back();
    }
}


int main() {
    std::vector<int> inputArray = {1, 2, 3};
    std::vector<std::vector<int>> allSubsets;

    std::vector<int> currentSubset;
    generateSubsets(inputArray, allSubsets, 0, currentSubset);

    // Print all subsets
    for (const auto& subset : allSubsets) {
        std::cout << "[";
        for (int num : subset) {
            std::cout << num << " ";
        }
        std::cout << "] ";
    }
    std::cout << std::endl;

    return 0;
}



// ### Generating Subsets of an Array with Two Sequential Recursive Calls:
 
#include <iostream>
#include <vector>

void generateSubsetsArray(const std::vector<int>& nums, std::vector<std::vector<int>>& subsets, int index, std::vector<int>& current) {
    if (index == nums.size()) {
        subsets.push_back(current); // Add the current subset to subsets
        return;
    }

    // Include the current element
    current.push_back(nums[index]);
    generateSubsetsArray(nums, subsets, index + 1, current);

    // Exclude the current element
    current.pop_back();
    generateSubsetsArray(nums, subsets, index + 1, current);
}

int main() {
    std::vector<int> inputArray = {1, 2, 3};
    std::vector<std::vector<int>> allSubsetsArray;
    std::vector<int> currentSubsetArray;

    generateSubsetsArray(inputArray, allSubsetsArray, 0, currentSubsetArray);

    // Print all subsets of the array
    for (const auto& subset : allSubsetsArray) {
        std::cout << "[";
        for (int num : subset) {
            std::cout << num << " ";
        }
        std::cout << "] ";
    }
    std::cout << std::endl;

    return 0;
}

//Array use karke h 


void generateSubsetsArraym(int nums[], int size, int index, int current[], int currentSize, int subsets[MAX_SIZE][MAX_SIZE], int& subsetCount) {
    // Yahaan par hum har current subset ko subsets array mein daal rahe hain
    for (int i = 0; i < currentSize; ++i) {
        subsets[subsetCount][i] = current[i];
    }
    subsetCount++; // Subsets ki count badhate ja rahe hain

    // Yahaan par loop chalate hain diye gaye index se lekar array size tak
    for (int i = index; i < size; ++i) {
        if (i > index && nums[i] == nums[i - 1]) {
            continue; // Agar current element previous element ke barabar hai, toh usko skip karte hain (duplicate)
        }

        current[currentSize] = nums[i]; // Yahaan par hum current element ko include karte hain
        generateSubsetsArray(nums, size, i + 1, current, currentSize + 1, subsets, subsetCount); // Recursion ke through subsets generate karte hain, including the current element
    }
}
