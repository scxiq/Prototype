#include <iostream>
#include <string>

// Абстрактний клас прототипа
class Prototype {
public:
    virtual Prototype* clone() const = 0;
    virtual void display() const = 0;
};

// Конкретний клас прототипа
class ConcretePrototype : public Prototype {
public:
    ConcretePrototype(int data, std::string name) : data_(data), name_(name) {}

    Prototype* clone() const override {
        return new ConcretePrototype(*this);
    }

    void display() const override {
        std::cout << "Data: " << data_ << ", Name: " << name_ << std::endl;
    }

private:
    int data_;
    std::string name_;
};

int main() {
    // Використання паттерна "Прототип"
    ConcretePrototype prototype(42, "Prototype");
    prototype.display();

    // Копіювання прототипа
    Prototype* clone = prototype.clone();
    clone->display();

    delete clone;

    return 0;
}
