#include "bank_account.h"

namespace bank_account {

void Bankaccount::open() {
    std::lock_guard<std::mutex> lock(mutex_);
    if (abierta_) {
        throw std::domain_error("La cuenta ya esta abierta");
    }
    abierta_ = true;
    saldo_ = 0;
}

void Bankaccount::close() {
    std::lock_guard<std::mutex> lock(mutex_);
    if (!abierta_) {
        throw std::domain_error("La cuenta ya esta cerrada");
    }
    abierta_ = false;
    saldo_ = 0;
}

int Bankaccount::balance() const {
    std::lock_guard<std::mutex> lock(mutex_);
    if (!abierta_) {
        throw std::domain_error("La cuenta esta cerrada");
    }
    return saldo_;
}

void Bankaccount::deposit(int amount) {
    std::lock_guard<std::mutex> lock(mutex_);
    if (!abierta_) {
        throw std::domain_error("La cuenta esta cerrada");
    }
    if (amount < 0) {
        throw std::domain_error("No se puede depositar un monto negativo");
    }
    saldo_ += amount;
}

void Bankaccount::withdraw(int amount) {
    std::lock_guard<std::mutex> lock(mutex_);
    if (!abierta_) {
        throw std::domain_error("La cuenta esta cerrada");
    }
    if (amount < 0) {
        throw std::domain_error("No se puede retirar un monto negativo");
    }
    if (amount > saldo_) {
        throw std::domain_error("Fondos insuficientes para el retiro");
    }
    saldo_ -= amount;
}

}  // namespace bank_account
