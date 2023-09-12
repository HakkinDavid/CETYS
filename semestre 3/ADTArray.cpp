# include <iostream>
# include <algorithm>
using namespace std;

template < class T >
class Array {
    private :
        int size;
        int length;
        T * A;
    
    public :
        Array () {
            size = 10;
            length = 0;
            A = new T [ 10 ];
        }
        Array ( int size ) {
            this -> size = size;
            length = 0;
            A = new T [ size ];
        }
        ~ Array () {
            delete [] A;
        }
    
        void Display ();
        void Add ( T x );
        void Resize ();
        void Insert ( int index , T x );
        void Delete ( int index );
        T Get ( int index );
        void Set ( int index , T x );
        void Reverse ();
        void Swap ( int a, int b );
};

template < class T >
void Array < T > :: Display () {
    for ( int i = 0; i < length; i ++)
    cout << A [ i ] << endl;
}

template < class T >
void Array < T > :: Add ( T x ) {
    if ( length == size ) {
        Resize ();
    }
    A [ length ] = x;
    length ++;
}

template < class T >
void Array < T > :: Resize () {
    T * B = new T [ size + 5 ];
    copy ( A , A + size , B );
    delete [] A;
    A = B;
    B = nullptr;
    size += 5;
}

template < class T >
void Array < T > :: Insert ( int index , T x ) {
    if ( length == size ) {
            cout << " No se puede " << endl;
            return;
        }
    if ( index >= 0 && index < length ) {
        for ( int i = length; i > index; i --) {
        A [ i ] = A [ i - 1 ];
    }
    A [ index ] = x;
    length ++;
  }
}
template < class T >
void Array < T > :: Delete ( int index ) {
    if ( index >= 0 && index < length ) {
        for ( int i = index; i < length - 1; i ++) {
            A [ i ] = A [ i + 1 ];
        }
        length --;
    }
}
template < class T >
T Array < T > :: Get ( int index ) {
    if ( index >= 0 && index < length ) {
        return A [ index ];
    }
    else {
        cout << "No se puede" << endl;
    }
    return NULL;
}

template < class T >
void Array < T > :: Set ( int index , T x ) {
    if ( index >= 0 && index < length ) {
        A [ index ] = x;
    }
}

template < class T >
void Array < T > :: Reverse () {
    for (int i = length-1, j = 0; i >= j; i--, j++) {
        Swap (i, j);
    }
}

template < class T >
void Array < T > :: Swap ( int a, int b ) {
    T temp = A [ a ];
    A [ a ] = A [ b ];
    A [ b ] = temp;
}

int main ()
{
    Array < int > arr ( 5 );
    arr.Add ( 2 );
    arr.Add ( 5 );
    arr.Add ( 6 );
    arr.Add ( 8 );
    arr.Add ( 7 );
    
    arr.Add ( 10 );
    
    arr.Display ();
    cout << endl;
    arr.Insert ( 1 , 23 );
    arr.Display ();
    cout << endl;
    arr.Delete ( 1 );
    arr.Display ();
    cout << endl;
    cout << arr.Get ( 1 )<< endl;
    arr.Set ( 1 , 4 );
    
    arr.Display ();

    cout << endl;

    arr.Reverse ();
    arr.Display ();
  

    return 0;
}