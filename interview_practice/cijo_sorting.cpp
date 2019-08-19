#include <iostream>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <random>
#include <fstream>
#include <chrono>

std::vector<double> apply_function(const std::vector<double>& vector) {
    std::vector<double> new_vect(vector.size());
    std::default_random_engine generator(std::chrono::system_clock::now().time_since_epoch().count());
    std::uniform_real_distribution<double> distribution(-1,1);

    double a=distribution(generator), b=distribution(generator), c=distribution(generator);

    for(size_t i=0; i<vector.size(); i++) {
        double val=vector[i];
        new_vect[i]= a*val*val + b*val +c;
    }

    return new_vect;
}

std::vector<double> generate_random(long int N) {
    std::vector<double> array(N);

    std::default_random_engine generator(std::chrono::system_clock::now().time_since_epoch().count());
    std::uniform_real_distribution<double> distribution(-3000,3000);

    for (int i=0; i<N; ++i) {
        array[i] = distribution(generator);
    }

    return array;
}


void write(const std::vector<double>& v) {
    std::ofstream file("output_cijo.txt");

    for(size_t i=0; i<v.size(); i++) {
        file << v[i] << std::endl;
    }
}



int main(void) {
    long int N=1000;
    std::vector<double> array= generate_random(N); /// generate random numbers here and sort
    std::sort(array.begin(), array.end());

    std::vector<double> narray= apply_function(array);
    std::vector<double> sorted(N);

    //// these might still be the bounds
    long int end=N-1;
    long int start=0;
    long int median= N/2;


    if(narray[median] > narray[start] && narray[median]>narray[end]) { ///case is concave downwards
    long int i=0;
    while(i<N) {
        if(narray[end] < narray[start]) {
            sorted[i]= narray[end];
            end--;
            i++;
        } else {
            sorted[i]= narray[start];
            start++;
            i++;
        }
    }
    } else { /// is convex

    long int i=N-1;
    while(i>=0) {
        if(narray[end] > narray[start]) {
            sorted[i]= narray[end];
            end--;
            i--;
        } else {
            sorted[i]= narray[start];
            start++;
            i--;
        }
    }
    }
    //


    std::cout<< "The start: " 
             << narray[0] 
             << " the end " 
             << narray[N-1] << std::endl;

    write(sorted);

    std::cout<< "The new start: " 
             << sorted[0] 
             << " the new end " 
             << sorted[N-1] << std::endl;
    return 0;
}










