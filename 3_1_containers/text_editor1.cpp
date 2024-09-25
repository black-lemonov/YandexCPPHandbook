#include <iostream>
#include <string>
#include <list>

struct TextEditor {
    std::list<std::string> document;
    std::list<std::string>::iterator cursor;
    std::string buffer;
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

void Down(TextEditor& editor) {
    if (editor.cursor == editor.document.end()) {
        return;
    }
    ++editor.cursor;
}

void Up(TextEditor& editor) {
    if (editor.cursor == editor.document.begin()) {
        return;
    }
    --editor.cursor;
}

void CtrlX(TextEditor& editor) {
    if (editor.cursor == editor.document.end()) {
        return;
    }
    editor.buffer = *editor.cursor;
    editor.cursor = editor.document.erase(editor.cursor);
}

void CtrlV(TextEditor& editor) {
    if (editor.buffer.empty()) {
        return;
    }
    editor.document.insert(editor.cursor, editor.buffer);
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
    }
}

int main() {
    TextEditor editor;
    InitEditor(editor);
    std::string command;
    while (true) {
        std::getline(std::cin, command);
        if (command.empty()) {
            break;
        }
        CommandContext(command, editor);
    } 
    PrintDocument(editor);
}