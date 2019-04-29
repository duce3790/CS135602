#include <iostream>

using namespace std;
class Array
{
public:

   void displayMessage() const
   {
      cout << size << endl;
   } // end function displayMessage
   int get() const{
    return size;
   }
    Array (int n);
    ~Array ();
   void setArraySize( int n );
private:
    int size;
    int *data;
};
void Array::setArraySize(int n){
    if (data == nullptr){
        if (n > 0){
            size = n;
            data = new int[n];
        }
        else size = 0;
    }
    else cerr << "can't reset array size\n";
}
Array::Array(int n){
    data = nullptr;
    setArraySize( n);
}
Array::~Array(){
	  delete [] data; data = nullptr;
}


int main()
{
    int m;
    cin >> m;
    Array abc (m);
    abc.displayMessage();
    cout << "Hello world!" << endl;
    return 0;
}
