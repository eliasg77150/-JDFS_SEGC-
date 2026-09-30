#pragma once
#include <mutex>
#include <stdexcept>

namespace bank_account {

class Bankaccount {
public:
    Bankaccount() = default;

    void open();
    void close();
    int balance() const;
    void deposit(int amount);
    void withdraw(int amount);

private:
    mutable std::mutex mutex_;
    bool abierta_ = false;
    int saldo_ = 0;
};

}  // namespace bank_account
