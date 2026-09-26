#include <iostream>
#include <string>
#include <unordered_map>
#include <cctype>

// LeetCode 3484 - Design Spreadsheet
class Spreadsheet {
public:
    explicit Spreadsheet(int rows) : rows(rows) {}

    void setCell(const std::string& cell, int value) {
        cells[cell] = value;
    }

    void resetCell(const std::string& cell) {
        cells.erase(cell);
    }

    int getValue(const std::string& formula) const {
        size_t plusPos = formula.find('+', 1);
        std::string left = formula.substr(1, plusPos - 1);
        std::string right = formula.substr(plusPos + 1);
        return resolveOperand(left) + resolveOperand(right);
    }

private:
    int rows;
    std::unordered_map<std::string, int> cells;

    int resolveOperand(const std::string& token) const {
        if (!token.empty() && std::isdigit(static_cast<unsigned char>(token[0]))) {
            return std::stoi(token);
        }
        auto it = cells.find(token);
        return it != cells.end() ? it->second : 0;
    }
};

int main() {
    Spreadsheet spreadsheet(3);
    std::cout << "getValue(=5+7) = " << spreadsheet.getValue("=5+7") << " (esperado 12)\n";

    spreadsheet.setCell("A1", 10);
    std::cout << "getValue(=A1+6) = " << spreadsheet.getValue("=A1+6") << " (esperado 16)\n";

    spreadsheet.setCell("B2", 15);
    std::cout << "getValue(=A1+B2) = " << spreadsheet.getValue("=A1+B2") << " (esperado 25)\n";

    spreadsheet.resetCell("A1");
    std::cout << "getValue(=A1+B2) = " << spreadsheet.getValue("=A1+B2") << " (esperado 15)\n";
    return 0;
}
