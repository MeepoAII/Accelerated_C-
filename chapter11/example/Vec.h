#include <cstddef>
template <class T> class Vec {
public:
	Vec() { create(); }
	explicit Vec(size_type n, const T& val=T()) { create(n, val); }
private:
	T* data;
	T* limit;
	// 为什么不用 new T[N]的方式分配内存呢？
	// 因为T必须有默认构造函数，而标准的vector是没有这个限制的


};