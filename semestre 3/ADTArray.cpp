# include <iostream>
# include <algorithm>
# include <cmath>
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
        Array ( initializer_list<T> args ) {
            this -> size = args.end() - args.begin();
            length = 0;
            A = new T [ size ];
            for (int i = 0; i < size; i++) {
                A[i] = *(args.begin() + i);
                length++;
            }
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
        //void InsertionSort ()
        void Merge_S (int l, int m, int r, T * arr);
        void MergeSort (int b, int e, T * arr);
        void MergeSort ();
        int Partition (int p, int r, T * arr);
        void QuickSort (int p, int r, T * arr);
        void QuickSort ();
};

template < class T >
void Array < T > :: Display () {
    for ( int i = 0; i < length; i ++)
        cout << A [ i ] << (i == length - 1 ? "\n" : ", ");
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
        cout << "No se puede. Retornando primer elemento." << endl;
    }
    return A[0];
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

template < class T >
void Array < T > :: Merge_S (int l, int m, int r, T * arr) {
    int debug = 135;
    int leftArrSize = m - l + 1; cout << "Ejecutando línea " << ++debug << endl;
    int rightArrSize = r - m; cout << "Ejecutando línea " << ++debug << endl;
    int leftArr[leftArrSize]; cout << "Ejecutando línea " << ++debug << endl;
    int rightArr[rightArrSize]; cout << "Ejecutando línea " << ++debug << endl;

    for (int i = 0; i < leftArrSize; i++) {
        leftArr[i] = arr [l + i]; cout << "Ejecutando línea " << ++debug << endl;
    }
    for (int i = 0; i < rightArrSize; i++) {
        rightArr[i] = arr [m + 1 + i]; cout << "Ejecutando línea " << ++debug << endl;
    }

    int atLeft = 0, atRight = 0, atArr = l; cout << "Ejecutando línea " << ++debug << endl;

    while (atLeft < leftArrSize && atRight < rightArrSize) {
        if (leftArr[atLeft] <= rightArr[atRight]) {
            arr[atArr] = leftArr[atLeft]; cout << "Ejecutando línea " << ++debug << endl;
            atLeft++; cout << "Ejecutando línea " << ++debug << endl;
        }
        else {
            arr[atArr] = rightArr[atRight];
            atRight++; cout << "Ejecutando línea " << ++debug << endl;
        }
        atArr++; cout << "Ejecutando línea " << ++debug << endl;
    }
    while (atLeft < leftArrSize) {
        arr[atArr] = leftArr[atLeft]; cout << "Ejecutando línea " << ++debug << endl;
        atLeft++; cout << "Ejecutando línea " << ++debug << endl;
        atArr++; cout << "Ejecutando línea " << ++debug << endl;
    }
    while (atRight < rightArrSize) {
        arr[atArr] = rightArr[atRight]; cout << "Ejecutando línea " << ++debug << endl;
        atRight++; cout << "Ejecutando línea " << ++debug << endl;
        atArr++; cout << "Ejecutando línea " << ++debug << endl;
    }
}

template < class T >
void Array < T > :: MergeSort ( int const b, int const e, T * arr) {
    cout << "mergesort w begin = " << b << " and end = " << e << endl;
    if (b >= e) return;
    int m = floor((e-b)/2);
    MergeSort(b, m, arr);
    MergeSort(m + 1, e, arr);
    Merge_S (b, m, e, arr);
}

template < class T >
void Array < T > :: MergeSort () {
    MergeSort(1, size, A);
}

template < class T >
int Array < T > :: Partition (int p, int r, T * arr) {
    T x = arr[r];
    int i = p - 1;
    for (int j = p; j < r; j++) {
        if (arr[j] <= x) {
            i = i+1;
            T tempEl = arr[i];
            arr[i] = arr[j];
            arr[j] = tempEl;
        }
    }
    x = arr[r];
    arr[r] = arr[i+1];
    arr[i+1] = x;
    return (i+1);
}

template < class T >
void Array < T > :: QuickSort (int p, int r, T * arr) {
    if (p < r) {
        int q = Partition(p, r, arr);
        QuickSort(p, q-1, arr);
        QuickSort(q+1, r, arr);
    }
}

template < class T >
void Array < T > :: QuickSort () {
    QuickSort(0, size, A);
}

int main ()
{
    Array < int > arr = {12, 44, 0, -1, 9, 7, 8};

    arr.Display();

    //arr.MergeSort();

    arr.QuickSort();
    arr.Display();


    return 0;
}