#include <iostream>
#include <string>
#include <array>
#include <stdexcept>

// Exercism - robot-simulator
class Robot {
public:
    enum Direction { NORTH = 0, EAST = 1, SOUTH = 2, WEST = 3 };

    Robot(int x = 0, int y = 0, Direction dir = NORTH)
        : x(x), y(y), dir(dir) {}

    void turnRight() { dir = static_cast<Direction>((dir + 1) % 4); }
    void turnLeft()  { dir = static_cast<Direction>((dir + 3) % 4); }

    void advance() {
        static const std::array<int, 4> dx = {0, 1, 0, -1};
        static const std::array<int, 4> dy = {1, 0, -1, 0};
        x += dx[dir];
        y += dy[dir];
    }

    void simulate(const std::string& instructions) {
        for (char c : instructions) {
            switch (c) {
                case 'A': advance(); break;
                case 'R': turnRight(); break;
                case 'L': turnLeft(); break;
                default:
                    throw std::invalid_argument(std::string("Instruccion invalida: ") + c);
            }
        }
    }

    int getX() const { return x; }
    int getY() const { return y; }
    Direction getDirection() const { return dir; }

    static std::string directionName(Direction d) {
        switch (d) {
            case NORTH: return "NORTH";
            case EAST:  return "EAST";
            case SOUTH: return "SOUTH";
            case WEST:  return "WEST";
        }
        return "UNKNOWN";
    }

private:
    int x, y;
    Direction dir;
};

void printState(const Robot& r, const std::string& label) {
    std::cout << label << " -> (" << r.getX() << ", " << r.getY()
              << "), " << Robot::directionName(r.getDirection()) << "\n";
}

int main() {
    Robot r1;
    printState(r1, "Estado inicial");

    r1.turnRight();
    printState(r1, "Tras turnRight()");

    Robot r2(7, 3, Robot::NORTH);
    r2.simulate("RAALAL");
    printState(r2, "Robot desde (7,3) tras RAALAL"); // esperado: (9,4) WEST
    return 0;
}
