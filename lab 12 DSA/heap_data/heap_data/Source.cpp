
#include <iostream>
#include <stdexcept>
#include <string>
#include <queue>
using namespace std;
class Task
{
public:
    int id;
    int priority;
    string description;
    Task():id(0),priority(0),description(""){}
    Task(int id,int priority,string description)
    {
        this->id = id;
        this->priority = priority;
        this->description = description;
    }
};
class PriorityQueue
{
private :
    Task * heap;
    int capacity;
    int size;
    int parent(int i)
    {
        return i / 2;
    }
    int left(int i)
    {
        return i * 2 + 1;
    }
    int right(int i)
    {
        return i * 2 + 2;
    }
    void swap(int i, int j)
    {
        Task temp = heap[i];
        heap[i] = heap[j];
        heap[j] = temp;
    }
    void heapifyUp(int j)
    {
        while (j != 0 && heap[parent(j)].priority < heap[j].priority)
        {
            this->swap(parent(j), j);
            j = parent(j);
        }
    }
    void heapifyDown(int i)
    {
        while (true)
        {
            int leftChild = left(i);
            int rightChild = right(i);
            int largest = i;

            if (leftChild < size && heap[leftChild].priority > heap[largest].priority)
            {
                largest = leftChild;
            }

            if (rightChild < size && heap[rightChild].priority > heap[largest].priority)
            {
                largest = rightChild;
            }

            if (largest != i)
            {
                swap(i, largest);
                i = largest;
            }
            else
            {
                break;
            }
        }
    }

public:
    PriorityQueue(int capacity)
    {
        heap = new Task[capacity];
        this->capacity = capacity;
        size = 0;
    }
    ~PriorityQueue()
    {
        if (heap)
        {
            delete[] heap;
            capacity = 0;
            size = 0;
        }
    }
    void enqueue(Task task)
    {

        heap[size++] = task;
        heapifyUp(size-1);
    }
    Task dequeue()
    {
        if (!isEmpty())
        {
            Task res = heap[0];
            swap(0, size - 1);
            size--;
            heapifyDown(0);
            return res;
        }
        return Task{ -1,-1,"" };
    }
    Task peek() const
    {
        if (!isEmpty())
            return heap[0];
        return Task{ -1,-1,"" };

    }
    bool isEmpty()const
    {
        if (size == 0)
            return true;
        return false;
    }
    int getSize() const
    {
        return size ;
    }
};
int kth_smallest(int nums[], int n, int k) 
{
    priority_queue<int> a;
    for (int i = 0; i < n; i++)
    {
        a.push(nums[i]);
    }
    for (int i = 0; i < n; i++)
    {
        
        nums[i]= a.top();
        a.pop();
        cout << nums[i] << " ";
    }

    return nums[n - k];
}
int main() 
{

    /*int input_array[] = { 2, 3, 9, 4, 0, 8 };
        int n = sizeof(input_array) / sizeof(input_array[0]);
        int k = 4;
    
        cout << "Input Array: ";
        for (int i = 0; i < n; ++i) 
        {
            cout << input_array[i] << " ";
        }
        cout << endl;
    
        cout << "k: " << k << endl;
    
        cout << "Output: " << kth_smallest(input_array, n, k) << endl;*/
    
    PriorityQueue q1{ 10 };
    q1.enqueue(Task { 1,10,"task 1 - low Priority" });
    q1.enqueue(Task{ 2,50,"task 2 - high Priority" });
    q1.enqueue(Task{ 3,30,"task 3 - medium Priority" });
    q1.enqueue(Task{ 4,40,"task 4 - medium high Priority" });

    Task top = q1.peek();
    cout << "Top Task : " << top.description << endl;

   Task d = q1.dequeue();
    cout << "Dequeued Task : " << d.description << endl;


   top = q1.peek();
    cout << "Top Task : " << top.description << endl;


    d = q1.dequeue();
    cout << "Dequeued Task : " << d.description << endl;


     top = q1.peek();
    cout << "Top Task  : " << top.description << endl;
    d = q1.dequeue();
    cout << "Dequeued Task : " << d.description << endl;

    top = q1.peek();
    cout << "Top Task  : " << top.description << endl;
    d = q1.dequeue();
    cout << "Dequeued Task : " << d.description << endl;

    top = q1.peek();
    cout << "Top Task  : " << top.description << endl;
    d = q1.dequeue();
    cout << "Dequeued Task : " << d.description << endl;

   /* top = q1.peek();
    cout<<*/
   // Task temp=q1.dequeue();
    /*cout << temp.description << endl;
    cout << q1.dequeue().priority << endl;;
    cout << temp.description << endl;*/

  //  int arr[] = { 20,10,30,50,40 };
    /*Heap_Tree <int> t;
    t.insert(99);
    t.insert(45);
    t.insert(63);
    t.insert(35);
    t.insert(29);
    t.insert(-1);
    t.insert(-1);
    t.insert(27);
    t.insert(12);
    t.insert(24);
    t.insert(26);
    t.deleteMax();
    t.display();*/


    return 0;
}


