#include <iostream>
#include <vector>
using namespace std;

vector<int> collectSticks(vector<int>& forest, int& bird) {
    vector<int> positions; // Store positions of collected sticks
    bool goingRight = true;

    while (true) {
        bool foundStick = false; // Track if a stick is found in the current pass

        if (goingRight) {
            for (int i = bird + 1; i < forest.size(); ++i) {
                if (forest[i] > 0) {
                    positions.push_back(i); // Store the position of the collected stick
                    bird = i; // Update the bird's position
                    foundStick = true; // A stick was found
                    break; // Exit the loop after finding the first stick
                }
            }
        } else {
            for (int i = bird - 1; i >= 0; --i) {
                if (forest[i] > 0) {
                    positions.push_back(i); // Store the position of the collected stick
                    bird = i; // Update the bird's position
                    foundStick = true; // A stick was found
                    break; // Exit the loop after finding the first stick
                }
            }
        }

        // Change direction
        goingRight = !goingRight;

        // Break if no sticks were found in this round
        if (!foundStick) {
            break;
        }
    }

    return positions; // Return positions of collected sticks
}

int main() {
    int size, bird;

    // Input size and forest elements
    cin >> size;
    vector<int> forest(size);

    for (int i = 0; i < size; ++i) {
        cin >> forest[i];
    }

    // Input initial position of the bird
    cin >> bird;

    // Collect sticks and get the result
    vector<int> result = collectSticks(forest, bird);

    // Output the positions of collected sticks
    for (int val : result) {
        cout << val << " "; // Print each value in result
    }
    cout << endl;

    return 0;
}
