#include <iostream>
#include <algorithm>
#include <iomanip>
using namespace std;

class ArrayOperations {
private:
    int* arr;
    int size;
    int capacity;

public:
    // Constructor
    ArrayOperations(int cap = 10) {
        capacity = cap;
        size = 0;
        arr = new int[capacity];
        cout << "Array created with capacity: " << capacity << endl;
    }

    // Destructor
    ~ArrayOperations() {
        delete[] arr;
    }

    // 1. Insert at end
    void insertAtEnd(int value) {
        if (size >= capacity) {
            cout << "Array is full! Cannot insert " << value << endl;
            return;
        }
        arr[size] = value;
        size++;
        cout << "Inserted " << value << " at end. New size: " << size << endl;
    }

    // 2. Insert at beginning
    void insertAtBeginning(int value) {
        if (size >= capacity) {
            cout << "Array is full! Cannot insert " << value << endl;
            return;
        }
        // Shift all elements to the right
        for (int i = size; i > 0; i--) {
            arr[i] = arr[i-1];
        }
        arr[0] = value;
        size++;
        cout << "Inserted " << value << " at beginning. New size: " << size << endl;
    }

    // 3. Insert at specific position
    void insertAtPosition(int position, int value) {
        if (position < 0 || position > size) {
            cout << "Invalid position! Valid range: 0 to " << size << endl;
            return;
        }
        if (size >= capacity) {
            cout << "Array is full! Cannot insert " << value << endl;
            return;
        }
        
        // Shift elements to the right from the position
        for (int i = size; i > position; i--) {
            arr[i] = arr[i-1];
        }
        arr[position] = value;
        size++;
        cout << "Inserted " << value << " at position " << position << ". New size: " << size << endl;
    }

    // 4. Delete from end
    void deleteFromEnd() {
        if (size == 0) {
            cout << "Array is empty! Nothing to delete." << endl;
            return;
        }
        int deletedValue = arr[size-1];
        size--;
        cout << "Deleted " << deletedValue << " from end. New size: " << size << endl;
    }

    // 5. Delete from beginning
    void deleteFromBeginning() {
        if (size == 0) {
            cout << "Array is empty! Nothing to delete." << endl;
            return;
        }
        int deletedValue = arr[0];
        // Shift all elements to the left
        for (int i = 0; i < size-1; i++) {
            arr[i] = arr[i+1];
        }
        size--;
        cout << "Deleted " << deletedValue << " from beginning. New size: " << size << endl;
    }

    // 6. Delete from specific position
    void deleteFromPosition(int position) {
        if (position < 0 || position >= size) {
            cout << "Invalid position! Valid range: 0 to " << (size-1) << endl;
            return;
        }
        if (size == 0) {
            cout << "Array is empty! Nothing to delete." << endl;
            return;
        }
        
        int deletedValue = arr[position];
        // Shift elements to the left from the position
        for (int i = position; i < size-1; i++) {
            arr[i] = arr[i+1];
        }
        size--;
        cout << "Deleted " << deletedValue << " from position " << position << ". New size: " << size << endl;
    }

    // 7. Delete by value
    void deleteByValue(int value) {
        for (int i = 0; i < size; i++) {
            if (arr[i] == value) {
                deleteFromPosition(i);
                return;
            }
        }
        cout << "Value " << value << " not found in array." << endl;
    }

    // 8. Linear Search
    int linearSearch(int value) {
        for (int i = 0; i < size; i++) {
            if (arr[i] == value) {
                cout << "Linear Search: " << value << " found at index " << i << endl;
                return i;
            }
        }
        cout << "Linear Search: " << value << " not found in array." << endl;
        return -1;
    }

    // 9. Binary Search (requires sorted array)
    int binarySearch(int value) {
        int left = 0, right = size - 1;
        int comparisons = 0;
        
        while (left <= right) {
            comparisons++;
            int mid = left + (right - left) / 2;
            
            if (arr[mid] == value) {
                cout << "Binary Search: " << value << " found at index " << mid << " (comparisons: " << comparisons << ")" << endl;
                return mid;
            }
            else if (arr[mid] < value) {
                left = mid + 1;
            }
            else {
                right = mid - 1;
            }
        }
        cout << "Binary Search: " << value << " not found in array (comparisons: " << comparisons << ")" << endl;
        return -1;
    }