//
//template <typename T>
//class Array
//{
//private:
//    T* arr;
//    int capacity;
//    int noOfElements;
//
//    // Function to resize the array when needed
//    void resize()
//    {
//        capacity *= 2;
//        T* newArr = new T[capacity];
//        for (int i = 0; i < noOfElements; ++i)
//        {
//            newArr[i] = arr[i];
//        }
//        delete[] arr;
//        arr = newArr;
//    }
//
//public:
//    // Constructor
//    Array(int initialCapacity = 10) : capacity(initialCapacity), noOfElements(1)
//    {
//        arr = new T[capacity];
//    }
//
//    // Copy constructor
//    Array(const Array& other) : capacity(other.capacity), noOfElements(other.noOfElements)
//    {
//        arr = new T[capacity];
//        for (int i = 0; i < noOfElements; ++i)
//        {
//            arr[i] = other.arr[i];
//        }
//    }
//
//    // Assignment operator
//    Array& operator=(const Array& other)
//    {
//        if (this == &other)
//        {
//            return *this;
//        }
//        delete[] arr;
//
//        capacity = other.capacity;
//        noOfElements = other.noOfElements;
//        arr = new T[capacity];
//        for (int i = 0; i < noOfElements; ++i)
//        {
//            arr[i] = other.arr[i];
//        }
//        return *this;
//    }
//
//    // Destructor
//    ~Array()
//    {
//        if (arr)
//            delete[] arr;
//    }
//
//    // Access operator (const version)
//    const T& operator[](int index) const
//    {
//        if (index < 0 || index >= noOfElements)
//        {
//            throw std::out_of_range("Index out of range");
//        }
//        return arr[index];
//    }
//
//    // Access operator (non-const version)
//    T& operator[](int index)
//    {
//        if (index < 0 || index >= noOfElements)
//        {
//            throw std::out_of_range("Index out of range");
//        }
//        return arr[index];
//    }
//
//    // Function to add a new element
//    void add(const T& element)
//    {
//        if (noOfElements == capacity)
//        {
//            resize();
//        }
//        arr[noOfElements++] = element;
//    }
//
//    // Function to get the number of elements
//    int size() const {
//        return noOfElements;
//    }
//    int getNoOfElement()
//    {
//        return noOfElements;
//    }
//    void setNoOfElement(int v)
//    {
//        noOfElements = v;
//    }
//    void swap(int source, int destination) {
//        if (source < 0 || source >= noOfElements || destination < 0 || destination >= noOfElements)
//        {
//            throw std::out_of_range("Index out of range");
//        }
//        T temp = arr[source];
//        arr[source] = arr[destination];
//        arr[destination] = temp;
//    }
//    bool isEmpty()
//    {
//        if (noOfElements == 1)
//            return true;
//        return false;
//    }
//};
//template <typename T>
//class Heap_Tree
//{
//    Array<T> arr;
//public:
//    void insert(T value)
//    {
//        arr.add(value);
//        int size = arr.getNoOfElement() - 1;
//        int i = size;
//        while (i > 1)
//        {
//            int parent = i / 2;
//            if (arr[parent] < arr[i])
//            {
//                arr.swap(parent, i);
//                i = parent;
//            }
//            else
//                return;
//        }
//    }
//    void display()
//    {
//        int size = arr.getNoOfElement() - 1;
//        for (int i = 1; i <= size; i++)
//        {
//            cout << arr[i] << "\t";
//        }
//    }
//    void deleteMax()
//    {
//        int lastIndex = arr.getNoOfElement() - 1;
//        arr.swap(1, lastIndex);
//        arr.setNoOfElement(lastIndex - 1);
//        int i = 1;
//        while (i < lastIndex)
//        {
//            int left = arr[2 * i];
//            int right = arr[2 * i + 1];
//            int larger = left > right ? 2 * i : 2 * i + 1;
//            if (arr[i] < arr[larger])
//            {
//                arr.swap(larger, i);
//                i = larger;
//            }
//            else
//            {
//                return;
//            }
//        }
//    }
//};
//void swap(int*& arr, int i, int j)
//{
//    int temp = arr[i];
//    arr[i] = arr[j];
//    arr[j] = temp;
//}
//void heapify(int*& arr, int n, int i)
//{
//    int largest = i;
//    int l = 2 * i;
//    int r = 2 * i + 1;
//    if (l <= n && arr[l] > arr[largest])
//        largest = l;
//    if (r <= n && arr[l] < arr[largest])
//        largest = r;
//    if (largest != i)
//    {
//        swap(arr, i, largest);
//        heapify(arr, n, largest);
//    }
//}
//void buildHeap(int* arr, int n)
//{
//    for (int i = n / 2; i > 0; i--)
//    {
//        heapify(arr, n, i);
//    }
//}
//void heapSort(int* a, int n)
//{
//    for (int i = n; i < 1; i--)
//    {
//        swap(a, 1, i);
//        heapify(a, i - 1, 1);
//    }
//}
//void swap2(int& a, int& b) {
//    int temp = a;
//    a = b;
//    b = temp;
//}
//
//// Heapify function to maintain the heap property
////void heapify(int* heap, int n, int i) {
////    int smallest = i;
////    int left = 2 * i + 1;
////    int right = 2 * i + 2;
////
////    if (left < n && heap[left] < heap[smallest]) {
////        smallest = left;
////    }
////    if (right < n && heap[right] < heap[smallest]) {
////        smallest = right;
////    }
////
////    if (smallest != i) {
////        swap2(heap[i], heap[smallest]);
////        heapify(heap, n, smallest);
////    }
////}
//
//// Function to build a min-heap from an array
//void buildMinHeap(int* heap, int n) {
//    for (int i = n / 2 - 1; i >= 0; --i) {
//        heapify(heap, n, i);
//    }
//}
//int findKthLargest(int* nums, int size, int k)
//{
//
//
//    int* heap = new int[k];
//
//    // Insert first k elements into the heap
//    for (int i = 0; i < k; ++i) {
//        heap[i] = nums[i];
//    }
//
//    // Build the min-heap with the first k elements
//    buildMinHeap(heap, k);
//
//    // Process the remaining elements
//    for (int i = k; i < size; ++i) {
//        if (nums[i] > heap[0]) {
//            heap[0] = nums[i];
//            heapify(heap, k, 0);
//        }
//    }
//
//    // The root of the heap is the k-th largest element
//    int kthLargest = heap[0];
//
//    // Clean up allocated memory
//    delete[] heap;
//
//    return kthLargest;
//}












