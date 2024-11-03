// size 0xC
template<typename T>
class FO2Vector {
public:
	T* begin = nullptr;
	T* end = nullptr;
	T* capacity = nullptr;

	auto GetSize() {
		return end - begin;
	}
	auto GetCapacity() {
		return capacity - begin;
	}
	T* Get(int id) {
		if (id < 0 || id >= GetSize()) return nullptr;
		return &begin[id];
	}
};