#include<iostream>
#include<cstdlib>
#include<ctime>

using namespace std;

//*CUSTOM CLASS.*//
class Array{

    private:

        int *arr;
        int size;

    public:

        int get_size();

        Array();                                // a default constructor.
        Array(int size);                        // a constructor with one parameter of size.
        Array(int* arr , int size);             // initiallize the array with an existing array.

        Array(const Array& obj_passed);         // a copy constructor.

        int& operator[] (int index);            // returns the integer at the specified index.[check out_of_range error]

        int& operator[](int index)const;        // returns the integer at the specified index

        const Array& operator=(const Array& );        // copies the array

        //*ARITHEMATIC OPERATORS.*//

        Array operator+(const Array& obj_passed);      // adds the two arrays.
        Array operator-(const Array& obj_passed);      // subtracts the two arrays.
        Array operator++();                             // pre-incriment operator.
        Array operator--();                             // pre-decriment operator.
        Array operator++(int);                          // post-incriment operator.
        Array operator--(int);                          // post-decriment operator.

        //*COMPARISON OPERATORS.*//

        bool operator==(const Array& obj_passed) const;         // compares the two arrays.
        bool operator!();                                       // returns true if the two arrays not are equal
        void operator+=(const Array& obj_passed);               // adds the two arrays
        void operator-=(const Array& obj_passed);               // subtracts the two arrays.
        int operator() (int index , int val);               // remove the value at the index and then shifts the 
                                                            // array to the left. return 1 if operation was successful. else [-1]

        //*DESTRUCTOR*//
        ~Array();

        //*FRIEND FUNCTIONS OF IO-STREAM.*//
        friend ostream& operator<<(ostream& out_put , const Array& obj);       // print result.
        friend istream& operator>>(istream& in_put , Array& obj);              // take input


        //*CONVERSION FUNCTIONS.*//
        operator float* () const;
        operator double* () const;
        operator long double* () const;

        //* reverse conversion constructors.*//
        Array(const float* float_array, int size);
        Array(const double* double_array, int size);
        Array(const long double* longDouble_Arr, int size);

};



//*CONSTRUCTORS OF THE CLASS.*//

//*parameterless constructor.*//
Array::Array(){
    size = 0;
    arr = NULL;
}

//*parameterized constructor.*//
Array::Array(int size){
    this->size = size;
    arr = new int[size];
}

//*copy constructor.*//
Array::Array(const Array& obj_passed){
    size = obj_passed.size;
    this->arr = new int[size];      //deep copying.
    for(int i = 0; i < size; i++){
        this->arr[i] = obj_passed.arr[i];
    }
}

//*copies tha array object with assignment operator.*//
const Array& Array::operator=(const Array& obj){
    if(this!= &obj){        // in case if this-> was pointing to the same object.
        
        delete[] arr;       // delete to prevent memory leak.*/
        size = obj.size;
        arr = new int[size];        // reallocate the memory to array.

        for(int i = 0; i < size; i++){
            arr[i] = obj.arr[i];
        }
    }

return *this;
}

//*GETTER FUNSTION FOR SIZE OF THE ARRAY WITH REFERNECE TO THE OBJECT.*//  ===> EXTRACT FUN.
int Array::get_size(){
    return size;
}

//*GETTER FUNSTION FOR THE VALUE AT THE INDEX WITH REFERNECE TO THE OBJECT.*//

//*get integer at a specific index.*//
int& Array::operator[] (int index){
    if(index < 0 || index >= size){
        cerr<<"\nTHE INEDX IS OUT_OF_RANGE."<<endl;
    }
    else{
        return arr[index];
    }
}

//*get integer at a specific index.[CONST]*//
int& Array::operator[](int index)const{
    if(index < 0 || index >= size){
        cerr<<"\nTHE INEDX IS OUT_OF_RANGE."<<endl;
    }
    else{
        return arr[index];
    }
}

//*add two arrays.*//
Array Array::operator+(const Array& obj_passed){
    
    if(this->size > obj_passed.size){
        Array temp(this->size);
        for(int i = 0; i < this->size; i++){
            temp[i] = this->arr[i] + obj_passed.arr[i];
        }
        return temp;

    }else if(this->size < obj_passed.size){
        Array temp(obj_passed.size);
        
        for(int i = 0; i < obj_passed.size; i++){
            temp[i] = this->arr[i] + obj_passed.arr[i];
        }
        return temp;
    
    }else if(this->size==obj_passed.size){
        Array obj_result(this->size);
    
        for(int i = 0; i < this->size; i++){
            obj_result.arr[i] = this->arr[i] + obj_passed.arr[i];
        }
        
        return obj_result;
    }
}

