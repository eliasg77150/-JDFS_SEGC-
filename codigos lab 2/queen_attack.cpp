#include <iostream>
#include <utility>
#include <cstdlib>
#include <stdexcept>

// Exercism - queen-attack
class QueenAttack {
public:
    QueenAttack(std::pair<int,int> white, std::pair<int,int> black)
        : white(white), black(black) {
        validate(white);
        validate(black);
        if (white == black) {
            throw std::invalid_argument("Las reinas no pueden ocupar la misma casilla");
        }
    }

    std::pair<int,int> whitePosition() const { return white; }
    std::pair<int,int> blackPosition() const { return black; }

    bool canAttack() const {
        bool sameRow = white.first == black.first;
        bool sameCol = white.second == black.second;
        bool sameDiagonal = std::abs(white.first - black.first) ==
                             std::abs(white.second - black.second);
        return sameRow || sameCol || sameDiagonal;
    }

private:
    std::pair<int,int> white;
    std::pair<int,int> black;

    static void validate(const std::pair<int,int>& pos) {
        if (pos.first < 0 || pos.first > 7 || pos.second < 0 || pos.second > 7) {
            throw std::invalid_argument("Posicion fuera del tablero");
        }
    }
};

void test(std::pair<int,int> white, std::pair<int,int> black) {
    QueenAttack qa(white, black);
    std::cout << "Blanca(" << white.first << "," << white.second << ") vs "
              << "Negra(" << black.first << "," << black.second << ") -> "
              << (qa.canAttack() ? "SE ATACAN" : "no se atacan") << "\n";
}

int main() {
    test({2, 4}, {6, 6});
    test({2, 4}, {2, 6});
    test({4, 5}, {2, 5});
    test({2, 2}, {0, 4});
    return 0;
}
