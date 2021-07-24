#ifndef GUARD_VEC_H
#define GUARD_VEC_H
#include <cstddef>

template <class T> class Vec {
public:

    // ������Ϊ����STL����һ��
    typedef T* iterator;
    typedef const T* const_iterator;
    typedef size_t size_type;
    typedef T value_type;

	Vec() { create(); }
	explicit Vec(size_type n, const T& val=T()) { create(n, val); }

    // ���ƹ��캯��
    // �����µ��ڴ�ռ�
    Vec(const Vec& v) { create(v.begin(), v.end()); }

    // ��ֵ�����
	// ��ֵ���������������(���ƹ���)�������ǣ�ǰ���Ƕ�һ���Ѿ����ڵ�ֵ��ȥ��Ȼ����һ���µ�ֵȡ����֮
	// �����߲���Ҫ��֮ǰ�Ķ�����������ݽ�����ղ���
	// �����˴������Ҹ�ֵ������
	// �ܽ᣺��ֵ����ɾ��һ����ֵ������ʼ����û���ⲽ��������ʼ����������һ���µĶ���ͬʱ����һ����ʼ��ֵ
    Vec& operator=(const Vec&);

	~Vec() { uncreate(); }

    // get Vec��С������
    size_type size() const { return (limit - data); }
    T& operator[](size_type i) { return data[i]; }
    const T& operator[](size_type i) const { return data[i]; }

    // ���ص������ĺ���begin, end
    iterator begin() { return data; }
    const_iterator begin() const { return data; }
    iterator end() { return limit; }
    const_iterator end() const { return limit; }


private:
    iterator data;
    iterator limit;
	// Ϊʲô���� new T[N]�ķ�ʽ�����ڴ��أ�
	// ��ΪT������Ĭ�Ϲ��캯��������׼��vector��û��������Ƶ�

};


#endif