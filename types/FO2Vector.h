// size 0xC
template<typename T>
class FO2Vector {
public:
	T* begin = nullptr;
	T* end = nullptr;
	T* capacity = nullptr;

	T operator[] (int i) const { return begin[i]; }
	T& operator[] (int i) { return begin[i]; }

	auto GetSize() const {
		return end - begin;
	}
	auto GetCapacity() const {
		return capacity - begin;
	}
};