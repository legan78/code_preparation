#include<iostream>
#include <string>
#include <vector>


using namespace std;

int find_questionmarks(const std::string& str) {
    int n_question_marks=0;
    for(size_t i=0; i< str.size();i++)
        if(str[i]=='?') n_question_marks++;
        
    return n_question_marks;
}

void print_combinations(const std::string& str) {
    // Number of question marks in the array
    int n_var= find_questionmarks(str);
    if(n_var==0) {std::cout << str; return;}
    // Number of combinations to produce
    
    int n_length=2;
    std::vector<int> steps(n_var,1);
    std::vector<bool> values(n_var, false);
    
    for(size_t i=1; i<n_var; i++) {
        steps[i]=steps[i-1]*2;
        n_length*=2;
    }


    for(int i=1; i<=n_length; i++) {
        // Find combination
        // output combination
        for(int j=0, k=n_var-1; j<str.size(); j++) {
            if(str[j]=='?') {
                std::cout<< (int)(values[k--]);
            } else {
                std::cout<< str[j];
            }
        }
        std::cout <<" ";

        for(int v=0; v<n_var; v++) {
            if(i%steps[v]==0) {
                values[v]=!values[v];
            }
        }
    }
}

    


int main()
{
    int t;
    cin>>t;
    while(t--){
        int n;
        std::string str;
        cin >> str;
        print_combinations(str);

    }
    return 0;
}


