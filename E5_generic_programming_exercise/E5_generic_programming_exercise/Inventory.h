#ifndef INVENTORY_H
#define INVENTORY_H

// TODO implement template class Inventory
// it is a polymorphic class with a virtual printContent() method
// it represents a container of objects of the same type with a maximum number of stored objects
// defined at compile time (use a non-type template argument) or creation time (constructor parameter)
// use an array to store objects and an array of booleans to know if a slot is occupied or not
// default number of stored objects is 5
template <typename T, int N=5>
class Inventory {
public:
    explicit Inventory() {
        for (int i=0; i<N; i++) {
            usedElements[i]=false;
        }
    };
    virtual ~Inventory() {}
    bool setElement(int pos, const T& element);

    bool getElement(int pos, const T& element);

    int getMaxElements() const {
        return maxElements;
    };

    virtual void printContent() const;

protected:
    int maxElements=10; // max number of objects that can be stored
    T elements[N];
    bool usedElements[N];
};

template <typename T, int N>
bool Inventory<T, N>::setElement(int pos, const T& element){ //inserisce un elemento
    if (pos>0 && pos<maxElements && !usedElements[pos]) {
        elements[pos] = element;
        usedElements[pos] = true;
        return true;
    }
    return false;
};

template<typename T, int N>
bool Inventory<T, N>::getElement(int pos, const T& element) { //leva gli elementi
    if (pos>0 && pos<maxElements && usedElements[pos]) {
        element = elements[pos];
        usedElements[pos] = false;
        return true;
    }
    return false;
}


template <typename T, int N>
void Inventory<T,N>::printContent() const {
    for (int i=0; i<N; i++) {
        if (usedElements[i])
            std::cout << i << ":" << elements[i] << std::endl;
    }
}

#endif //INVENTORY_H
