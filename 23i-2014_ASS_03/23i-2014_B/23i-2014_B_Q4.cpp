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


//*CONSTRUCTORS FOR THE CLAS OBJECTS.*//

//*parameter-less constructor.*//
Matrix::Matrix(){
    this->row = 0;
    this->col = 0;
    this->matrix = nullptr;
}

//*parametrized constructor.*//
Matrix::Matrix(int row, int col){
    this->row = row;
    this->col = col;
    this->matrix = new float[row*col];
}

//*copy sonctructor.*//
Matrix::Matrix(const Matrix& copy){

    this->row = copy.row;
    this->col = copy.col;

    this->matrix = new float[this->row*this->col];          // deep copying.

    for(int i=0 ; i<row ; i++){
        for(int j=0 ; j<col ; j++){
            *(this->matrix + i*col + j) = *(copy.matrix + i*col + j);
        }
    }
}


//*set the value at the particular index of the array for non constant object.*//
float& Matrix::operator()(int& row, int& col) {
    return this->matrix[row*this->col + col];       // returning reference to the element by calculating the index.
}



//*set the value at the particular index of the array for constant object.*//
float& Matrix::operator()(int& row, int& col) const {
    return this->matrix[row*this->col + col];       // returning reference to the element by calculating the index.
}


//*ASSIGNS ONE OBJECT TO OTHER.*//
Matrix& Matrix::operator=(const Matrix& assign){

    if(*this==assign){
        cout<<"\nTHE OBJECT IS ALREADY BEING POINTED. [SELF-ASSIGNMENT_CASE] \n";
        return *this;       // is the obj. is already being pointed to it-self.
    }

    this->row = assign.row;
    this->col = assign.col;

    delete []matrix;           // avoid memory leaks.
    this->matrix = new float[this->row*this->col];          // deep copying.

    for(int i=0 ; i<row ; i++){
        for(int j=0 ; j<col ; j++){
            *(this->matrix + i*col + j) = *(assign.matrix + i*col + j);
        }
    }

return *this;
}


//*check is the two matrix are equal or not.*//
bool Matrix::operator==(const Matrix& comp){

    if( (this->row != comp.row) || (this->col != comp.col) ){
        return false;
    }
    
    for(int i=0 ; i<row ; i++){
        for(int j=0 ; j<col ; j++){
            if(*(this->matrix + i*col + j) != *(comp.matrix + i*col + j)){
                return false;
            }        
        }
    }

return true;        // if equal.
}


//*ADD TWO MATRIXES.*//
Matrix& Matrix::operator+(const Matrix& add){
    
    if( (this->row != add.row) || (this->col != add.col) ){
        cerr<<"\nWE CANNOT PERMORM ADDITION ON MATRIXE'S WITH UN-EQUAL DIMENSINS. \n";
        return *this;
    }

    for(int i=0 ; i<row ; i++){
        for(int j=0 ; j<col ; j++){
            *(this->matrix + i*col + j) = *(this->matrix + i*col + j) + *(add.matrix + i*col + j);       
        }
    }

return *this;
}


//*SUBTRACT TWO MATRIXES.*//
Matrix& Matrix::operator-(const Matrix& sub){
    
    if( (this->row != sub.row) || (this->col != sub.col) ){
        cerr<<"\nWE CANNOT PERMORM ADDITION ON MATRIXE'S WITH UN-EQUAL DIMENSINS. \n";
        return *this;
    }

    for(int i=0 ; i<row ; i++){
        for(int j=0 ; j<col ; j++){
            *(this->matrix + i*col + j) = *(this->matrix + i*col + j) - *(sub.matrix + i*col + j);       
        }
    }

return *this;
}


//*MULTIPLY TWO MATRIXES.*//
Matrix& Matrix::operator*(const Matrix& mult){
    
    if(this->col != mult.row){
        cerr<<"\nMATRIX IS NOT FEASIBLE FOR MULTIPLICATION. THANKS. \n";
        return *this;
    }

    Matrix result(this->row , mult.col);
    
    for(int i=0 ; i<this->row ; i++){
        for(int j=0 ; j<mult.col ; j++)
        {
            for(int k=0 ; k<this->col ; k++)
            {
                result.matrix[i*mult.col + j] += this->matrix[i*this->col + k] * mult.matrix[k*mult.col + j];
                //result[i][j] += this->matrix[i][k] * mult.matrix[k][j];
            }
        }
    }
    *this = result;         // copy the result matrix.


return *this;
}

