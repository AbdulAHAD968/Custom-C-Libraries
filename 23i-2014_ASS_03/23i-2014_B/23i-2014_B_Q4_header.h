#include<iostream>

using namespace std;

//*CUSTOM CLASS.*//
class Matrix{

    private:

        int row;
        int col;
        float* matrix ;         // treat 2_d array as 1-d array.

    public:

        Matrix();                                   // parameter-less constructor.
        Matrix(int, int);                           // parameterized constructor with rows and col.
        Matrix(const Matrix& copy);                 // copy constructor.

        float& operator()(int& row , int& col );    // set the value at particular row and column.

        float& operator()(int& row , int& col ) const;    // set the value at particular row and column for constant obj.

        Matrix& operator=(const Matrix& assign);        // assigns (copies) a matrix and return the SAME.
        bool operator==(const Matrix& comp);          // returns true if and only if the matrix is equal to the given matrix.


        //*some arethematic operations.*//
        Matrix& operator+(const Matrix& add);         // add two matrices.
        Matrix& operator-(const Matrix& sub);         // subtract two matrices.
        Matrix& operator+=(const Matrix& add);        // add and assign two matrices.    
        Matrix& operator-=(const Matrix& sub);        // subtract and assign two matrices.
        Matrix& operator*(const Matrix& mult);        // multiply two matrices.
        Matrix& operator++(int);                      // post increment each element of the matrix.

        ~Matrix();                                    // destructor.            


        //*IO-STREAM FUNCTIONS TO TAKE INPUT AND OUTPUT FOR THE MATRIX.*//

        friend ostream& operator<<(ostream& out, const Matrix& mat);        // for printing output.
        friend istream& operator>>(istream& in, Matrix& mat);               // for taking input.

        //*CONVERSION FUNCTIONS.*//

        operator float* () const;
        operator double* () const;
        operator long double* () const;

        //* reverse conversion constructors.*//
        Matrix(const float* float_matrix, int row , int col);
        Matrix(const double* double_matrix, int row , int col);
        Matrix(const long double* longDouble_matrix, int row , int col);

};


//*ACCESS THE CONVERSION FUNCTIONS.*//
void conversion_functions(Matrix& a_1 , Matrix& a_2 , int row , int col);

//*ACCESS THE REMAINING FUNCTIONS.*//
void remaining_functions(Matrix& arr , Matrix& arr_1 , int row , int col);