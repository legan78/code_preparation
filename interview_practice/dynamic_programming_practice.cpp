#include <iostream>
#include <cstdlib>
#include <vector>

#define MYINF 5000

std::ostream& operator<<(std::ostream& os, const std::vector<int>& v) {

    for(size_t i= 0; i< v.size(); i++) {
        os<< v[i] << " ";
    }

    return os;
}

int main() {
    int pp[]= {1,5,8,9,10,17,17,20,24,30};
    std::vector<int> P(pp, pp+10);
    std::vector<int> revs(11, 0);
    int rod_length= 10;


    for(size_t i=1; i<=10; i++) {
        revs[i]=-MYINF;

        for(size_t j=1; j<=i; j++) {
            revs[i]= std::max(P[j-1]+revs[i-j], revs[i]);
        }
    }

    std::cout << revs << std::endl;

    return 0;
}