//*subtracts two arrays.*//
Array Array::operator-(const Array& obj_passed){
    
    if(this->size > obj_passed.size){
        Array temp(this->size);
        for(int i = 0; i < this->size; i++){
            temp[i] = this->arr[i] - obj_passed.arr[i];
        }
        return temp;

    }else if(this->size < obj_passed.size){
        Array temp(obj_passed.size);
        
        for(int i = 0; i < obj_passed.size; i++){
            temp[i] = this->arr[i] - obj_passed.arr[i];
        }
        return temp;
    
    }else if(this->size==obj_passed.size){
        Array obj_result(this->size);
    
        for(int i = 0; i < size; i++){
            obj_result.arr[i] = this->arr[i] - obj_passed.arr[i];
        }
        
        return obj_result;
    }
}

//*pre-increment operator.*//
Array Array::operator++(){
    cout<<"\n THE ARRAY AFTER [PRE] INCREMENTING IS = \n";
    for(int i=0 ; i<this->size ; i++){
        this->arr[i]++;       // incriment +1 at each index of the array.
    }
    return *this;
}

//*pre-decrement operator.*//
Array Array::operator--(){
    cout<<"\n THE ARRAY AFTER [PRE] DECREMENTING IS = \n";
    for(int i=0 ; i<this->size ; i++){
        this->arr[i]--;       // decriment -1 at each index of the array.
    }
    return *this;
}

//*post-increment operator.*//
Array Array::operator++(int){
    cout<<"\n THE ARRAY AFTER [POST] INCREMENTING IS = \n";
    Array temp(*this);
    for(int i=0 ; i<this->size ; i++){
        this->arr[i]++;       // incriment +1 at each index of the array.
    }
    return temp;
}

//*post-decrement operator.*//
Array Array::operator--(int){
    cout<<"\n THE ARRAY AFTER [POST] DECREMENTING IS = \n";
    Array temp(*this);
    for(int i=0 ; i<this->size ; i++){
        this->arr[i]--;       // decriment -1 at each index of the array.
    }
    return temp;
}

//*compares the two arrays.*//
bool Array::operator==(const Array& obj_passed) const{
    if(this->size!= obj_passed.size){
        return false;       // if the size don't match simply return false.
    }
    // else case is to map element by element.

    for(int i = 0; i < this->size; i++){
        if(this->arr[i]!= obj_passed.arr[i]){
            return false;
        }
    }
    return true;
}

//*compares the two arrays.*//
bool Array::operator!(){
    for(int i=0 ; i<this->size ; i++){
        if(this->arr[i]!= 0){
            return false;       //return false if the array is not empty
        }
    }
    return true;        //return true if the array is empty.
}

//*add two arrays and assigns it to the other one.*//
void Array::operator+=(const Array& obj_passed){

    int re_size=0;
    if(this->size > obj_passed.size){
        re_size = obj_passed.size;      // getting the least size.
    }else{
        re_size = this->size;
    }

    if(this->size == obj_passed.size){
        for(int i=0 ; i<size ; i++){
            this->arr[i] += obj_passed.arr[i];
        }
    }
    else{
        cout<<"\nTHE SIZE IS NOT SAME. SO COPYING UPTO LOWER SIZE."<<endl;
        for(int i=0 ; i<re_size ; i++){
            this->arr[i] += obj_passed.arr[i];      // but it will add only within the limit.
        }
    }

}

//*subtract two arrays and assigns it to the other one.*//
void Array::operator-=(const Array& obj_passed){

    int re_size=0;
    if(this->size > obj_passed.size){
        re_size = obj_passed.size;      // getting the least size.
    }else{
        re_size = this->size;
    }

    if(this->size == obj_passed.size){
        for(int i=0 ; i<size ; i++){
            this->arr[i] -= obj_passed.arr[i];
        }
    }
    else{
        cout<<"\nTHE SIZE IS NOT SAME. SO COPYING UPTO LOWER SIZE."<<endl;
        for(int i=0 ; i<re_size ; i++){
            this->arr[i] -= obj_passed.arr[i];      // but it will add only within the limit.
        }
    }

}

//*remove the value at the index and then shifts the array to the left.*//
int Array::operator()(int index, int val){
    if(index < 0 || index >= size){
        cerr<<"\nTHE INDEX IS OUT_OF_RANGE."<<endl;
        return -1;      // for out of range error return -1.
    }

    for(int i=index ; i<this->size-1 ; i++){
        arr[i] = arr[i+1];      // start from the index and then shift the array to left.
    }
    size--;

return 1;
}

