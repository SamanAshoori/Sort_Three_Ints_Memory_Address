//ownership.cpp
#include "ownership.hpp"
#include <iostream>
#include <memory>

void transfer_ownership() {
    std::unique_ptr<int> original = std::make_unique<int>(69);
    std::cout << "Original PTR Location: " << original.get() << std::endl;

    std::unique_ptr<int> receiver = std::move(original);   // transfer ownership
    std::cout << "Receiver PTR Location: " << receiver.get() << std::endl;

    if (!original) {
        std::cout << "Original is now empty (nullptr)." << std::endl;
    } else {
        std::cout << "Original PTR Value: " << *original << std::endl; // won't run
    }
}
