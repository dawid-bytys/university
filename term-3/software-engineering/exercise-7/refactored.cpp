#include <iostream>

class Seller {
 private:
  int count_of_delayed_deliveries;

 public:
  Seller() : count_of_delayed_deliveries(0) {}

  void increase_count_of_delayed_deliveries() {
    ++count_of_delayed_deliveries;
  }

  bool is_seller_punctual() const {
    return count_of_delayed_deliveries > 5 ? true : false;
  };
};
