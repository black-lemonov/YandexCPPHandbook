#include <iostream>
#include <string>
#include <list>
#include <utility>


struct TextEditor {
    std::list<std::string> document;
    std::list<std::string>::iterator cursor;
    std::list<std::string>::iterator secondaryCursor;
    std::list<std::string> largeBuffer;
    bool shiftPressed = false;
    bool reversed = false;
};


void InitEditor(TextEditor& editor) {
    std::string line;
	while (true) {
        std::getline(std::cin, line);
        if (line.empty()) {
            break;
        }
        editor.document.push_back(line);
    }
    editor.cursor = editor.document.begin();
}


void PrintDocument(const TextEditor& editor) {
    for (const auto& s : editor.document) {
        std::cout << s << '\n';
    }
}


void Shift(TextEditor& editor) {
	editor.shiftPressed = true;
	editor.secondaryCursor = editor.cursor;
}


void Down(TextEditor& editor) {
    if (editor.shiftPressed && editor.cursor == editor.secondaryCursor) {
        editor.reversed = true; 
    }
    if (editor.cursor == editor.document.end()) {
        return;
    }
    ++editor.cursor;
}


void Up(TextEditor& editor) {
    if (editor.shiftPressed && editor.cursor == editor.secondaryCursor) {
        editor.reversed = false;
    }
    if (editor.cursor == editor.document.begin()) {
        return;
    }
    --editor.cursor;
}


void CtrlX(TextEditor& editor) {
	if (!editor.shiftPressed && editor.cursor == editor.document.end()) {
        return;
    }
    if (editor.shiftPressed
        && editor.cursor == editor.document.end()
        && editor.secondaryCursor == editor.document.end()) {
        editor.shiftPressed = false;
        return;
    }
    if (editor.shiftPressed && editor.cursor != editor.secondaryCursor) {
        if (editor.reversed) {
            std::swap(editor.cursor, editor.secondaryCursor);
            editor.reversed = false;
        }
        if (!editor.largeBuffer.empty()) {
            editor.largeBuffer.clear();
        }
        editor.largeBuffer.splice(
            editor.largeBuffer.begin(),
            editor.document,
            editor.cursor, editor.secondaryCursor
        );
        editor.cursor = editor.secondaryCursor;
        editor.shiftPressed = false;
        return;
	}
    editor.largeBuffer.assign(1, *editor.cursor);
    editor.cursor = editor.document.erase(editor.cursor);
    editor.shiftPressed = false;
}


void CtrlV(TextEditor& editor) {
    if (editor.largeBuffer.empty()) {
        editor.shiftPressed = false;
        editor.reversed = false;
        return;
    }
    if (editor.shiftPressed && editor.cursor != editor.secondaryCursor) {
        if (editor.reversed) {
            std::swap(editor.cursor, editor.secondaryCursor);
            editor.reversed = false;
        }
        editor.cursor = editor.document.erase(editor.cursor, editor.secondaryCursor);
	}
    editor.document.insert(editor.cursor, editor.largeBuffer.begin(), editor.largeBuffer.end());
    editor.shiftPressed = false;
}


void CommandContext(const std::string& command, TextEditor& editor) {
    if (command == "Down") {
        Down(editor);
    } else if (command == "Up") {
        Up(editor);
    } else if (command == "Ctrl+X") {
        CtrlX(editor);
    } else if (command == "Ctrl+V") {
        CtrlV(editor);
    } else if (command == "Shift") {
        Shift(editor);
    }
}


int main() {
    TextEditor editor;
    InitEditor(editor);
    std::string command;
    while (std::cin >> command) {
        CommandContext(command, editor);
    }
    // while (true) {
    //     std::getline(std::cin, command);
    //     if (command.empty()) {
    //         break;
    //     } 
    //     CommandContext(command, editor);
    // }
    PrintDocument(editor);
}