//#ifndef PRIORITY_H
//#define PRIORITY_H
//#include<iostream>
//#include<string>
//using namespace std;
//
//class Task
//{
//public:
//    int id;
//    int priority;
//    string descrition;
//    Task() :id(0), priority(0), descrition("") {}
//    Task(int id, int priority, string description)
//    {
//        this->id = id;
//        this->priority = priority;
//        this->descrition = description;
//    }
//
//};
//
//class PriorityQueue
//{
//    Task* heap;
//    int capacity;
//    int size;
//    int parent(int i)
//    {
//        return i / 2;
//    }
//    int left(int i)
//    {
//        return 2 * i;
//    }
//    int right(int i)
//    {
//        return 2 * i + 1;
//    }
//    void swap(Task& a, Task& b)
//    {
//        Task temp = a;
//        a = b;
//        b = temp;
//    }
//    bool maxHeap()
//    {
//        int i = 0;
//        bool status = false;
//        while (i <= size)
//        {
//            if ((2 * i + 1 <= size) && (2 * i + 2 <= size))
//            {
//                if (heap[2 * i + 1].priority > heap[2 * i + 2].priority && heap[i].priority < heap[2 * i + 1].priority)
//                {
//                    swap(heap[i], heap[2 * i + 1]);
//                    status = true;
//                }
//                else if (heap[2 * i + 1].priority < heap[2 * i + 2].priority && heap[i].priority < heap[2 * i + 2].priority)
//                {
//                    swap(heap[i], heap[2 * i + 2]);
//                    status = true;
//                }
//            }
//            if (2 * i + 1 <= size && heap[2 * i + 1].priority > heap[i].priority)
//            {
//                swap(heap[i], heap[2 * i + 1]);
//                status = true;
//            }
//            else if (2 * i + 2 <= size && heap[2 * i + 2].priority > heap[i].priority)
//            {
//                swap(heap[i], heap[2 * i + 2]);
//                status = true;
//            }
//            i++;
//        }
//        return status;
//    }
//    void heapifyUp(int i)
//    {
//        bool status = true;
//        while (status)
//            status = maxHeap();
//    }
//    void heapifyDown(int i)
//    {
//        heap[0].id = heap[size].id;
//        heap[0].priority = heap[size].priority;
//        heap[0].descrition = heap[size].descrition;
//        size--;
//        heapifyUp(0);
//
//    }
//
//public:
//
//    PriorityQueue(int capacity)
//    {
//        heap = new Task[capacity];
//        this->capacity = capacity;
//        size = 0;
//    }
//    ~PriorityQueue()
//    {
//        delete[] heap;
//    }
//    void enqueue(Task task)
//    {
//        heap[size].id = task.id;
//        heap[size].priority = task.priority;
//        heap[size].descrition = task.descrition;
//        size++;
//        heapifyUp(0);
//    }
//    Task Dequeue()
//    {
//        Task t;
//        t.id = heap[0].id;
//        t.priority = heap[0].priority;
//        t.descrition = heap[0].descrition;
//        heapifyDown(0);
//        return t;
//    }
//    Task peek() const
//    {
//        Task t;
//        t.id = heap[0].id;
//        t.priority = heap[0].priority;
//        t.descrition = heap[0].descrition;
//        return t;
//    }
//    bool isEmpty() const
//    {
//        if (size == 0)return true;
//        return false;
//    }
//    int getSize() const
//    {
//        return size + 1;
//    }
//    void display()
//    {
//        for (int i = 0; i < size; i++)
//        {
//            cout << "priority : " << heap[i].priority << "  ";
//            cout << "id : " << heap[i].id << "  ";
//            cout << "description : " << heap[i].descrition << "  ";
//            cout << endl;
//        }
//    }
//
//};
//
//#endif // !PRIORITY_H


