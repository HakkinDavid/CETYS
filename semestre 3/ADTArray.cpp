# include <iostream>
# include <algorithm>
# include <cmath>
# include <chrono>
using namespace std;
using namespace chrono;

template < class T >
class Array {
    private :
        int size;
        int length;
        T * A = nullptr;
    
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
            if (A != nullptr) {
                //delete [] A;
            }
        }
    
        void Display ();
        void Add ( T x );
        void Resize ();
        void Insert ( int index , T x );
        void Delete ( int index );
        T& Get ( int index );
        void Set ( int index , T x );
        void Reverse ();
        void Swap ( int a, int b );
        void InsertionSort (Array<T>& arr);
        void InsertionSort ();
        void Merge_S (int p, int q, int r, Array<T>& arr);
        void MergeSort (int p, int r, Array<T>& arr);
        void MergeSort ();
        int Partition (int p, int r, Array<T>& arr);
        void QuickSort (int p, int r, Array<T>& arr);
        void QuickSort ();

        T& operator[] (int index);
};

template < class T >
T& Array < T > :: operator[] (int index) {
    return Get(index);
}

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
T& Array < T > :: Get ( int index ) {
    if ( index >= 0 && index < length ) {
        return A [ index ];
    }
    else {
        cout << "No se puede acceder al elemento " << index << ", el tamaño es " << length << ". Retornando primer elemento." << endl;
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
void Array < T > :: InsertionSort (Array<T>& arr) {
    for (int j = 1; j < arr.length; j++) {
        T key = arr[j];
        int i = j - 1;
        while (i >= 0 && arr[i] > key) {
            arr[i+1] = arr[i];
            i = i - 1;
        }
        arr[i + 1] = key;
    }
}

template < class T >
void Array < T > :: InsertionSort () {
    InsertionSort(*this);
}

template < class T >
void Array < T > :: Merge_S (int p, int q, int r, Array<T>& arr) {
    int n1 = q - p + 1;
    int n2 = r - q;
    T L[n1];
    T R[n2];

    for (int i = 0; i < n1; i++) {
        L[i] = arr [p + i];
    }
    for (int i = 0; i < n2; i++) {
        R[i] = arr [q + i];
    }

    int atL = 0, atR = 0;

    for (int k = p; k < r; k++) {
        if (L[atL] <= R[atR]) {
            arr[k] = L[atL];
            atL++;
        }
        else {
            arr[k] = R[atR];
            atR++;
        }
    }
}

template < class T >
void Array < T > :: MergeSort ( int p, int r, Array<T>& arr ) {
    if (p < r) {
        int q = floor((p+r)/2);
        MergeSort(p, q, arr);
        MergeSort(q + 1, r, arr);
        Merge_S (p, q, r, arr);
    }
}

template < class T >
void Array < T > :: MergeSort () {
    MergeSort(0, length-1, *this);
}

template < class T >
int Array < T > :: Partition (int p, int r, Array<T>& arr) {
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
void Array < T > :: QuickSort (int p, int r, Array<T>& arr) {
    if (p < r) {
        int q = Partition(p, r, arr);
        QuickSort(p, q-1, arr);
        QuickSort(q+1, r, arr);
    }
}

template < class T >
void Array < T > :: QuickSort () {
    QuickSort(0, length-1, *this);
}

int main ()
{
    int BIGSIZE = 9999;
    Array < int > A (BIGSIZE);
    for (int i = 0; i < BIGSIZE; i++) {
        A.Add(rand() % INT_MAX);
    }
    Array < int > B = A;
    Array < int > C = A;

    /*A.Display();
    cout << endl;
    B.Display();
    cout << endl;
    C.Display();
    cout << endl;*/

    auto ISstart = high_resolution_clock::now();
    A.InsertionSort();
    auto ISend = high_resolution_clock::now();
    auto MSstart = high_resolution_clock::now();
    B.MergeSort();
    auto MSend = high_resolution_clock::now();
    auto QSstart = high_resolution_clock::now();
    C.QuickSort();
    auto QSend = high_resolution_clock::now();

    /*A.Display();
    cout << endl;
    B.Display();
    cout << endl;
    C.Display();
    cout << endl;*/

    cout << "Insertion Sort: " << (duration_cast<microseconds>(ISend - ISstart)).count() << "µs." << endl;
    cout << "Merge Sort: " << (duration_cast<microseconds>(MSend - MSstart)).count() << "µs." << endl;
    cout << "Quick Sort: " << (duration_cast<microseconds>(QSend - QSstart)).count() << "µs." << endl;

    return 0;
}