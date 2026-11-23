#include <iostream>

void towerOfHanoi(int n, char source, char destination, char auxiliary) {

    if (n == 1) {
        std::cout << "Move disk 1 from " << source << " to " << destination << std::endl;
        return;
    }
    
    // Step 1: Move (n - 1) disks from source to auxiliary using destination
    towerOfHanoi(n - 1, source, auxiliary, destination);
    
    // Step 2: Move the nth disk from source to destination
    std::cout << "Move disk " << n << " from " << source << " to " << destination << std::endl;
    
    // Step 3: Move the (n - 1) disks from auxiliary to destination using source
    towerOfHanoi(n - 1, auxiliary, destination, source);
}

int main() {
    int n = 3; // Number of disks
    
    std::cout << "Steps to solve Towers of Hanoi for " << n << " disks:" << std::endl;
    towerOfHanoi(n, 'A', 'C', 'B'); // A = Source, C = Destination, B = Auxiliary
    
    return 0;
}

