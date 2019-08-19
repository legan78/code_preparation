#include <iostream>
#include <cstdlib>
#include <string>
#include <map> 
#include <exception>


bool unique(const char* str) {
    std::map<char, char> mymap;

    for(size_t i=0; str[i]!='\0'; i++) {
        try{
            //// the character exists!
            mymap.at(str[i])= str[i];
            return false;
        } catch(std::out_of_range& e) {
            //// the character doesnt exist
            mymap[str[i]]=str[i];
        }
    }

    return true;
}


void string_unique() {
//    bool is_unique= unique("angelnoemartinezgonzalez");
//    bool is_unique= unique("abcdefghijklmnopqrstuvwxyz");
//    bool is_unique= unique("aaaaaaaaaaaaaaaaa");
    bool is_unique= unique("this one wa");

    if(is_unique) std::cout << "String has no repeated chars" <<std::endl;
    else std::cout << "String is not unique!!!" <<std::endl;
}

void reverse_string(char* str) {
    size_t length=0;
    size_t i=0;

    while(str[i]!='\0'){ length++; i++; }
    std::cout << "The length is " << length <<std::endl;
    /// initialize index
    size_t j= length-1;
    i= 0;
    size_t bound= length/2;

    while(i< bound) {
        std::swap(str[i], str[j]);
        i++;
        j--;
    }
}

void reverse() {
    char str[]="a";
    reverse_string(str);
    std::cout << "New string " << str << std::endl;
}


#include <iostream>
#include <algorithm>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;


bool operator==(const std::string& str1, const std::string& str2) {
    if(str1.size() != str2.size()) return false;
    
    for(size_t i=0; i< str1.size(); i++) {
        if(str1[i]!= str2[i])return false;
    }
    
    return true;
    
}

bool solution1(std::string& word1, std::string& word2){
    std::sort(word1.begin(), word1.end());
    std::sort(word2.begin(), word2.end());

    return word1==word2;
}


void scan_word(const std::string& str1, std::vector<long int>& dictionary, int incr=1) {
    for(long int i=0;i < str1.size(); i++) {
        //// 97 is the first lowercase a to int in ascii
        long int pos= (long int)str1[i]-97;
        dictionary[pos]+= incr;
    }
}

bool solution2(std::string& word1, std::string& word2) {
    std::vector<long int> dictionary(26,0);

    //// scanword and add counters
    scan_word(word1, dictionary);

    //// scan second word and reduce 
    scan_word(word2, dictionary, -1);

    //// look for zeros or lower than zeros
    for(size_t i=0; i<26; i++) {
        if(dictionary[i]!=0) return false;
    }

    return true;
}

int anagram() {
    //code
    size_t N_TEST=0;
    std::string line, word1, word2;
    std::stringstream ss;

    std::getline(std::cin, line);
    ss.str(line);
    ss >> N_TEST;

    for(size_t i=0; i<N_TEST; i++) {
        std::getline(std::cin, line);
        std::istringstream iss(line);

        iss >> word1;
        iss >> word2;

        //bool solution= solution1(word1, word2);
        bool solution= solution2(word1, word2);
        
        if(solution) {
            std::cout << "YES" <<std::endl;
        } else {
            std::cout << "NO" <<std::endl;
        }
    }

    return 0;
}


void replace_spaces() {
    //code
    size_t N_TEST=0;
    size_t str_length=1;

    std::string str, len;
    std::getline(std::cin, len);
    N_TEST= std::atoi(len.c_str());

    for(size_t t=0; t<N_TEST; t++) {
        std::getline(std::cin, str);
        std::getline(std::cin, len);
        str_length= std::atoi(len.c_str());


        std::cout << "The string: " << str  << " the length: " <<str_length << std::endl; 
        long int space_count=0;
        long int space_before=0;
        long int space_after=0;

        for(size_t ii=0;ii<str.size();ii++)
            if(str[ii]== ' ') space_count++;

        for(size_t ii=0;str[ii]==' ';ii++)
            space_before++;

        for(long int ii= str_length-1;str[ii]==' ';ii--)
            space_after++;

        size_t size=str_length+(space_count-space_before-space_after)*3-space_count;
        std::string new_str(size,'x');

        size_t j=space_before, i=0;
        while(j<str.size()-space_after) {
            //// change space by %20
            if(str[j]==' ') {
                new_str[i]='%';
                new_str[i+1]='2';
                new_str[i+2]='0';
                i+=3;
                j++;
            } else {
                new_str[i]=str[j];
                i++; j++;
            }
        }
        std::cout << new_str << std::endl;
    }
}

void basic_compresion(const std::string& str) {

    std::vector<long int> dictionary(26, 0);
    scan_word(str, dictionary);

    //// how many of the dictionary is not zero
    long int count_non_zero=0;
    std::ostringstream oss;

    size_t i=0, j=0, count;
    char current='x', next='x';
    std::string final_str;

    while(i<str.size()) {
        current= str[i];
        count=1;
        j=i+1;

        while(j<str.size() && current==str[j]) {
            count++;
            j++;
        }

        oss<<current<<std::to_string(count);

        i=j;
    }

    std::cout << oss.str() << std::endl;    

}

int main(int argc, char** argv) {
    basic_compresion("aabcccccaaa");

    return 0;
}



