#include <iostream>

using namespace std;

class fur {
   protected:
    int weight;

   public:
    void setWeight(int a = 0) {
        weight = a;
    }
    int getWeight() {
        return weight;
    }
    void ShowWeight() {
        cout << "weight=" << weight << endl;
    }
};

class sofa : virtual public fur {
   public:
    void sit() {
        cout << "sit!" << endl;
    }
    void ShowWeight() {
        cout << "Sofa weight=" << weight << endl;
    }
};

class bed : virtual public fur {
   public:
    void lie() {
        cout << "lie!" << endl;
    }
    // void ShowWeight() {
    //     cout << "bed weight=" << weight << endl;
    // }
};

class sofabed : public sofa, public bed {
   public:
    void fold() {
        cout << "fold!" << endl;
    }
};
int main() {
    sofabed obj;
    obj.sit();
    obj.lie();
    obj.fold();
    obj.setWeight(100);
    obj.ShowWeight();
}