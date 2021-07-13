
template <class T> class Vec {
public:
    Vec() { create(); }

private:
    T* data;
    T* limit;
};