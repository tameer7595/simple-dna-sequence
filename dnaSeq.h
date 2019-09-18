//
// Created by tameer on 9/11/19.
//
#include <iostream>
#include <stdlib.h>
#include "string.h"
#include "nucleotide.h"

#ifndef DNASEQUENCE_DNASEQ_H
#define DNASEQUENCE_DNASEQ_H

class DnaSequence {
public:
    DnaSequence(char *);

    DnaSequence(std::string);

    DnaSequence(const DnaSequence &);

    ~DnaSequence();

    const DnaSequence &operator=(const DnaSequence &);

    bool operator==(const DnaSequence &other);

    friend std::ostream &operator<<(std::ostream &os, const DnaSequence &dt);

    char operator[](int);

    DnaSequence* slice(int ,int);

    std::string pairing();
    int Find(DnaSequence *sub,int);
    void FindAll(DnaSequence *sub,int);
    int Count(DnaSequence* sub);
    int length() const;
    void find_consensus_sequences(int);


private:
    Nucleotide *dna;
};

inline DnaSequence::DnaSequence(char *ch) {
    this->dna = (Nucleotide *) malloc(sizeof(Nucleotide) * strlen(ch)+1);
    unsigned int i = 0;
    while (i < strlen(ch)) {
        dna[i] = ch[i];
        i++;
    }

}

inline DnaSequence::DnaSequence(std::string str) {
    this->dna = (Nucleotide *) malloc(sizeof(Nucleotide) * str.length());
    unsigned int  i = 0;
    while (i < str.length()) {
        dna[i] = str[i];
        i++;
    }
}

inline DnaSequence::DnaSequence(const DnaSequence &other) {
    this->dna = (Nucleotide *) malloc(sizeof(Nucleotide) * other.length());
    int i = 0;
    while (i < other.length()) {
        this->dna[i] = other.dna[i].get_nucleotide();
        i++;
    }
}

inline DnaSequence::~DnaSequence() {
    free(dna);
}

inline const DnaSequence &DnaSequence::operator=(const DnaSequence &other) {
    this->dna = (Nucleotide *) malloc(sizeof(Nucleotide) * other.length());
    int i = 0;
    while (i < other.length()) {
        this->dna[i] = other.dna[i].get_nucleotide();
        i++;
    }
    return *this;
}

inline bool DnaSequence::operator==(const DnaSequence &other) {
    if (this->length() != other.length())
        return false;
    else {
        int i = 0;
        while (i < this->length()) {
            if (this->dna[i].get_nucleotide() != other.dna[i].get_nucleotide())
                return false;
        }
        return true;
    }
}

inline int DnaSequence::length() const {
    int count = 0;
    int i = 0;
    while (dna[i].get_nucleotide() != '\0' ) {
        count++;
        i++;
    }
    return count;

}

#endif //DNASEQUENCE_DNASEQ_H
