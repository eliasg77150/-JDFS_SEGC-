#include "hamming.h"
#include <stdexcept>

namespace hamming {

int compute(const std::string& strand_a, const std::string& strand_b) {
    if (strand_a.size() != strand_b.size()) {
        throw std::domain_error("Las hebras deben tener la misma longitud");
    }

    int distancia = 0;
    for (size_t i = 0; i < strand_a.size(); ++i) {
        if (strand_a[i] != strand_b[i]) {
            ++distancia;
        }
    }

    return distancia;
}

}  // namespace hamming
