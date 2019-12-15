#include <vector>
#include <iostream>
#include <stack>
#include <random>
#include <chrono>

typedef std::stack<int, std::vector<int> > my_stack;

class StackOfStacks {
public:
  StackOfStacks(int s_capacity):
  stack_capacity(s_capacity),
  current_stack(0){ 
    // the_stack.push_back(my_stack());
  }

  void push(int number) {
      if(the_stack.size()==0) {
          the_stack.push_back(my_stack());
          current_stack=0;
      }

      if(the_stack[current_stack].size() == stack_capacity) {
          current_stack++;
          the_stack.push_back(my_stack());
      }

      std::cout << "Pushing in stack: " 
                << current_stack 
                << std::endl;
      the_stack[current_stack].push(number);
  }

  void pop() {
      if(the_stack.size()==0) return; // empty stack

      if(the_stack[current_stack].size()==0) {
          the_stack.pop_back();
          current_stack= std::max<int>(0, current_stack-1);
      }

      int top= the_stack[current_stack].top();
      the_stack[current_stack].pop();

      std::cout << "Poping out: " << top << std::endl;
  }

  int size() {
      int s=0;
      for(size_t i=0; i< the_stack.size(); i++) {
          s+= the_stack[i].size();
      }

      return s;
  }

private:
    size_t stack_capacity;
    size_t current_stack;

    std::vector<my_stack> the_stack;
};


void problem1() {
    StackOfStacks lots_of_stacks(5);

    for(size_t i=0; i<50; i++) {
        lots_of_stacks.push(i);
    }

    std::cout << "Poping out!!!!!!!! " << std::endl;

    while(lots_of_stacks.size()>0) {
        lots_of_stacks.pop();
    }

}

typedef std::stack<int, std::vector<int> > mystack;

void print_stack(const mystack& st, const char* name) {
    mystack tmp= st;
    std::cout << name << " ";
    while(!tmp.empty()) {
        std::cout << tmp.top() << " "; 
        tmp.pop();
    }
}

void hanoi(int n, mystack& src, mystack& dst, mystack& aux) {
    if(n>0) {
        hanoi(n-1, src, aux, dst);
        int the_n= src.top();
        src.pop();
        dst.push(the_n);

        hanoi(n-1, aux, dst, src);
    }
}




int stack_exe() {

    mystack src, tmp, dst;


    for(int i=11; i>0; i--) {
        src.push(i);
    }

    print_stack(src, "src"); 
    std::cout << std::endl;
    print_stack(tmp, "tmp"); 
    std::cout << std::endl;
    print_stack(dst, "dst"); 
    std::cout << std::endl;

    hanoi(11, src, dst, tmp);

    print_stack(src, "src"); 
    std::cout << std::endl;
    print_stack(tmp, "tmp"); 
    std::cout << std::endl;
    print_stack(dst, "dst"); 
    std::cout << std::endl;

    return 0;
}


std::ostream& operator<<(std::ostream& os, const mystack& st) {
    my_stack other= st;

    while(!other.empty()) {
        os << other.top() << " ";
        other.pop();
    }
    return os;
}


int main() {

    my_stack src, dst;
    std::default_random_engine
          generator(std::chrono::system_clock::now().time_since_epoch().count());
    std::uniform_int_distribution<int> distribution(0,100);
    for(size_t i=0; i<10; i++) {
        int then= distribution(generator);
        src.push(then);
    }

    my_stack original= src;
    //std::cout << src.size() << std::endl;
    // std::cout << src << std::endl;

    while(!src.empty()) {
        int src_nm= src.top();
        int c_size= src.size();
        src.pop();

        /// find the place where to place src_nm
        while(!dst.empty() && dst.top()> src_nm) {
            src.push(dst.top());
            dst.pop();
        }

        /// push the number on destiny
        dst.push(src_nm);

        /// return previous to dst
        while(src.size()>c_size) {
            dst.push(src.top());
            src.pop();
        }
        
        //std::cout << "+++++++++++" << std::endl;
        //std::cout << "Src: "<< src << std::endl;
        //std::cout << "Dst: "<< dst << std::endl;
        //std::getchar();
    }

    std::cout << "Original: " << original << std::endl;
    std::cout << "Dst:      " << dst      << std::endl;
}



















