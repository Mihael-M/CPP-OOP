/* The task was done with the help of:
* - Hristo Partenov - No:0MI0700218
* - Dimitar Conev - No:72087
* - Victor Milanov - No:0MI0700270
* - Zhozhemir Kushev - No:8MI0700284
*/

#include <stdio.h>
#include <iostream>
#include "MultiSet.h"
#include <fstream>

MultiSet::MultiSet(unsigned n, unsigned k) {
    this->bucketsCount = ((n + 1) * k) / this->elementsInBucket + 1;
    this->buckets = new uint8_t[this->bucketsCount]{ 0 };
    this->n = n + 1;
    this->k = k;
}
void MultiSet::free() {
    delete[] this->buckets;
    this->bucketsCount = 0;
    this->n = 0;
    this->k = 0;
    this->buckets = nullptr;
}
void MultiSet::copyFrom(const MultiSet& other) {
    this->buckets = new uint8_t[other.bucketsCount];
    for (size_t i = 0; i < other.bucketsCount; i++)
    {
        this->buckets[i] = other.buckets[i];
    }
    this->bucketsCount = other.bucketsCount;
    this->n = other.n;
    this->k = other.k;
}


MultiSet::MultiSet(const MultiSet& other) {
    copyFrom(other);
}


MultiSet& MultiSet::operator=(const MultiSet& other){
    if (this != &other){
        free();
        copyFrom(other);
    }
    return *this;
}

unsigned MultiSet::getNumberStartIndex(unsigned num) const{
    return this->k * (num - 1);
}

MultiSet::~MultiSet(){
    free();
}



bool MultiSet::isInOneBucket(unsigned startIndex) const {
    return startIndex / elementsInBucket == (startIndex + k - 1) / elementsInBucket;
}


unsigned MultiSet::getBucketIndex(unsigned num) const{
    return num / elementsInBucket;
}

bool MultiSet::contains(uint8_t num) const{
    
    if(countOfNumber(num) != 0){
        return true;
    }
    
    return false;
    
}
unsigned creatingMaskWithOnes(size_t start,size_t end) {
    
    unsigned mask = 0;
    for (size_t i = start; i < end; i++){
        mask += (1 << i);
    }
    
    return mask;
}




void MultiSet::add(unsigned num){
    
    unsigned maxOccurrences = (1 << k) - 1;
     
    if(countOfNumber(num) + 1 > maxOccurrences){
        return;
    }
    
    
    num++; // because of 0
    if (num > n) {
        return;
    }
    
    
    
    unsigned startIndexOfNumber = getNumberStartIndex(num);
    unsigned bucketIndex = getBucketIndex(startIndexOfNumber);

    
    
    if (isInOneBucket(startIndexOfNumber)) {
        uint8_t mask = (1 << elementsInBucket - ((startIndexOfNumber + k - 1) % elementsInBucket) - 1);
        buckets[bucketIndex] += mask;
    }
    else {
        unsigned elementsInFirstBucket = elementsInBucket - (startIndexOfNumber % elementsInBucket);
        unsigned elementsInSecondBucket = k - elementsInFirstBucket;
         
        
        
        unsigned mask = 0;
      
        for (int i = elementsInBucket - 1; i >= elementsInBucket - elementsInSecondBucket; i--){
            mask += (1 << i);
        }
        
        if (!((buckets[bucketIndex + 1] & mask) == mask)) {
            buckets[bucketIndex + 1] += (1 << (elementsInBucket - elementsInSecondBucket));
            return;
        }

        buckets[bucketIndex + 1] &= (~mask);
        mask = creatingMaskWithOnes(0, elementsInFirstBucket);
        if (!((buckets[bucketIndex] & mask) == mask)) {
            buckets[bucketIndex]++;
        }
    }
}

unsigned MultiSet::countOfNumber(unsigned num) const {
    
    num++;
    if (num > n) {
        return 0;
    }
    unsigned startIndexOfNumber = getNumberStartIndex(num);
    unsigned bucketIndex = getBucketIndex(startIndexOfNumber);
    unsigned startIndexInTheBucket = startIndexOfNumber % elementsInBucket;
    if (isInOneBucket(startIndexOfNumber)) {
        unsigned movedBucked = buckets[bucketIndex] >> (elementsInBucket - k - startIndexInTheBucket);
        unsigned mask = creatingMaskWithOnes(0, k);

        return (movedBucked & mask);
    }
    else {
        unsigned elementsInFirstBucket = elementsInBucket - (startIndexOfNumber % elementsInBucket);
        unsigned elementsInSecondBucket = k - elementsInFirstBucket;
        unsigned mask = creatingMaskWithOnes(0, elementsInFirstBucket);
        
        unsigned result = ((buckets[bucketIndex] & mask) << elementsInSecondBucket);

        unsigned movedBucked = buckets[bucketIndex + 1] >> (elementsInBucket - elementsInSecondBucket);
        mask = creatingMaskWithOnes(0, elementsInSecondBucket);
        return result + (movedBucked & mask);
    }

    
}


