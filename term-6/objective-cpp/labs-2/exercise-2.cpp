#include <iostream>
#include <string>

class Animal {
 protected:
  std::string name;

 public:
  Animal(const std::string &name) : name(name) {}

  virtual void make_sound() const {
    std::cout << "Generic animal sound\n";
  }

  virtual ~Animal() {}
};

class Dog : public Animal {
 public:
  Dog(const std::string &name) : Animal(name) {}

  void make_sound() const override {
    std::cout << name << " says Woof!\n";
  }
};

class Cat : public Animal {
 public:
  Cat(const std::string &name) : Animal(name) {}

  void make_sound() const override {
    std::cout << name << " says Meow!\n";
  }
};

void print_animal_sound(const Animal &animal) {
  animal.make_sound();
}

int main() {
  Dog my_dog("Buddy");
  Cat my_cat("Whiskers");

  // Dynamic polymorphism
  print_animal_sound(my_dog);
  print_animal_sound(my_cat);

  // Static polymorphism
  my_dog.make_sound();
  my_cat.make_sound();

  return 0;
}
