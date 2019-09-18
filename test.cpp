//
// Created by tameer on 9/17/19.
//

#include "test.h"
#include "dnaSeq.h"
#include <fstream>
#include <iostream>
using std::ifstream;
void Test::working_without_file() {

    char* dna = (char*)"GAGATGGAGTAAATGCCCGAGTGA";
    DnaSequence d(dna);

    std :: cout <<"the length of : "<< d <<"is: "<< d.length()<< std::endl;
    std :: cout <<"subseq after calling  slice(0,3) is :";
    DnaSequence *newdna = d.slice(0,3);
    std::cout << *newdna<<std::endl;

    std::cout<<"result of the pairing process :"<< d.pairing()<<std::endl;
    std::cout<<"the index of subsequence "<<*newdna <<"is :"<< d.Find(newdna,0)<<std::endl;
    std::cout<<"number of occurrences : "<<d.Count(newdna)<<std::endl;
    d.FindAll(newdna,0);
    std::cout <<"The consensus sequences in the DNA sequence is: "<<std::endl;
    d.find_consensus_sequences(0);
    delete newdna;
}

void Test:: working_with_file(){
    std::string line;
    ifstream input_file ("input.txt");
    if (input_file.is_open()){
        while ( getline (input_file,line) )
        {
            std::cout << "*************** new dna seq******************"<<std::endl;
            DnaSequence d(line);

            std :: cout <<"the length of : "<< d <<"is: "<< d.length()<< std::endl;
            std :: cout <<"subseq after calling  slice(0,3) is :";
            DnaSequence *newdna = d.slice(0,3);
            std::cout << *newdna<<std::endl;

            std::cout<<"result of the pairing process :"<< d.pairing()<<std::endl;
            std::cout<<"the index of subsequence "<<*newdna <<"is :"<< d.Find(newdna,0)<<std::endl;
            std::cout<<"number of occurrences : "<<d.Count(newdna)<<std::endl;
            d.FindAll(newdna,0);
            std::cout <<"The consensus sequences in the DNA sequence is: "<<std::endl;
            d.find_consensus_sequences(0);
            delete newdna;
        }
        input_file.close();
    }

}