void printBinary(uint8_t num) {
    int size = sizeof(num) * 8;
    for (int i = size - 1; i >= 0; i--) {
        int bit = (num >> i) & 1;
        std::cout << bit;
    }
}

void MultiSet::printLikeInMemory() const{
    
    for (int i = 0; i < bucketsCount; i++){
        printBinary(buckets[i]);
        std::cout<<std::endl;
    }
}



void MultiSet::serialize(std::ofstream& ofs) const{

     if (!ofs.is_open()) {
         return;
     }

     ofs.write((const char*)&bucketsCount, sizeof(bucketsCount));
     ofs.write((const char*)&n, sizeof(n));
     ofs.write((const char*)&k, sizeof(k));

     ofs.write((const char*)buckets, sizeof(uint8_t) * bucketsCount);

     ofs.close();
 }



 void MultiSet::deserialize(std::ifstream& ifs) {

     if (!ifs.is_open()) {
         return;
     }

     unsigned bucketsCount;
     ifs.read((char*)&bucketsCount, sizeof(bucketsCount));

     unsigned n;
     ifs.read((char*)&n, sizeof(n));

     unsigned k;
     ifs.read((char*)&k, sizeof(k));

     delete[]this->buckets;

     this->buckets = new uint8_t[bucketsCount];
     this->bucketsCount = bucketsCount;
     this->n = n;
     this->k = k;

     ifs.read((char*)buckets, sizeof(uint8_t) * bucketsCount);

     ifs.close();
 }



unsigned MultiSet::getCountOfAllNumbers() const{
    
    int count = 0;
    for (int i = 0; i < n; i++){
        if (countOfNumber(i) > 0){
            count++;
        }
    }
    return count;
}


MultiSet intersectionOfSets(const MultiSet& lhs, const MultiSet& rhs){
   
    MultiSet intersect(lhs.n,lhs.k);
    
    int minSize = std::min(lhs.n,rhs.n);
    for(int i = 0;i<minSize;i++){
        if(lhs.contains(i) && rhs.contains(i)){
            int countInIntersect = std::min(lhs.countOfNumber(i), rhs.countOfNumber(i));
            for(int j = 0;j<countInIntersect;j++){
                intersect.add(i);
            }
        }
    }
    
    return intersect;
    
    
}


MultiSet differenceOfSets(const MultiSet& lhs, const MultiSet& rhs) {
    MultiSet result(lhs.n, lhs.k);
    
    int minSize = std::min(lhs.n,rhs.n);
    for(int i = 0;i<minSize;i++){
        if(lhs.contains(i) && !rhs.contains(i)){
            int timesOccur = lhs.countOfNumber(i);
            for(int j = 0;j<timesOccur;j++){
                result.add(i);
            }
        }
    }
    return result;
}




void MultiSet::complement(int num){
    
    num++;
    if (num > n) {
        return;
    }
    
    
    unsigned startIndexOfNumber = getNumberStartIndex(num);
    unsigned bucketIndex = getBucketIndex(startIndexOfNumber);
    unsigned startIndexInTheBucket = startIndexOfNumber % elementsInBucket;
    int mask = 0;
    
    if (isInOneBucket(startIndexOfNumber)) {
        mask = creatingMaskWithOnes(0, k);
        buckets[bucketIndex] ^= (mask << (elementsInBucket - k - startIndexInTheBucket));
    }
    
    else{
        
        
        unsigned elementsInFirstBucket = elementsInBucket - (startIndexOfNumber % elementsInBucket);
        unsigned elementsInSecondBucket = k - elementsInFirstBucket;
        mask = creatingMaskWithOnes(0, elementsInSecondBucket);
        buckets[bucketIndex + 1] ^= (mask << (elementsInBucket - elementsInSecondBucket));
        
        
        mask = 0;
        mask = creatingMaskWithOnes(0, elementsInFirstBucket);
        buckets[bucketIndex] ^= mask;
    }
}




void MultiSet::printMultiSet() const{
    
    std::cout<<"{ ";
    for(int i = 0;i<n;i++){
        int currCount = countOfNumber(i);
        for(int j = 0;j<currCount;j++){
            std::cout<<i<<" ";
        }
    }
    std::cout << " }" << std::endl;
}