    // 10. Display/Traverse array
    void display() {
        if (size == 0) {
            cout << "Array is empty!" << endl;
            return;
        }
        cout << "Array contents (" << size << "/" << capacity << "): ";
        for (int i = 0; i < size; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    // 11. Reverse array
    void reverse() {
        if (size <= 1) {
            cout << "Array has less than 2 elements. Nothing to reverse." << endl;
            return;
        }
        
        for (int i = 0; i < size/2; i++) {
            int temp = arr[i];
            arr[i] = arr[size-1-i];
            arr[size-1-i] = temp;
        }
        cout << "Array reversed successfully." << endl;
    }

    // 12. Sort array (Bubble Sort)
    void bubbleSort() {
        if (size <= 1) {
            cout << "Array has less than 2 elements. Nothing to sort." << endl;
            return;
        }
        
        for (int i = 0; i < size-1; i++) {
            for (int j = 0; j < size-i-1; j++) {
                if (arr[j] > arr[j+1]) {
                    // Swap elements
                    int temp = arr[j];
                    arr[j] = arr[j+1];
                    arr[j+1] = temp;
                }
            }
        }
        cout << "Array sorted using Bubble Sort." << endl;
    }

    // 13. Find maximum element
    int findMax() {
        if (size == 0) {
            cout << "Array is empty!" << endl;
            return -1;
        }
        
        int maxVal = arr[0];
        int maxIndex = 0;
        
        for (int i = 1; i < size; i++) {
            if (arr[i] > maxVal) {
                maxVal = arr[i];
                maxIndex = i;
            }
        }
        cout << "Maximum element: " << maxVal << " at index " << maxIndex << endl;
        return maxVal;
    }

    // 14. Find minimum element
    int findMin() {
        if (size == 0) {
            cout << "Array is empty!" << endl;
            return -1;
        }
        
        int minVal = arr[0];
        int minIndex = 0;
        
        for (int i = 1; i < size; i++) {
            if (arr[i] < minVal) {
                minVal = arr[i];
                minIndex = i;
            }
        }
        cout << "Minimum element: " << minVal << " at index " << minIndex << endl;
        return minVal;
    }

    // 15. Calculate sum of all elements
    int calculateSum() {
        if (size == 0) {
            cout << "Array is empty! Sum = 0" << endl;
            return 0;
        }
        
        int sum = 0;
        for (int i = 0; i < size; i++) {
            sum += arr[i];
        }
        cout << "Sum of all elements: " << sum << endl;
        return sum;
    }

    // 16. Calculate average
    double calculateAverage() {
        if (size == 0) {
            cout << "Array is empty! Cannot calculate average." << endl;
            return 0;
        }
        
        double avg = (double)calculateSum() / size;
        cout << "Average of all elements: " << fixed << setprecision(2) << avg << endl;
        return avg;
    }

    // 17. Update element at specific position
    void updateElement(int position, int newValue) {
        if (position < 0 || position >= size) {
            cout << "Invalid position! Valid range: 0 to " << (size-1) << endl;
            return;
        }
        
        int oldValue = arr[position];
        arr[position] = newValue;
        cout << "Updated element at position " << position << " from " << oldValue << " to " << newValue << endl;
    }

    // 18. Check if array is sorted
    bool isSorted() {
        for (int i = 0; i < size-1; i++) {
            if (arr[i] > arr[i+1]) {
                cout << "Array is not sorted." << endl;
                return false;
            }
        }
        cout << "Array is sorted in ascending order." << endl;
        return true;
    }

    // 19. Count occurrences of a value
    int countOccurrences(int value) {
        int count = 0;
        for (int i = 0; i < size; i++) {
            if (arr[i] == value) {
                count++;
            }
        }
        cout << "Value " << value << " occurs " << count << " times in the array." << endl;
        return count;
    }

    // 20. Get array statistics
    void getStatistics() {
        if (size == 0) {
            cout << "Array is empty! No statistics available." << endl;
            return;
        }
        
        cout << "\n=== ARRAY STATISTICS ===" << endl;
        cout << "Size: " << size << "/" << capacity << endl;
        cout << "Elements: ";
        display();
        findMin();
        findMax();
        calculateSum();
        calculateAverage();
        isSorted();
        cout << "========================" << endl;
    }

    // Utility functions
    int getSize() const { return size; }
    int getCapacity() const { return capacity; }
    bool isEmpty() const { return size == 0; }
    bool isFull() const { return size == capacity; }
};

// Function to display menu
void displayMenu() {
    cout << "\n=== ARRAY OPERATIONS MENU ===" << endl;
    cout << "1.  Insert at End" << endl;
    cout << "2.  Insert at Beginning" << endl;
    cout << "3.  Insert at Position" << endl;
    cout << "4.  Delete from End" << endl;
    cout << "5.  Delete from Beginning" << endl;
    cout << "6.  Delete from Position" << endl;
    cout << "7.  Delete by Value" << endl;
    cout << "8.  Linear Search" << endl;
    cout << "9.  Binary Search (sorted array)" << endl;
    cout << "10. Display Array" << endl;
    cout << "11. Reverse Array" << endl;
    cout << "12. Sort Array (Bubble Sort)" << endl;
    cout << "13. Find Maximum" << endl;
    cout << "14. Find Minimum" << endl;
    cout << "15. Calculate Sum" << endl;
    cout << "16. Calculate Average" << endl;
    cout << "17. Update Element" << endl;
    cout << "18. Check if Sorted" << endl;
    cout << "19. Count Occurrences" << endl;
    cout << "20. Array Statistics" << endl;
    cout << "21. Demo All Operations" << endl;
    cout << "0.  Exit" << endl;
    cout << "=============================" << endl;
}

// Function to demonstrate all operations
void demoAllOperations() {
    cout << "\n=== DEMONSTRATING ALL ARRAY OPERATIONS ===" << endl;
    
    ArrayOperations demo(15);
    
    // Insert operations
    cout << "\n--- INSERTION OPERATIONS ---" << endl;
    demo.insertAtEnd(10);
    demo.insertAtEnd(20);
    demo.insertAtEnd(30);
    demo.insertAtBeginning(5);
    demo.insertAtPosition(2, 15);
    demo.display();
    
    // Search operations
    cout << "\n--- SEARCH OPERATIONS ---" << endl;
    demo.linearSearch(20);
    demo.linearSearch(100);
    
    // Statistical operations
    cout << "\n--- STATISTICAL OPERATIONS ---" << endl;
    demo.findMax();
    demo.findMin();
    demo.calculateSum();
    demo.calculateAverage();
    demo.countOccurrences(20);
    
    // Modification operations
    cout << "\n--- MODIFICATION OPERATIONS ---" << endl;
    demo.updateElement(1, 25);
    demo.display();
    demo.reverse();
    demo.display();
    
    // Sorting and binary search
    cout << "\n--- SORTING AND BINARY SEARCH ---" << endl;
    demo.bubbleSort();
    demo.display();
    demo.isSorted();
    demo.binarySearch(20);
    demo.binarySearch(100);
    
    // Deletion operations
    cout << "\n--- DELETION OPERATIONS ---" << endl;
    demo.deleteByValue(15);
    demo.deleteFromEnd();
    demo.deleteFromBeginning();
    demo.deleteFromPosition(1);
    demo.display();
    
    // Final statistics
    cout << "\n--- FINAL STATISTICS ---" << endl;
    demo.getStatistics();
    
    cout << "\n=== DEMO COMPLETED ===" << endl;
}

int main() {
    cout << "Welcome to Comprehensive Array Operations Program!" << endl;
    
    int capacity;
    cout << "Enter the capacity of the array: ";
    cin >> capacity;
    
    ArrayOperations arrayOps(capacity);
    int choice;
    
    do {
        displayMenu();
        cout << "Enter your choice: ";
        cin >> choice;
        
        switch (choice) {
            case 1: {
                int value;
                cout << "Enter value to insert at end: ";
                cin >> value;
                arrayOps.insertAtEnd(value);
                break;
            }
            case 2: {
                int value;
                cout << "Enter value to insert at beginning: ";
                cin >> value;
                arrayOps.insertAtBeginning(value);
                break;
            }
            case 3: {
                int position, value;
                cout << "Enter position and value: ";
                cin >> position >> value;
                arrayOps.insertAtPosition(position, value);
                break;
            }
            case 4: {
                arrayOps.deleteFromEnd();
                break;
            }
            case 5: {
                arrayOps.deleteFromBeginning();
                break;
            }
            case 6: {
                int position;
                cout << "Enter position to delete: ";
                cin >> position;
                arrayOps.deleteFromPosition(position);
                break;
            }
            case 7: {
                int value;
                cout << "Enter value to delete: ";
                cin >> value;
                arrayOps.deleteByValue(value);
                break;
            }
            case 8: {
                int value;
                cout << "Enter value to search: ";
                cin >> value;
                arrayOps.linearSearch(value);
                break;
            }
            case 9: {
                int value;
                cout << "Enter value to search (binary): ";
                cin >> value;
                cout << "Note: Array should be sorted for binary search!" << endl;
                arrayOps.binarySearch(value);
                break;
            }
            case 10: {
                arrayOps.display();
                break;
            }
            case 11: {
                arrayOps.reverse();
                break;
            }
            case 12: {
                arrayOps.bubbleSort();
                break;
            }
            case 13: {
                arrayOps.findMax();
                break;
            }
            case 14: {
                arrayOps.findMin();
                break;
            }
            case 15: {
                arrayOps.calculateSum();
                break;
            }
            case 16: {
                arrayOps.calculateAverage();
                break;
            }
            case 17: {
                int position, value;
                cout << "Enter position and new value: ";
                cin >> position >> value;
                arrayOps.updateElement(position, value);
                break;
            }
            case 18: {
                arrayOps.isSorted();
                break;
            }
            case 19: {
                int value;
                cout << "Enter value to count: ";
                cin >> value;
                arrayOps.countOccurrences(value);
                break;
            }
            case 20: {
                arrayOps.getStatistics();
                break;
            }
            case 21: {
                demoAllOperations();
                break;
            }
            case 0: {
                cout << "Thank you for using Array Operations Program!" << endl;
                break;
            }
            default: {
                cout << "Invalid choice! Please try again." << endl;
                break;
            }
        }
        
        if (choice != 0 && choice != 21) {
            cout << "\nPress Enter to continue...";
            cin.ignore();
            cin.get();
        }
        
    } while (choice != 0);
    
    return 0;
}