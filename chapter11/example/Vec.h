#include <cstddef>
template <class T> class Vec {
public:
	Vec() { create(); }
	explicit Vec(size_type n, const T& val=T()) { create(n, val); }
private:
	T* data;
	T* limit;
	// Ϊʲô���� new T[N]�ķ�ʽ�����ڴ��أ�
	// ��ΪT������Ĭ�Ϲ��캯��������׼��vector��û��������Ƶ�


};