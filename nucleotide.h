//
// Created by tameer on 9/13/19.
//

#ifndef DNASEQUENCE_NUCLEOTIDE_H
#define DNASEQUENCE_NUCLEOTIDE_H

#include <iostream>

class Nucleotide {
public:
    Nucleotide(char ch = '\0');

    void set_nucleotide(char);

    char get_nucleotide();

    ~Nucleotide();

private:
    char m_nucleotide;

    bool checkInput(char input);
};

inline Nucleotide::Nucleotide(char nucleotide) {
    if (!checkInput(nucleotide)) {
        throw std::invalid_argument("Invalid Nucleotide !!!");
    }
    m_nucleotide = nucleotide;
}

/*this function check if the  input can be nucleotide*/
inline bool Nucleotide::checkInput(char input) {
    return (input == 'A' || input == 'T' || input == 'G' || input == 'C');
}

inline void Nucleotide::set_nucleotide(char ch) {
    m_nucleotide = ch;
}

inline char Nucleotide::get_nucleotide() {
    return m_nucleotide;
}

inline Nucleotide::~Nucleotide() {}

#endif //DNASEQUENCE_NUCLEOTIDE_H
