#include <iostream>
#include <string>

class Procesor {
private:
    std::string* denumire;
    float frecventa;
    std::string* tehnologiiProducere;
    int marimeMemorie;

public:

    Procesor() : denumire(new std::string()), frecventa(0.0f), tehnologiiProducere(new std::string()), marimeMemorie(0) {}


    Procesor(const std::string& denumire, float frecventa, const std::string& tehnologiiProducere, int marimeMemorie)
            : denumire(new std::string(denumire)), frecventa(frecventa), tehnologiiProducere(new std::string(tehnologiiProducere)), marimeMemorie(marimeMemorie) {}


    ~Procesor() {
        delete denumire;
        delete tehnologiiProducere;
    }


    void afisare() const {
        std::cout << "Denumire procesor: " << *denumire << "\nFrecventa: " << frecventa
                  << " GHz\nTehnologii de producere: " << *tehnologiiProducere << "\nMarime memorie: " << marimeMemorie << " GB\n";
    }
};

class Computer {
private:
    Procesor* procesor;


public:

    Computer() : procesor(new Procesor()) {}


    Computer(const std::string& denumireProcesor, float frecventaProcesor, const std::string& tehnologiiProducere, int marimeMemorie)
            : procesor(new Procesor(denumireProcesor, frecventaProcesor, tehnologiiProducere, marimeMemorie)) {}


    ~Computer() {
        delete procesor;

    }


    void afisare() const {
        std::cout << "Informatii computer:\n";
        procesor->afisare();

    }
};

int main() {

    Computer computer1("Intel Core i7", 3.5f, "14nm", 16);
    Computer computer2;  // Utilizare constructor implicit


    std::cout << "Computer 1:\n";
    computer1.afisare();
    std::cout << "\nComputer 2:\n";
    computer2.afisare();

    return 0;
}