//*initiallize the array with ans existing array.*//
Array:: Array(int* passed_arr , int size){
    this->size = size;
    this->arr = new int[size];
    for(int i=0 ; i<size ; i++){
        this->arr[i] = passed_arr[i];
    }
}

//*DESTRUCTOR.*//
Array::~Array(){
    delete[] arr;
    arr=nullptr;
}

//*O-STREAM FUNSTION TO DISPLAY OUTPUT.*//
ostream& operator<<(ostream& out_put , const Array& obj){
    out_put<<"\n SIZE OF THE ARRAY IS = "<<obj.size<<endl;
    out_put<<"\n AND THE ARRAY IS = \n\n {  ";
    for(int i=0 ; i<obj.size ; i++){
        out_put<<obj.arr[i]<<" ";
    }
    out_put<<"  }"<<endl;

return out_put;
}

//*I-STREAM FUNSTION TO TAKE INPUT.*//
istream& operator>>(istream& in_put, Array& obj){
    int size;
    cout<<"\nENTER THE SIZE OF THE ARRAY =  ";
    in_put>>size;
    obj.size = size;
    obj.arr = new int[size];
    cout<<"\nENTER THE ELEMENTS OF THE ARRAY = "<<endl;
    for(int i=0 ; i<size ; i++){
        cout<<"AT INDEX  =  [ "<<i+1<<" ]  =  ";
        in_put>>obj.arr[i];
    }

return in_put;
}

//*CONVERSION FUNCTIONS.*//

//*int to float conversion.*//
Array::operator float* () const{

    float* f_array = new float[size];
    for(int i=0 ; i<size ; i++){
        f_array[i] = static_cast<float>(arr[i]);
    }

    cout<<"\n THE CONVERTED [FLOAT ARRAY] IS = \n";
    for(int i=0 ; i<size ; i++){
        cout<<f_array[i]<<" ";
    }
    cout<<endl;

return f_array;
}

//*int to double conversion.*//
Array::operator double* () const{
    double* d_array = new double[size];
    for(int i=0 ; i<size ; i++){
        d_array[i] = static_cast<double>(arr[i]);
    }

    cout<<"\n THE CONVERTED [DOUBLE ARRAY] IS = \n";
    for(int i=0 ; i<size ; i++){
        cout<<d_array[i]<<" ";
    }
    cout<<endl;

return d_array;
}

//*int to long double conversion.*//
Array::operator long double* () const{
    long double* ld_array = new long double[size];
    for(int i=0 ; i<size ; i++){
        ld_array[i] = static_cast<long double>(arr[i]);
    }

    cout<<"\n THE CONVERTED [LONG DOUBLE ARRAY] IS = \n";
    for(int i=0 ; i<size ; i++){
        cout<<ld_array[i]<<" ";
    }
    cout<<endl;

return ld_array;
}

//*reverse conversion functions.*//

//*float to int conversion.*//
Array::Array(const float* float_array, int size){
    this->size = size;
    this->arr = new int[size];
    for(int i=0 ; i<size ; i++){
        this->arr[i] = static_cast<int>( float_array[i] );
    }

    // as it is a constructor,therefore no return.
}

//*double to int conversion.*//
Array::Array(const double* double_array, int size){
    this->size = size;
    this->arr = new int[size];
    for(int i=0 ; i<size ; i++){
        this->arr[i] = static_cast<int>( double_array[i] );
    }

    // as it is a constructor,therefore no return.
}

//*long double to int conversion.*//
Array::Array(const long double* longDouble_Arr, int size){
    this->size = size;
    this->arr = new int[size];
    for(int i=0 ; i<size ; i++){
        this->arr[i] = static_cast<int>( longDouble_Arr[i] );
    }

    // as it is a constructor,therefore no return.
}

//*ACCESS THE CONVERSION FUNCTIONS.*//
void conversion_functions(Array& a_1 , const Array& a_2);

//*ACCESS THE REMAINING FUNCTIONS.*//
void remaining_functions(Array& arr , const Array& arr_1);