//*POST-INCREMENT OPERATOR.*//
Matrix& Matrix::operator++(int){

    for(int i=0 ; i<row ; i++){
        for(int j=0 ; j<col ; j++){
            *(this->matrix + i*col + j) = *(this->matrix + i*col + j) + 1;
        }
    }

return *this;
}

//*ADD AND ASSIGN TWO MATRIXES.*//
Matrix& Matrix::operator+=(const Matrix& add){
    
    if( (this->row != add.row) || (this->col != add.col) ){
        cerr<<"\nWE CANNOT PERMORM ADDITION ON MATRIXE'S WITH UN-EQUAL DIMENSINS. \n";
        return *this;
    }

    for(int i=0 ; i<row ; i++){
        for(int j=0 ; j<col ; j++){
            *(this->matrix + i*col + j) += *(add.matrix + i*col + j);       
        }
    }

return *this;
}

//*SUBTRACT AND ASSIGN TWO MATRIXES.*//
Matrix& Matrix::operator-=(const Matrix& sub){
    
    if( (this->row != sub.row) || (this->col != sub.col) ){
        cerr<<"\nWE CANNOT PERMORM ADDITION ON MATRIXE'S WITH UN-EQUAL DIMENSINS. \n";
        return *this;
    }

    for(int i=0 ; i<row ; i++){
        for(int j=0 ; j<col ; j++){
            *(this->matrix + i*col + j) -= *(sub.matrix + i*col + j);       
        }
    }

return *this;
}


//*O-STREAM FUNCTIONS PRINT OUTPUT FOR THE MATRIX.*//
ostream& operator<<(ostream& out , const Matrix& mat){

    cout<<"\n THE MATRIX IS SHOWN BELOW. \n"<<endl;

    for(int i=0 ; i<mat.row ; i++){
        for(int j=0 ; j<mat.col ; j++){
            out<<mat.matrix[i*mat.col + j]<<"\t";
        }
        out<<endl;
    }
}

//*I-STREAM FUNCTIONS TO TAKE INPUT FOR THE MATRIX.*//
istream& operator>>(istream& in, Matrix& mat){

    cout<<"\n FEED THE ROWS AND COL OF THE MATRIX. \n"<<endl;
    
    for(int i=0 ; i<mat.row ; i++){
        for(int j=0 ; j<mat.col ; j++){
            in>>mat.matrix[i*mat.col + j];
        }
    }
}

//*DESTRUCTOR.*//
Matrix::~Matrix(){
    delete[] matrix;
    matrix = nullptr;
}

//*CONVERSION FUNCTIONS.*//

//*int to float conversion.*//
Matrix::operator float* () const{

    float* f_array = new float[row*col];
    for(int i=0 ; i<row ; i++){
        for(int j=0 ; j<col ; j++){
            f_array[i*col + j] = static_cast<float>(matrix[i*col + j]);
        }
    }

    cout<<"\n THE CONVERTED [FLOAT ARRAY] IS = \n";
    for(int i=0 ; i<row ; i++){
        for(int j=0 ; j<col ; j++){
            cout<<f_array[i*col + j]<<"\t";
        }
        cout<<endl;
    }
    cout<<endl;

return f_array;
}


//*int to double conversion.*//
Matrix::operator double* () const{
    double* d_array = new double[row*col];
    for(int i=0 ; i<row ; i++){
        for(int j=0 ; j<col ; j++){
            d_array[i*col + j] = static_cast<double>(matrix[i*col + j]);
        }
    }

    cout<<"\n THE CONVERTED [DOUBLE ARRAY] IS = \n";
    for(int i=0 ; i<row ; i++){
        for(int j=0 ; j<col ; j++){
            cout<<d_array[i*col + j]<<"   ";
        }
        cout<<endl;
    }
    cout<<endl;

return d_array;
}


