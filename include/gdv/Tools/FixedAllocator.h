#ifndef GDV_FIXEDALLOCATOR_H_
#define GDV_FIXEDALLOCATOR_H_

#include <assert.h>
#include "gdv/Common/Types.h"

namespace gdv {

template <size_t Stride, size_t Num>
class FixedAllocator {
	static_assert(Stride > 7, "The stride requires more than 8.");
	static_assert(Num > 0, "The num requires more than 1.");

public:
	FixedAllocator() noexcept :
		buffer_{},
		heap_{} {
		DeallocateAll();
	}

	~FixedAllocator() {}

	void* Allocate() noexcept {
		void *block;
		block = heap_;
		*(size_t*)heap_ = *(size_t*)block;
		return block;
	}

	void Deallocate(void *p) noexcept {
		*(size_t*)p = *(size_t*)heap_;
		heap_ = p;
	}

	void DeallocateAll() noexcept {
		for(size_t i = 0; i < Num - 1; ++i){
			*(size_t*)&buffer_[i * Stride] = *(size_t*)&buffer_[(i + 1) * Stride];
		}
		*(size_t**)&buffer_[(Num - 1) * Stride] = nullptr;
		heap_ = (void*)buffer_;
	}

public:
	FixedAllocator(const FixedAllocator&) = delete;
	FixedAllocator(FixedAllocator&&) = delete;
	FixedAllocator& operator = (const FixedAllocator&) = delete;
	FixedAllocator& operator = (FixedAllocator&&) = delete;

private:
	byte buffer_[Stride * Num];
	void *heap_;
};

} // namespace gdv

#endif
