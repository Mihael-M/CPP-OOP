#include <iostream>

template <class T>
class Vector{
  
private:
    T* arr = nullptr;
    size_t size;
    size_t capacity;
    
    void resize(size_t newCap);
    void copy(const Vector<T>& other);
    void move(Vector<T>&& other);
    void free();
    
public:
    Vector();
    Vector(const Vector<T>& other);
    Vector(Vector<T>&& other) noexcept;
    Vector& operator=(const Vector<T>& other);
    Vector& operator=(Vector<T>&& other) noexcept;
    ~Vector();
    
    void pushBack(const T& obj);
    void popBack();
    void insert(size_t index,const T& obj);
    void remove(size_t index);
    size_t count() const;
    bool isEmpty() const;
    const T& back() const;
    const T& operator[](size_t index) const;
    void clear();
    void print() const;
};


template<class T>
Vector<T>::Vector(){
    this->capacity = 8;
    this->arr= new T[this->capacity];
    this->size = 0;
}

template<class T>
Vector<T>::Vector(const Vector<T>& other){
    copy(other);
}

template<class T>
Vector<T>::Vector(Vector<T>&& other) noexcept{
    move(std::move(other));
}

template<class T>
Vector<T>& Vector<T>::operator=(const Vector<T>& other){
    if(this!=&other){
        free();
        copy(other);
    }
    return *this;
}

template<class T>
Vector<T>& Vector<T>::operator=(Vector<T>&& other) noexcept{
    if(this!=&other){
        free();
        move(std::move(other));
    }
    return *this;
}

template<class T>
Vector<T>::~Vector(){
    free();
}


template<class T>
void Vector<T>::free(){
    delete[]arr;
    this->capacity = 0;
    this->size = 0;
}

template<class T>
void Vector<T>::resize(size_t newCap){
    
    T* temp = new T[newCap];
    for(int i = 0;i<size;i++){
        this->arr[i] = temp[i];
    }
    delete[]this->arr;
    this->arr = temp;
    this->capacity = newCap;
}



template<class T>
void Vector<T>::pushBack(const T& obj){
    if(size == capacity)
        resize(capacity * 2);
    
    arr[size] = obj;
    size++;
}


template<class T>
void Vector<T>::popBack(){
    size--;
}


template<class T>
void Vector<T>::insert(size_t index, const T& obj){
    if(index >= size)
        throw std::invalid_argument("Invalid index");
    
    if(size+1 == capacity)
        resize(capacity * 2);
    
    
    for(size_t i = size; i > index; --i) {
        arr[i] = arr[i - 1];
    }
    arr[index] = obj;
    size++;
}

template<class T>
void Vector<T>::remove(size_t index){
    for(size_t i = index;i<size - 1;i++)
        arr[i] = arr[i+1];
    size--;
}

template<class T>
size_t Vector<T>::count() const{
    return size;
}


template<class T>

bool Vector<T>::isEmpty() const{
    return (size == 0);
}

template<class T>
const T& Vector<T>::back() const{
    return arr[size - 1];
}

template<class T>
const T& Vector<T>::operator[](size_t index)const{
    if(index >= size)
        throw std::invalid_argument("Invalid index");
    return arr[index];
}

template<class T>
void Vector<T>::clear(){
    size = 0;
}


template<class T>
void Vector<T>::print() const{
    for(int i = 0;i<size;i++)
        std::cout<<arr[i]<<" ";
}


template<>

