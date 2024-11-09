#include "DynamicArr.h"
template<class T>
const double DynamicArr<T>::coeff_ = 2;
//конструктор
template<class T>
DynamicArr<T>::DynamicArr() {
	arr_ = new T[capacity_];
}
//ещё конструктор
template<class T>
DynamicArr<T>::DynamicArr(size_t size, T elem) : size_(size)
	,capacity_(coeff_* size_)
	,arr_(new T[capacity_]) {
	for (size_t i = 0; i < size_; ++i) {
		arr_[i] = elem;
	}
}
//конструктор копирования
template<class T>
DynamicArr<T>::DynamicArr(const DynamicArr<T>& rhs) {
	size_ = rhs.size_;
	capacity_ = rhs.capacity_;
	arr_ = new T[capacity_];
	for (size_t i = 0; i < size_; ++i) {
		arr_[i] = rhs.arr_[i];
	}
}
//конструктор перемещения
template<class T>
DynamicArr<T>::DynamicArr(DynamicArr<T>&& rhs) {
	size_ = rhs.size_;
	arr_ = rhs.arr_;
	capacity_ = rhs.capacity_;
	rhs.arr_ = nullptr;
	rhs.size_ = rhs.capacity_ = 0;
}
//деструктор
template<class T>
DynamicArr<T>::~DynamicArr() {
	delete[] arr_;
}
template<class T>
//оператор присвоения
void DynamicArr<T>::operator= (const DynamicArr<T>& rhs) {
	delete[] arr_;
	arr_ = new T[rhs.capacity_];
	size_ = rhs.size_;
	capacity_ = rhs.capacity_;
	for (size_t i = 0; i < rhs.size_; ++i) {
		arr_[i] = rhs.arr_[i];
	}
	
}
//оператор перемещения
void DynamicArr<T>::operator= (DynamicArr<T>&& rhs) {
	delete[] arr_;
	arr_ = rhs.arr_;
	size_ = rhs.size_;
	capacity_ = rhs.capacity_;
	rhs.arr_ = nullptr;
	rhs.size_ = rhs.capacity_ = 0;

}
//Оператор []
template <class T>
const T& DynamicArr<T>::operator[](size_t index) const {
	return arr_[index];
}
template<class T>
T& DynamicArr<T>::operator[]( size_t index) {
	return arr_[index];
}


//size
template<class T>
size_t DynamicArr<T>::size() const {
	return size_;
}
//capacity
template<class T>
size_t DynamicArr<T>::capacity() const {
	return capacity_;
}
//push_back
template<class T>
void DynamicArr<T>::push_back(T elem) {
	if (size_ == capacity_) {
		capacity_ = coeff_ * capacity_;
		T* tmp = new T[capacity_];
		for (size_t i = 0; i < size_; ++i) {
			tmp[i] = arr_[i];
		}
		delete[] arr_;
		arr_ = tmp;
	}
	arr_[size_++] = elem;
}