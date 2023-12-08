#include <iostream>
#include <string>

class Presa {
protected:
    std::string* denumire;
    int tiraj;
    int indexAbonare;
    std::string* periodicitate;

public:

    Presa() : denumire(new std::string()), tiraj(0), indexAbonare(0), periodicitate(new std::string()) {}


    Presa(const std::string& denumire, int tiraj, int indexAbonare, const std::string& periodicitate)
            : denumire(new std::string(denumire)), tiraj(tiraj), indexAbonare(indexAbonare), periodicitate(new std::string(periodicitate)) {}


    virtual ~Presa() {
        delete denumire;
        delete periodicitate;
    }


    Presa(const Presa& other)
            : denumire(new std::string(*(other.denumire))), tiraj(other.tiraj), indexAbonare(other.indexAbonare), periodicitate(new std::string(*(other.periodicitate))) {}


    Presa& operator=(const Presa& other) {
        if (this != &other) {
            delete denumire;
            delete periodicitate;

            denumire = new std::string(*(other.denumire));
            tiraj = other.tiraj;
            indexAbonare = other.indexAbonare;
            periodicitate = new std::string(*(other.periodicitate));
        }
        return *this;
    }


    virtual void afisare() const {
        std::cout << "Denumire: " << *denumire << "\nTiraj: " << tiraj
                  << "\nIndex de abonare: " << indexAbonare << "\nPeriodicitate: " << *periodicitate << std::endl;
    }


    friend std::istream& operator>>(std::istream& is, Presa& presa);
    friend std::ostream& operator<<(std::ostream& os, const Presa& presa);
};


std::istream& operator>>(std::istream& is, Presa& presa) {
    std::cout << "Introduceti denumirea: ";
    std::getline(is, *presa.denumire);

    std::cout << "Introduceti tirajul: ";
    is >> presa.tiraj;

    std::cout << "Introduceti indexul de abonare: ";
    is >> presa.indexAbonare;

    std::cout << "Introduceti periodicitatea: ";
    is >> *presa.periodicitate;

    return is;
}


std::ostream& operator<<(std::ostream& os, const Presa& presa) {
    os << "Denumire: " << *presa.denumire << "\nTiraj: " << presa.tiraj
       << "\nIndex de abonare: " << presa.indexAbonare << "\nPeriodicitate: " << *presa.periodicitate;
    return os;
}


class Ziar : public Presa {
private:


public:

    Ziar(const std::string& denumire, int tiraj, int indexAbonare, const std::string& periodicitate)
            : Presa(denumire, tiraj, indexAbonare, periodicitate) {

    }


    ~Ziar() {

    }


    void afisare() const override {
        Presa::afisare();

    }


};


class Revista : public Presa {
private:


public:

    Revista(const std::string& denumire, int tiraj, int indexAbonare, const std::string& periodicitate)
            : Presa(denumire, tiraj, indexAbonare, periodicitate) {

    }


    ~Revista() {

    }


    void afisare() const override {
        Presa::afisare();

    }


};


class ZiarElectronic : public Presa {
private:


public:

    ZiarElectronic(const std::string& denumire, int tiraj, int indexAbonare, const std::string& periodicitate)
            : Presa(denumire, tiraj, indexAbonare, periodicitate) {

    }


    ~ZiarElectronic() {

    }


    void afisare() const override {
        Presa::afisare();

    }


};

int main() {
    Ziar ziar("Ziarul National", 10000, 12345, "zilnic");
    Revista revista("Revista Culturala", 5000, 67890, "saptamanal");
    ZiarElectronic ziarElectronic("ZiarOnline", 20000, 54321, "zilnic");

    std::cout << "Informatii Ziar:\n" << ziar << "\n\n";
    std::cout << "Informatii Revista:\n" << revista << "\n\n";
    std::cout << "Informatii Ziar Electronic:\n" << ziarElectronic << "\n\n";

    return 0;
}
