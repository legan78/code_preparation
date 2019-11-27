#include <cstdlib>
#include <iostream>


struct Node {
  double data;
  int col, row;
  struct Node *next;

  Node(double x, int i, int j)
  : row(i), col(j), data(x), next(NULL) {
  }

};


class SparseMatrix {
//// Rowmajor matrix
public:

    SparseMatrix(size_t rows, size_t cols)
    : n_rows(rows), n_cols(cols) {
        data= new Node*[n_rows];
        for(size_t i=0; i<n_cols; i++) data[i]= NULL;
    }


    double at(long int i, long int j) const {
        if(data[i]==NULL) return 0;

        Node* row= data[i];

        while(row!=NULL) {
            /// we have found the node
            if(row->col==j) 
                return row->data;
            row= row->next;
        }

        return 0.0;
    }

    void set(double x, long int i, long int j) {
        //// no data in this row
        if(data[i]==NULL) {
            data[i]= new Node(x, i, j);
        //// there is already data in this row, search where to set
        } else {
            Node* row= data[i];
            Node* prev=row;
            size_t ob_j=0;

            //// the data is in the first node
            if(prev->col==j) {
                prev->data=x;
            } else {
                //// search for j or the inmediate previous
                while(prev->next!=NULL) {
                    //// the data was filled previously
                    if(prev->next->col==j)
                        break;
                    //// there is no cell
                    else if(prev->next->col>j)
                        break;

                    prev=prev->next;
                }

                //// Set the value
                Node* tmp= prev->next;
                //// In case the cell wasnt filled previously
                if(prev->next==NULL)
                    prev->next= new Node(x,i,j);
                prev->next->next= tmp;
            }
        }
    }


    SparseMatrix operator+(const SparseMatrix& mat1, const SparseMatrix& mat2) {
        SparseMatrix sum(mat.get_n_rows(), mat.get_n_cols());


        


        return sum;
    }


    size_t get_n_cols()const{return n_cols;}
    size_t get_n_rows()const{return n_rows;}

private:

    Node** data;
    size_t n_rows;
    size_t n_cols;

};



std::ostream& operator<<(std::ostream& os, const SparseMatrix& mat) {

    for(size_t i=0; i<mat.get_n_rows(); i++) {
        for(size_t j=0; j<mat.get_n_cols(); j++) {
            os << mat.at(i,j) << "\t";
        }
        os << std::endl;
    }


    return os;
}


int main() {

    SparseMatrix mat(3,3);

    mat.set(-1, 1,1);

    std::cout << mat;


    for(size_t i=0, k=0; i<3; i++)
        for(size_t j=0; j<3; j++,k++)
            mat.set(k,i,j); 

    std::cout << mat;



    return 0;
}










