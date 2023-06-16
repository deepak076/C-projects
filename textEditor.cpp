#include <iostream>
#include <stack>
#include <queue>

using namespace std;

void printText(const string& text) {
    cout << "Text: " << text << endl;
}

void undo(stack<string>& undoStack, queue<string>& redoQueue, string& text) {
    if (!undoStack.empty()) {
        string previousText = text;
        redoQueue.push(previousText);

        text = undoStack.top();
        undoStack.pop();
    }
}

void redo(stack<string>& undoStack, queue<string>& redoQueue, string& text) {
    if (!redoQueue.empty()) {
        string previousText = text;
        undoStack.push(previousText);

        text = redoQueue.front();
        redoQueue.pop();
    }
}

void performEdit(stack<string>& undoStack, const string& previousText, string& text) {
    undoStack.push(previousText);
    printText(text);
}

int main() {
    string text;
    stack<string> undoStack;
    queue<string> redoQueue;

    char choice;
    do {
        cout << "Menu:\n";
        cout << "1. Enter text\n";
        cout << "2. Undo\n";
        cout << "3. Redo\n";
        cout << "4. Print text\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case '1': {
                string newText;
                cin.ignore(); // Ignore the newline character
                getline(cin, newText);
                string previousText = text;
                text += newText;
                performEdit(undoStack, previousText, text);
                break;
            }
            case '2':
                undo(undoStack, redoQueue, text);
                break;
            case '3':
                redo(undoStack, redoQueue, text);
                break;
            case '4':
                printText(text);
                break;
            case '5':
                cout << "Exiting the program...\n";
                break;
            default:
                cout << "Invalid choice. Try again.\n";
                break;
        }
    } while (choice != '5');

    return 0;
}
