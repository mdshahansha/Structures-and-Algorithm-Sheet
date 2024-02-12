#include <iostream>
#include <bits/stdc++.h>
#include <string>
using namespace std;

void generateSubsetsString(const std::string& s, std::vector<std::string>& subsets, int index, std::string current) {
    subsets.push_back(current); // Add the current subset to subsets
    
    for (int i = index; i < s.length(); ++i) {
        current.push_back(s[i]); // Include the current character
        
        generateSubsetsString(s, subsets, i + 1, current); // Recursively generate subsets including the current character
        
        current.pop_back(); // Exclude the current character (backtrack)
    }
}

int main() {
    std::string inputString = "abc";
    std::vector<std::string> allSubsetsString;
    std::string currentSubsetString = "";

    generateSubsetsString(inputString, allSubsetsString, 0, currentSubsetString);

    // Print all subsets of the string
    for (const auto& subset : allSubsetsString) {
        std::cout << "[" << subset << "] ";
    }
    std::cout << std::endl;

    return 0;
}



// ### Generating Subsets of a String with Two Sequential Recursive Calls:



#include <iostream>
#include <vector>
#include <string>

void generateSubsetsString(const std::string& s, std::vector<std::string>& subsets, int index, std::string current) {
    if (index == s.length()) {
        subsets.push_back(current); // Add the current subset to subsets
        return;
    }

    // Include the current character
    generateSubsetsString(s, subsets, index + 1, current + s[index]);

    // Exclude the current character
    generateSubsetsString(s, subsets, index + 1, current);
}

int main() {
    std::string inputString = "abc";
    std::vector<std::string> allSubsetsString;

    generateSubsetsString(inputString, allSubsetsString, 0, "");

    // Print all subsets of the string
    for (const auto& subset : allSubsetsString) {
        std::cout << "[" << subset << "] ";
    }
    std::cout << std::endl;

    return 0;
}

/*

#include <iostream>
#include <vector>
#include <string>
using namespace std;
int c=0;

void generateSubsetsString(const std::string& s, std::vector<std::string>& subsets, int index, std::string current) {
    if (index == s.length()) {
        subsets.push_back(current); // Add the current subset to subsets
          cout<<index<<" -> BASE CASE     "<<c++<<endl;
        return;
    }

    // Include the current character
    cout<<index<<" ->StarT     "<<c++<<endl;
    generateSubsetsString(s, subsets, index + 1, current + s[index]);


    // Exclude the current character
      cout<<index<<" -> MID    "<<c++<<endl;
    generateSubsetsString(s, subsets, index + 1, current);
      cout<<index<<" -> END     "<<c++<<endl;
      cout<<endl;
}

int main() {
    std::string inputString = "abc";
    std::vector<std::string> allSubsetsString;

    generateSubsetsString(inputString, allSubsetsString, 0, "");

    // Print all subsets of the string
    for (const auto& subset : allSubsetsString) {
        std::cout << "[" << subset << "] ";
    }
    std::cout << std::endl;

    return 0;
}

*/
1 read gpt,
2 run code and print  string output as well,
3 watch coding ninja dry run video 