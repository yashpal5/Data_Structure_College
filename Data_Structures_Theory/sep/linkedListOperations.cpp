#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* head = NULL; // Global head pointer

// Function to insert at the beginning
void insertAtBeginning(int value) {
    Node* newNode = new Node();
    newNode->data = value;
    newNode->next = head;
    head = newNode;
    cout << "Inserted " << value << " at the beginning.\n";
}

// Function to insert at the end
void insertAtEnd(int value) {
    Node* newNode = new Node();
    newNode->data = value;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
    } else {
        Node* temp = head;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = newNode;
    }
    cout << "Inserted " << value << " at the end.\n";
}

// Function to insert at a given position
void insertAtPosition(int value, int position) {
    Node* newNode = new Node();
    newNode->data = value;

    if (position == 1) { // insert at head
        newNode->next = head;
        head = newNode;
        cout << "Inserted " << value << " at position " << position << ".\n";
        return;
    }

    Node* temp = head;
    for (int i = 1; temp != NULL && i < position - 1; i++)
        temp = temp->next;

    if (temp == NULL) {
        cout << "Position out of range.\n";
        delete newNode;
        return;
    }

    newNode->next = temp->next;
    temp->next = newNode;
    cout << "Inserted " << value << " at position " << position << ".\n";
}

// Function to delete from beginning
void deleteFromBeginning() {
    if (head == NULL) {
        cout << "List is empty.\n";
        return;
    }
    Node* temp = head;
    head = head->next;
    cout << "Deleted element: " << temp->data << "\n";
    delete temp;
}

// Function to delete from end
void deleteFromEnd() {
    if (head == NULL) {
        cout << "List is empty.\n";
        return;
    }
    if (head->next == NULL) {
        cout << "Deleted element: " << head->data << "\n";
        delete head;
        head = NULL;
        return;
    }
    Node* temp = head;
    while (temp->next->next != NULL)
        temp = temp->next;

    cout << "Deleted element: " << temp->next->data << "\n";
    delete temp->next;
    temp->next = NULL;
}

// Function to delete from any position
void deleteFromPosition(int position) {
    if (head == NULL) {
        cout << "List is empty.\n";
        return;
    }

    Node* temp = head;

    if (position == 1) {
        head = head->next;
        cout << "Deleted element: " << temp->data << "\n";
        delete temp;
        return;
    }

    for (int i = 1; temp != NULL && i < position - 1; i++)
        temp = temp->next;

    if (temp == NULL || temp->next == NULL) {
        cout << "Position out of range.\n";
        return;
    }

    Node* nodeToDelete = temp->next;
    temp->next = nodeToDelete->next;
    cout << "Deleted element: " << nodeToDelete->data << "\n";
    delete nodeToDelete;
}

// Function to search an element
void searchElement(int value) {
    Node* temp = head;
    int pos = 1;
    while (temp != NULL) {
        if (temp->data == value) {
            cout << "Element " << value << " found at position " << pos << ".\n";
            return;
        }
        temp = temp->next;
        pos++;
    }
    cout << "Element " << value << " not found.\n";
}

// Function to display list
void displayList() {
    if (head == NULL) {
        cout << "List is empty.\n";
        return;
    }
    Node* temp = head;
    cout << "Linked List: ";
    while (temp != NULL) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL\n";
}

int main() {
    int choice, value, position;

    do {
        cout << "\n------ MENU ------\n";
        cout << "1. Insert at Beginning\n";
        cout << "2. Insert at End\n";
        cout << "3. Insert at Position\n";
        cout << "4. Delete from Beginning\n";
        cout << "5. Delete from End\n";
        cout << "6. Delete from Position\n";
        cout << "7. Search Element\n";
        cout << "8. Display List\n";
        cout << "9. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value: ";
                cin >> value;
                insertAtBeginning(value);
                break;

            case 2:
                cout << "Enter value: ";
                cin >> value;
                insertAtEnd(value);
                break;

            case 3:
                cout << "Enter value and position: ";
                cin >> value >> position;
                insertAtPosition(value, position);
                break;

            case 4:
                deleteFromBeginning();
                break;

            case 5:
                deleteFromEnd();
                break;

            case 6:
                cout << "Enter position: ";
                cin >> position;
                deleteFromPosition(position);
                break;

            case 7:
                cout << "Enter value to search: ";
                cin >> value;
                searchElement(value);
                break;

            case 8:
                displayList();
                break;

            case 9:
                cout << "Exiting program...\n";
                break;

            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 9);

    return 0;
}