//*int to long double conversion.*//
Matrix::operator long double* () const{
    long double* ld_array = new long double[row*col];
    for(int i=0 ; i<row ; i++){
        for(int j=0 ; j<col ; j++){
            ld_array[i*col + j] = static_cast<long double>(matrix[i*col + j]);
        }
    }

    cout<<"\n THE CONVERTED [LONG DOUBLE ARRAY] IS = \n";
    for(int i=0 ; i<row ; i++){
        for(int j=0 ; j<col ; j++){
            cout<<ld_array[i*col + j]<<"   ";
        }
        cout<<endl;
    }
    cout<<endl;

return ld_array;
}


//*reverse conversion functions.*//

//*float to int conversion.*//
Matrix::Matrix(const float* float_array, int row , int col){
    this->row = row;
    this->col = col;
    this->matrix = new float[row * col];
    for(int i=0 ; i<row ; i++){
        for(int j=0 ; j<col ; j++){
            this->matrix[i*col + j] = static_cast<int>( float_array[i*col + j] );
        }
    }

    cout<<"\n THE CONVERTED MATRIX IS  =  \n";
    for(int i=0 ; i<row ; i++){
        for(int j=0 ; j<col ; j++){
            cout<<this->matrix[i*col + j]<<"    ";
        }
        cout<<endl;
    }
    cout<<endl;

    // as it is a constructor,therefore no return.
}

