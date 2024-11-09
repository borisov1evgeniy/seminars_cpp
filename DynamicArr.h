#pragma once
template <class T>
class DynamicArr {
	static const size_t initialCapacity_ = 2;	// only one for all objects of DynamicArr
	static const double coeff_;					// same as above

	size_t size_ = 0;
	size_t capacity_ = initialCapacity_;
	T* arr_;

public:
	DynamicArr();
	DynamicArr(size_t size, T element = 0);
	DynamicArr(const DynamicArr<T>& rhs);
	DynamicArr(DynamicArr<T>&& rhs);
	~DynamicArr();
	size_t size() const;
	size_t capacity() const;
	void push_back(T elem);
	void operator= (const DynamicArr<T>& rhs);
	T& operator[](const size_t index);
	const T& operator[](size_t index) const;
	
};