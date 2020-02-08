
// https://www.youtube.com/watch?v=pP15kDeXJU0

#include <memory>

template<class T>
class TrackingAllocator {
public:
	using value_type = T;

	// optional aliases
	using pointer = T * ;
	using const_pointer = const T *;

	using void_pointer = void *;
	using const_void_pointer = const void *;

	using size_type = size_t;

	using difference_type = std::ptrdiff_t;

	template<class U>
	struct rebind {
		using other = TrackingAllocator<U>;
	};

	TrackingAllocator() = default;

	template<class U>
	TrackingAllocator(const TrackingAllocator<U>& other) { }

	~TrackingAllocator() = default;

	pointer allocate(size_type numObjects) {
		mAllocations += numObjects;
		return static_cast<pointer>(operator new(sizeof(T) * numObjects));
	}

	pointer allocate(size_type numObjects, const_void_pointer hint) {
		return allocate(numObjects);
	}

	void deallocate(pointer p, size_type numObjects) {
		operator delete(p);
	}

	size_type max_size() const {
		return std::numeric_limits<size_type>::max();
	}

	template<class U, class... Args>
	void construct(U *p, Args && ...args) {
		new (p) U(std::forward<Args>(args)...);
	}

	template<class U>
	void destroy(U *p) {
		p->~U();
	}

	size_type getAllocations() const {
		return mAllocations;
	}

private:
	static size_type mAllocations;
};


template<class T>
typename TrackingAllocator<T>::size_type TrackingAllocator<T>::mAllocations = 0;
