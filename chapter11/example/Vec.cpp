#include "Vec.h"

template <class T>
Vec<T>& Vec<T>::operator=(const Vec& rhs)
{
	// �ж��Ƿ�������Ҹ�ֵ
	if (&rhs != this)
	{
		// ɾ���������������
		uncreate();
		// ���Ҳิ��Ԫ�ص����
		create(rhs.begin(), rhs.end());
	}
	return *this;
}