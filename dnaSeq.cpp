//
// Created by tameer on 9/11/19.
//

#include "dnaSeq.h"

std::ostream &operator<<(std::ostream &os, const DnaSequence &dt) {
    size_t i = 0;
    char temp;
    size_t len = dt.length();
    while (i < len) {
        temp = dt.dna[i].get_nucleotide();
        os << temp;
        i++;
    }
    return os;
}

char DnaSequence::operator[](int index) {
    if (index > this->length())
        throw std::out_of_range("Bad Index");
    return dna[index].get_nucleotide();
}

DnaSequence *DnaSequence::slice( int start,  int end) {
    if(start < 0 || end > this->length())
        throw std::bad_alloc();
    std::string temp = "";
    while (start < end) {
        temp += this->dna[start].get_nucleotide();
        start++;
    }
    return (new DnaSequence(temp));
}

/* replace A<->T AND G<->C THEN REVERSE THE RESULT */
std::string DnaSequence::pairing() {
    std::string pairing = "";
    unsigned int i = 0;
    while (i < (unsigned int )this->length()) {
        if (dna[i].get_nucleotide() == 'A')
            pairing += 'T';
        if (dna[i].get_nucleotide() == 'T')
            pairing += 'A';
        if (dna[i].get_nucleotide() == 'G')
            pairing += 'C';
        if (dna[i].get_nucleotide() == 'C')
            pairing += 'G';
        i++;
    }

    /* reversed a String*/
    i = 0;
    unsigned int j = (unsigned int)pairing.length() - 1;
    while (i < j) {
        char temp;
        temp = pairing[i];
        pairing[i] = pairing[j];
        pairing[j] = temp;
        i++;
        j--;
    }
    return pairing;
}

/* look for a given subsequence if it found return the started index*/
int  DnaSequence::Find(DnaSequence* sub,int startfrom){
    int i=startfrom,j=0;
    int index;
    while(i < this->length()) {
        if (this->dna[i].get_nucleotide() == sub->dna[j].get_nucleotide()){
            index = i;
            while ((this->dna[i].get_nucleotide() == sub->dna[j].get_nucleotide()) &&
               (j < sub->length() && i < this->length())) {
                i++;
                j++;
            }
            if (j == sub->length())
            return index;
            else {
                j = 0;
            }
        }else
            i++;
    }
        return -1;
}
/*Find all the occurrences of a subsequence within a sequence*/
void DnaSequence :: FindAll(DnaSequence *sub,int){
    int start=0;
    while(start < length() && start != -1){
        start = Find(sub,start);
        if(start>=0){
            std::cout<<"INDEX "<<start<< " : "<<*(slice(start,sub->length()+start))<<std::endl;
        }
        if(start !=-1)
            start+= sub->length();
    }
}

int  DnaSequence::Count(DnaSequence* sub){
    int i=0,j=0;
    int count = 0;
    while(i < this->length()) {
        if (this->dna[i].get_nucleotide() == sub->dna[j].get_nucleotide()) {
            while ((this->dna[i].get_nucleotide() == sub->dna[j].get_nucleotide()) &&
                   (j < sub->length() && i < this->length())) {
                i++;
                j++;
            }
            if (j == sub->length()) {
                count++;
                j = 0;
            }
        } else
            i++;

    }
    return count;
}
/*prvide all the Consensus Sequence in a DNA Sequence*/
void DnaSequence :: find_consensus_sequences(int startrfrom){
    if(startrfrom >= length())
        return;
    DnaSequence start_codon((char*)"ATG");
    DnaSequence end_codon1((char*)"TAG");
    DnaSequence end_codon2((char*)"TAA");
    DnaSequence end_codon3((char*)"TGA");
    int start_index = Find(&start_codon,startrfrom);
    int end_index;
    if(start_index > 0){
        end_index = Find(&end_codon1,startrfrom);
        if(end_index > 0 && (end_index -(start_index+2)-1)%3==0 )
            std::cout<<*(slice(start_index,end_index+3))<<std::endl;

        else {
            end_index = Find(&end_codon2,startrfrom);
            if (end_index > 0 && (end_index - (start_index + 2) - 1) % 3 == 0)
                std::cout << *(slice(start_index, end_index + 3))<<std::endl;
            else {
                end_index = Find(&end_codon3,startrfrom);
                if (end_index > 0 && (end_index - (start_index + 2) - 1) % 3 == 0)
                    std::cout << *(slice(start_index, end_index + 3))<< std::endl;
            }
        }
    }
    find_consensus_sequences(end_index+3);
}