//*MAIN FUNCTION.*//
int main(){

    Array arr;          // creating an Array obj.
    cin>>arr;           // taking input via i-stream function.
    cout<<arr;

    const Array arr_1(arr);         // copied the data.

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
                conversion_functions(arr , arr_1);
            break;
            }
            case 2:
            {
                remaining_functions(arr , arr_1);

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


//*CONVERSION FUNCTIONS.*//
void conversion_functions(Array& a_1 , const Array& a_2){

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
                int size;
                cout<<"\nENTER THE SIZE OF THE ARRAY [FLOATING ARRAY]\n";
                cin>>size;
                float* float_array = new float[size];
                cout<<"\nENTER THE ELEMENTS OF THE ARRAY [FLOATING ARRAY]\n";
                for(int i=0 ; i<size ; i++){
                    cout<<"\nAT INDEX  =  [ "<<i+1<<" ]  =  ";
                    cin>>float_array[i];
                }
                Array float_arr(float_array, size);
                cout<<float_arr<<endl;
            
            break;
            }
            case 2:
            {
                int size;
                cout<<"\nENTER THE SIZE OF THE ARRAY [DOUBLEING ARRAY]\n";
                cin>>size;
                double* double_array = new double[size];
                cout<<"\nENTER THE ELEMENTS OF THE ARRAY [DOUBLEING ARRAY]\n";
                for(int i=0 ; i<size ; i++){
                    cout<<"\nAT INDEX  =  [ "<<i+1<<" ]  =  ";
                    cin>>double_array[i];
                }
                Array double_arr(double_array, size);
                cout<<double_arr<<endl;
            
            break;
            }
            case 3:
            {
                int size;
                cout<<"\nENTER THE SIZE OF THE ARRAY [LONG DOUBLEING ARRAY]\n";
                cin>>size;
                long double* longDouble_Arr = new long double[size];
                cout<<"\nENTER THE ELEMENTS OF THE ARRAY [LONG DOUBLEING ARRAY]\n";
                for(int i=0 ; i<size ; i++){
                    cout<<"\nAT INDEX  =  [ "<<i+1<<" ]  =  ";
                    cin>>longDouble_Arr[i];
                }
                Array longDouble_arr(longDouble_Arr, size);
                cout<<longDouble_arr<<endl;

            break;
            }
            case 4:
            {
                float* f_array;
                cout<<"\n THE ARRAY AFTER [INT] TO [FLOAT] CONVERSION.\n";
                f_array = a_1;
            break;               
            }
            case 5:
            {
                double* d_array;
                cout<<"\n THE ARRAY AFTER [INT] TO [DOUBLE] CONVERSION.\n";
                d_array = a_1;

            break;
            }
            case 6:
            {
                long double* ld_array;
                cout<<"\n THE ARRAY AFTER [INT] TO [LONG DOUBLE] CONVERSION.\n";
                ld_array = a_1;

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


//*REMAINING FUNCTIONS.*//
void remaining_functions(Array& arr , const Array& arr_1){

    int exit=1;

        while(exit){

            int choice;
            cout<<"\n SELECT THE OPERATIO YOU WANT TO PERFORM [**] \n";
            cout<<"\n [1].  RETURN VALUE AT A SPECIFIC {INDEX} VIA ~CONSTANT OBJECT.";
            cout<<"\n [2].  RETURN VALUE AT A SPECIFIC {INDEX} VIA  CONSTANT OBJECT.";
            cout<<"\n [3].  ADD TWO ARRAYS      [INDEX WISE] ";
            cout<<"\n [4].  SUBTRACT TWO ARRAYS [INDEX WISE] ";
            cout<<"\n [5].  PRE-INCREMENT       [INDEX WISE] ";
            cout<<"\n [6].  PRE-DECREMENT       [INDEX WISE] ";
            cout<<"\n [7].  POST-INCREMENT      [INDEX WISE] ";
            cout<<"\n [8].  POST-DECREMENT      [INDEX WISE] ";
            cout<<"\n [9].  COMPARE TWO ARRAYS  [INDEX WISE] ";
            cout<<"\n [10]. CHECK IF THE ARRAY IS EMPTY. ";
            cout<<"\n [11]. ADD AND THAN ASSIGN ONE ARRAY TO OTHER. ";
            cout<<"\n [12]. SUBTRACT AND THAN ASSIGN ONE ARRAY TO OTHER. ";
            cout<<"\n [13]. REMOVE THE VALUE AT A SPECIFIC {INDEX} ";
            cout<<"\n [14]. INITIALLIZE ARRAY WITH AN EXIXTING ARRAY. ";
            cout<<"\n [15]. COPIES THE ARRAY WITH ASSIGNMENT OPERATOR. ";
            cout<<"\n [0]. { EXIT CASE } \n";
            cout<<"\n     ENTER YOUR CHOICE = ";
            cin>>choice;

            switch(choice){
                case 1:
                {
                    int index;
                    cout<<"\n ENTER THE INDEX = ";
                    cin>>index;

                    int element_returned = arr[index];
                    cout<<"\n THE VALUE AT INDEX  [ "<<index<<" ]   IS =   { "<<element_returned<<" }"<<endl;
                break;
                }
                case 2:
                {
                    int index;
                    cout<<"\n ENTER THE INDEX = ";
                    cin>>index;

                    int element_returned = arr_1[index];
                    cout<<"\n THE VALUE AT INDEX  [ "<<index<<" ]   IS =   { "<<element_returned<<" }"<<endl;
                break;
                }
                case 3:
                {
                    Array new_obj;
                    cin>>new_obj;
                    cout<<new_obj;
                    
                    cout<<"\n ADDING THIS ARRAY WITH THE ALREADY INITIALLIZED ARRAY. \n";

                    new_obj = new_obj + arr;
                    cout<<new_obj<<endl;
                break;
                }
                case 4:
                {
                    Array new_obj;
                    cin>>new_obj;
                    cout<<new_obj;

                    cout<<"\n SUBTRACTING THIS ARRAY WITH THE ALREADY INITIALLIZED ARRAY. \n";
                    new_obj = new_obj - arr;
                    cout<<new_obj<<endl;
                break;
                }
                case 5:
                {
                    ++arr;
                    cout<<arr;
                break;
                }
                case 6:
                {
                    --arr;
                    cout<<arr;
                break;
                }
                case 7:
                {
                    arr++;
                    cout<<arr;
                break;
                }
                case 8:
                {
                    arr--;
                    cout<<arr;
                break;
                }
                case 9:
                {
                    if(arr == arr_1){
                        cout<<"\n THE TWO ARRAYS ARE EQUAL.";
                    }else{
                        cout<<"\n THE TWO ARRAYS ARE NOT EQUAL.";
                    }
                break;
                }
                case 10:
                {
                    bool is_empty = arr.operator!();

                    if(!is_empty){
                        cout<<"\n THE ARRAY IS NOT EMPTY.";
                    }else{
                        cout<<"\n THE ARRAY IS EMPTY.";
                    }
                break;
                }
                case 11:
                {
                    Array new_obj;
                    cin>>new_obj;
                    cout<<new_obj;

                    cout<<"\n [ADD] AND [ASSIGN] THIS ARRAY WITH THE ALREADY INITIALLIZED ARRAY. \n";

                    arr += new_obj;
                    cout<<arr<<endl;
                break;
                }
                case 12:
                {
                    Array new_obj;
                    cin>>new_obj;
                    cout<<new_obj;

                    cout<<"\n [SUBTRACT] AND [ASSIGN] THIS ARRAY WITH THE ALREADY INITIALLIZED ARRAY. \n";
                    arr -= new_obj;
                    cout<<arr<<endl;
                
                break;
                }
                case 13:
                {
                    cout<<"\n THE SIZE OF THE ARRY IS  = [ "<<arr.get_size()<<" ] "<<endl; 
                    int index;
                    cout<<"\n ENTER THE INDEX =   :) ";
                    cin>>index;
                    cout<<"\n THE VALUE AT INDEX  [ "<<index<<" ]   IS = "<<endl;
                    cout<<arr[index]<<endl;

                    cout<<"\n NOW REMOVING THIS VALUE FROM THE ARRAY ):"<<endl;
                    arr.operator()(index , arr[index]);
                    cout<<"\n THE UPDATED ARRAY IS = \n";
                    cout<<arr<<endl;
                break;
                }
                case 14:
                {
                    int size;
                    cout<<"\n ENTER THE SIZE OF THE ARRAY =  ";
                    cin>>size;
                    int* arr = new int[size];
                    cout<<"\n ENTER THE ELEMENTS OF THE ARRAY = "<<endl;
                    for(int i=0 ; i<size ; i++){
                        cout<<"\nAT INDEX  =  [ "<<i+1<<" ]  =  ";
                        cin>>arr[i];
                    }
                    Array new_obj(arr, size);       // constructor that initializes the array with pre-defined array.
                    cout<<new_obj<<endl;
                break;
                }
                case 15:
                {
                    cout<<"\nTHE ARRAY BEFORE COPYING IS = "<<endl;
                    cout<<arr<<endl;

                    arr = arr_1;        // copying via assignment operator... 

                    cout<<"\nTHE ARRAY [AFTER] COPTING IS = "<<endl;
                    cout<<arr<<endl;
                break;
                }
                case 0:
                {
                    cout<<"\n { !!!----RETURNING TO MAIN----!!! }. \n";
                    return;
                }
                default:
                {
                    cout<<"\n PLEASE ENTER A VALID CHOICE. \n";
                break;
                }
            
            }//switch

        cout<<"\n DO YOU WANT TO CONTINUE [?]";
        cout<<"\n [1]. YES.";
        cout<<"\n [0]. NO. ";
        cout<<"\n ENTER YOUR CHOICE = ";
        cin>>exit;
    }//loop

}