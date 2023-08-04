#include <iostream>
#include <list>
#include <string>

class Animal {
public:
    Animal(const std::string& name) : name(name) {}
    virtual ~Animal() = default;
    virtual const std::string& getName() const {
        return name;
    }

private:
    std::string name;
};

class Dog : public Animal {
public:
    Dog(const std::string& name) : Animal(name) {}
};

class Cat : public Animal {
public:
    Cat(const std::string& name) : Animal(name) {}
};

class AnimalShelter {
public:
    // Enqueue an animal (either Dog or Cat) into the shelter
    void enqueue(Animal* animal) {
        if (dynamic_cast<Dog*>(animal)) {
            dogQueue.push_back(animal);
        } else if (dynamic_cast<Cat*>(animal)) {
            catQueue.push_back(animal);
        }
    }

    // Dequeue the oldest animal of any type
    Animal* dequeueAny() {
        if (dogQueue.empty() && catQueue.empty()) {
            return nullptr;
        }

        if (dogQueue.empty()) {
            return dequeueCat();
        } else if (catQueue.empty()) {
            return dequeueDog();
        }

        if (dogQueue.front() < catQueue.front()) {
            return dequeueDog();
        } else {
            return dequeueCat();
        }
    }

    // Dequeue the oldest dog
    Dog* dequeueDog() {
        if (dogQueue.empty()) {
            return nullptr;
        }

        Dog* oldestDog = dynamic_cast<Dog*>(dogQueue.front());
        dogQueue.pop_front();
        return oldestDog;
    }

    // Dequeue the oldest cat
    Cat* dequeueCat() {
        if (catQueue.empty()) {
            return nullptr;
        }

        Cat* oldestCat = dynamic_cast<Cat*>(catQueue.front());
        catQueue.pop_front();
        return oldestCat;
    }

private:
    std::list<Animal*> dogQueue;
    std::list<Animal*> catQueue;
};

int main() {
    AnimalShelter shelter;

    shelter.enqueue(new Dog("Dog1"));
    shelter.enqueue(new Cat("Cat1"));
    shelter.enqueue(new Dog("Dog2"));
    shelter.enqueue(new Cat("Cat2"));

    Animal* oldestAnimal = shelter.dequeueAny();
    if (oldestAnimal) {
        std::cout << "Adopted " << oldestAnimal->getName() << std::endl;
        delete oldestAnimal;
    }

    Dog* oldestDog = shelter.dequeueDog();
    if (oldestDog) {
        std::cout << "Adopted Dog " << oldestDog->getName() << std::endl;
        delete oldestDog;
    }

    Cat* oldestCat = shelter.dequeueCat();
    if (oldestCat) {
        std::cout << "Adopted Cat " << oldestCat->getName() << std::endl;
        delete oldestCat;
    }

    return 0;
}