//*double to int conversion.*//
Matrix::Matrix(const double* double_array, int row , int col){
    this->row = row;
    this->col = col;
    this->matrix = new float[row * col];
    for(int i=0 ; i<row ; i++){
        for(int j=0 ; j<col ; j++){
            this->matrix[i*col + j] = static_cast<int>( double_array[i*col + j] );
        }
    }

    cout<<"\n THE CONVERTED MATRIX IS  =  \n";
    for(int i=0 ; i<row ; i++){
        for(int j=0 ; j<col ; j++){
            cout<<this->matrix[i*col + j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;

    // as it is a constructor,therefore no return.
}

//*long double to int conversion.*//
Matrix::Matrix(const long double* longDouble_Arr, int row , int col){
    this->row = row;
    this->col = col;
    this->matrix = new float[row * col];
    for(int i=0 ; i<row ; i++){
        for(int j=0 ; j<col ; j++){
            this->matrix[i*col + j] = static_cast<int>( longDouble_Arr[i*col + j] );
        }
    }

    cout<<"\n THE CONVERTED MATRIX IS  =  \n";
    for(int i=0 ; i<row ; i++){
        for(int j=0 ; j<col ; j++){
            cout<<this->matrix[i*col + j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;

    // as it is a constructor,therefore no return.
}


//*ACCESS THE CONVERSION FUNCTIONS.*//
void conversion_functions(Matrix& a_1 , Matrix& a_2 , int row , int col);

//*ACCESS THE REMAINING FUNCTIONS.*//
void remaining_functions(Matrix& arr , Matrix& arr_1 , int row , int col);

//*MAIN FUNCTION.*//
int main(){
    
    int row,col;
    cout<<"\nENTER THE NUMBER OF ROWS. [TRY TO KEEP SYMMETRY PLEASE.]";
    cin>>row;
    while(row<0){
        cout<<"\nTRY AGAIN. ENTER THE [+VE] NUMBER OF ROWS.";
        cin>>row;
    }
    cout<<"\nENTER THE NUMBER OF COLUMNS. [TRY TO KEEP SYMMETRY PLEASE.]";
    cin>>col;
    while(col<0){
        cout<<"\nTRY AGAIN. ENTER THE [+VE] NUMBER OF COLUMNS.";
        cin>>col;
    }

    Matrix mat_1(row,col);
    cin>>mat_1;
    cout<<mat_1;

    ////////////////////////////////

    cout<<"\n ENTER DATA FOR THE OTHER OBJECT [TO BE OVERLOADED]. \n";
    cout<<"\nENTER THE NUMBER OF ROWS. [TRY TO KEEP SYMMETRY PLEASE.]";
    cin>>row;
    while(row<0){
        cout<<"\nTRY AGAIN. ENTER THE [+VE] NUMBER OF ROWS.";
        cin>>row;
    }
    cout<<"\nENTER THE NUMBER OF COLUMNS. [TRY TO KEEP SYMMETRY PLEASE.]";
    cin>>col;
    while(col<0){
        cout<<"\nTRY AGAIN. ENTER THE [+VE] NUMBER OF COLUMNS.";
        cin>>col;
    }

    Matrix mat_2(row, col);
    cin>>mat_2;
    cout<<mat_2;

    ////////////////////////////////

    while(true){

        int sup_choice;
        cout<<"\n [1]. VIEW THE CONVERSION FUNCTIONS. ";
        cout<<"\n [2]. VIEW THE REMAINING [OVERLOAD] FUNCTIONS. ";
        cout<<"\n [0]. {!!!---EXIT---!!!}."<<endl;
        cout<<"\n\t {ENTER YOUR CHOICE} :: ";
        cin>>sup_choice;

        switch(sup_choice){
            case 1:
            {
                conversion_functions(mat_1 , mat_2 , row , col);
            break;
            }
            case 2:
            {
                remaining_functions(mat_1 , mat_2 , row , col);

            break;
            }
            case 0:
            {
                cout<<"\n {!!!---EXITING THE PROGRAM---!!!}"<<endl;
                return 0;
            }
            default:
            {
                cout<<"\n INVALID CHOICE!!!"<<endl;
            break;
            }
        }//switch
    }//loop[]


return 0;
}

//*ACCESS THE CONVERSION FUNCTIONS.*//
void conversion_functions(Matrix& a_1 , Matrix& a_2 , int row , int col){
    while(true){

        int choice;
        cout<<"\n [1]. FLOAT TO INT. ";
        cout<<"\n [2]. DOUBLE TO INT. ";
        cout<<"\n [3]. LONG DOUBLE TO INT. ";
        cout<<"\n [4]. INT TO FLOAT. ";
        cout<<"\n [5]. INT TO DOUBLE. ";
        cout<<"\n [6]. INT TO LONG DOUBLE. ";
        cout<<"\n [0]. {!!!---EXIT---!!!}."<<endl;
        cout<<"\n\t {ENTER YOUR CHOICE} :: ";
        cin>>choice;

        switch(choice){
            case 1:
            {
                int row,col;
                cout<<"\nENTER THE ROWS OF THE MATRIX.\n";
                cin>>row;
                cout<<"\nENTER THE COLUMN OF THE MATRIX.\n";
                cin>>col;
                float* float_array = new float[row*col];
                cout<<"\nENTER THE ELEMENTS OF THE ARRAY [FLOATING ARRAY]\n";
                for(int i=0 ; i<row ; i++){
                    for(int j=0 ; j<col ; j++){
                        cin>>float_array[i*col + j];
                    }
                }
                Matrix float_arr(float_array, row, col);

                delete [] float_array;
                float_array = nullptr;
            
            break;
            }
            case 2:
            {
                int row,col;
                cout<<"\nENTER THE ROWS OF THE MATRIX.\n";
                cin>>row;
                cout<<"\nENTER THE COLUMN OF THE MATRIX.\n";
                cin>>col;
                double* double_array = new double[row*col];
                cout<<"\nENTER THE ELEMENTS OF THE ARRAY [DOUBLEING ARRAY]\n";
                for(int i=0 ; i<row ; i++){
                    for(int j=0 ; j<col ; j++){
                        cin>>double_array[i*col + j];
                    }
                }
                Matrix double_arr(double_array, row, col);

                delete [] double_array;
                double_array = NULL;

            break;
            }
            case 3:
            {
                int row,col;
                cout<<"\nENTER THE ROWS OF THE MATRIX.\n";
                cin>>row;
                cout<<"\nENTER THE COLUMN OF THE MATRIX.\n";
                cin>>col;
                long double* long_double_array = new long double[row*col];
                cout<<"\nENTER THE ELEMENTS OF THE ARRAY [LONG DOUBLEING ARRAY]\n";
                for(int i=0 ; i<row ; i++){
                    for(int j=0 ; j<col ; j++){
                        cin>>long_double_array[i*col + j];
                    }
                }
                Matrix long_double_arr(long_double_array, row, col);

                delete [] long_double_array;
                long_double_array = NULL;

            break;
            }
            case 4:
            {
                float* f_array;
                cout<<"\n THE ARRAY AFTER [INT] TO [FLOAT] CONVERSION.\n";
                f_array = a_1;

                delete f_array;
                f_array = nullptr;

            break;               
            }
            case 5:
            {
                double* d_array;
                cout<<"\n THE ARRAY AFTER [INT] TO [DOUBLE] CONVERSION.\n";
                d_array = a_1;

                delete d_array;
                d_array = nullptr;

            break;
            }
            case 6:
            {
                long double* ld_array;
                cout<<"\n THE ARRAY AFTER [INT] TO [LONG DOUBLE] CONVERSION.\n";
                ld_array = a_1;

                delete ld_array;
                ld_array = nullptr;

            break;
            }
            case 0:
            {
                cout<<"\n {!!!---RETURNING TO MAIN---!!!}"<<endl;
                return;
            }
            default:
            {
                cout<<"\n INVALID CHOICE!!!"<<endl;
            break;
            }

        }//end switch

    }//end loop
}


//*ACCESS THE REMAINING FUNCTIONS.*//
void remaining_functions(Matrix& mat_1 , Matrix& mat_2 , int row , int col){
    
    while(true){

        int choice;
        cout<<"\n WHAT OPERATION YOU WANT TO PERFORM <?> ";
        cout<<"\n [1].  USE THE COPY CONSTRUCTOR.";
        cout<<"\n [2].  USE THE ASSIGNMENT OPERATOR.";
        cout<<"\n [3].  USE THE ADDITION OPERATOR.";
        cout<<"\n [4].  USE THE SUBTRACTION OPERATOR.";
        cout<<"\n [5].  USE THE MULTIPLICATION OPERATOR.";
        cout<<"\n [6].  USE THE POST-INCREMENT OPERATOR.";
        cout<<"\n [7].  USE THE ADDITION AND ASSIGNMENT OPERATOR.";
        cout<<"\n [8].  USE THE SUBTRACTION AND ASSIGNMENT OPERATOR.";
        cout<<"\n [9].  SET VALUE AT [ROW] & [C0L] FOR {NON-CONSTANT} OBJECT.";
        cout<<"\n [10]. SET VALUE AT [ROW] & [C0L] FOR {CONSTANT} OBJECT.";
        cout<<"\n [0].  EXIT THE PROGRAM.";
        cout<<"\n           [ ENTER YOUR CHOICE ]. \n";
        cin>>choice;

        switch(choice){
            case 1:
            {
                cout<<"\n MAKING A NEW OBJ. AND COPYING THE [OBJ_01] \n";
                Matrix mat_3(mat_1);
                cout<<mat_3;

            break;
            }
            case 2:
            {
                cout<<"\n ASSIGNING THE [OBJ_02] TO [OBJ_1]. \n";
                cout<<"\n [OBJ_1] BEFORE ASSIGNING. \n";
                cout<<mat_1;

                mat_1 = mat_2;
                cout<<"\n [OBJ_1] AFTER ASSIGNING. \n";
                cout<<mat_1;

            break;
            }
            case 3:
            {
                cout<<"\n ADDING THE [OBJ_02] TO [OBJ_1]. \n";
                cout<<"\n [OBJ_1] BEFORE ADDING. \n";
                cout<<mat_1;

                mat_1 = mat_1 + mat_2;
                cout<<"\n [OBJ_1] AFTER ADDING. \n";
                cout<<mat_1;

            break;
            }
            case 4:
            {
                cout<<"\n SUBTRACTING THE [OBJ_02] FROM [OBJ_1]. \n";
                cout<<"\n [OBJ_1] BEFORE SUBTRACTING. \n";
                cout<<mat_1;

                mat_1 = mat_1 - mat_2;
                cout<<"\n [OBJ_1] AFTER SUBTRACTING. \n";
                cout<<mat_1;

            break;
            }
            case 5:
            {
                cout<<"\n MULTIPLYING THE [OBJ_02] BY [OBJ_1]. \n";
                cout<<"\n [OBJ_1] BEFORE MULTIPLYING. \n";
                cout<<mat_1;

                mat_1 = mat_1 * mat_2;
                cout<<"\n [OBJ_1] AFTER MULTIPLYING. \n";
                cout<<mat_1;

            break;
            }
            case 6:
            {
                cout<<"\n POST-INCREMENTING THE [OBJ_1]. \n";
                cout<<"\n [OBJ_1] BEFORE POST-INCREMENTING. \n";
                cout<<mat_1;

                mat_1++;
                cout<<"\n [OBJ_1] AFTER POST-INCREMENTING. \n";
                cout<<mat_1;

            break;
            }
            case 7:
            {
                cout<<"\n ADDING AND ASSIGNING THE [OBJ_02] TO [OBJ_1]. \n";
                cout<<"\n [OBJ_1] BEFORE ADDING. \n";
                cout<<mat_1;

                mat_1 += mat_2;
                cout<<"\n [OBJ_1] AFTER ADDING. \n";
                cout<<mat_1;

            break;
            }
            case 8:
            {
                cout<<"\n SUBTRACTING AND ASSIGNING THE [OBJ_02] FROM [OBJ_1]. \n";
                cout<<"\n [OBJ_1] BEFORE SUBTRACTING. \n";
                cout<<mat_1;

                mat_1 -= mat_2;
                cout<<"\n [OBJ_1] AFTER SUBTRACTING. \n";
                cout<<mat_1;

            break;
            }
            case 9:
            {
                int value;
                int* row_col = new int[2];
                cout<<"\n ENTER THE ROW. ";
                cin>>row_col[0];
                while(row_col[0]<0 || row_col[0]>=row){
                    cout<<"\nTRY AGAIN. ENTER THE [+VE] ROW [within range].";
                    cin>>row_col[0];
                }
                
                cout<<"\n ENTER THE COL. ";
                cin>>row_col[1];
                while(row_col[1]<0 || row_col[1]>=col){
                    cout<<"\nTRY AGAIN. ENTER THE [+VE] COL [within range].";
                    cin>>row_col[1];
                }
                
                cout<<"\n ENTER THE VALUE. ";
                cin>>value;
                
                cout<<"\n SET VALUE AT [ROW] & [C0L] FOR {NON-CONSTANT} OBJECT. \n";
                cout<<"\n [OBJ_1] BEFORE SETTING VALUE. \n";
                cout<<mat_1;

                mat_1(row_col[0], row_col[1]) = value;

                cout<<"\n [OBJ_1] AFTER SETTING VALUE. \n";
                cout<<mat_1;

                delete [] row_col;      // delete
                row_col = NULL;         // undangle

            break;
            }
            case 10:
            {
                cout<<"\n FIRST WE COPIED THE DATA OF [1st] MATRIX IN THE CONSTANT MATRIX. \n";   
                const Matrix mat_su(mat_1);
                
                int value;
                int* row_col = new int[2];
                cout<<"\n ENTER THE ROW. ";
                cin>>row_col[0];
                while(row_col[0]<0 || row_col[0]>row){
                    cout<<"\nTRY AGAIN. ENTER THE [+VE] ROW [within range].";
                    cin>>row_col[0];
                }
                
                cout<<"\n ENTER THE COL. ";
                cin>>row_col[1];
                while(row_col[1]<0 || row_col[1]>col){
                    cout<<"\nTRY AGAIN. ENTER THE [+VE] COL [within range].";
                    cin>>row_col[1];
                }
                
                cout<<"\n ENTER THE VALUE. ";
                cin>>value;
                
                cout<<"\n SET VALUE AT [ROW] & [C0L] FOR {CONSTANT} OBJECT. \n";
                cout<<"\n [OBJ_1] BEFORE SETTING VALUE. \n";
                cout<<mat_su;

                mat_su(row_col[0], row_col[1]) = value;

                cout<<"\n [OBJ_1] AFTER SETTING VALUE. \n";
                cout<<mat_su;

                delete [] row_col;      // delete
                row_col = NULL;         // undangle

            break;
            }
            case 0:
            {
                cout<<"\n {!!!---RETURNING TO MAIN---!!!}"<<endl;
                return;
            }
            default:
            {
                cout<<"\n INVALID CHOICE. TRY AGAIN. \n";
            break;
            }

        }//switch.

    }//loop.

}