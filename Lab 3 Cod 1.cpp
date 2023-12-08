#include <iostream>

class Time {
private:
    int ore;
    int minute;
    int secunde;

public:

    Time(int ore = 0, int minute = 0, int secunde = 0) : ore(ore), minute(minute), secunde(secunde) {}


    friend Time operator+(const Time& t1, const Time& t2);
 friend Time operator-(const Time& t1, const Time& t2);


    Time& operator++();

    Time operator++(int);

    Time& operator--();

    Time operator--(int);


    void display() const {
        std::cout << "Timp: " << ore << " ore, " << minute << " minute, " << secunde << " secunde\n";
    }
};


Time operator+(const Time& t1, const Time& t2) {
    int totalSecunde = t1.ore * 3600 + t1.minute * 60 + t1.secunde +
                       t2.ore * 3600 + t2.minute * 60 + t2.secunde;

    return Time(totalSecunde / 3600, (totalSecunde % 3600) / 60, totalSecunde % 60);
}


Time operator-(const Time& t1, const Time& t2) {
    int totalSecunde = t1.ore * 3600 + t1.minute * 60 + t1.secunde -
                       t2.ore * 3600 + t2.minute * 60 + t2.secunde;

    return Time(totalSecunde / 3600, (totalSecunde % 3600) / 60, totalSecunde % 60);
}


Time& Time::operator++() {
    ++secunde;
    if (secunde == 60) {
        secunde = 0;
        ++minute;
        if (minute == 60) {
            minute = 0;
            ++ore;
            if (ore == 24) {
                ore = 0;
            }
        }
    }
    return *this;
}


Time Time::operator++(int) {
    Time temp(*this);
    ++(*this);
    return temp;
}


Time& Time::operator--() {
    --secunde;
    if (secunde < 0) {
        secunde = 59;
        --minute;
        if (minute < 0) {
            minute = 59;
            --ore;
            if (ore < 0) {
                ore = 23;
            }
        }
    }
    return *this;
}

// Supraincarcarea operatorului "--" - postfixat
Time Time::operator--(int) {
    Time temp(*this);
    --(*this);
    return temp;
}

int main() {
    Time t1(1, 30, 45);
    Time t2(0, 45, 15);


    Time sum = t1 + t2;
    Time diff = t1 - t2;
    ++t1;
    --t2;

    std::cout << "T1: ";
    t1.display();

    std::cout << "T2: ";
    t2.display();

    std::cout << "Suma (T1 + T2): ";
    sum.display();

    std::cout << "Diferenta (T1 - T2): ";
    diff.display();

    return 0;
}
