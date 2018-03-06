#ifndef GDV_FIXEDALLOCATOR_H_
#define GDV_FIXEDALLOCATOR_H_

#include <assert.h>
#include "gdv/Common/Types.h"

namespace gdv {

template<size_t Stride, size_t Num>
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
		assert(heap_.next_);
		NextBlock block;
		block = heap_;
		heap_ = block;
		return (void*)block.next_;
	}

	void Deallocate(void *p) noexcept {
		assert((size_t)p >= (size_t)buffer_ && (size_t)p < (size_t)buffer + Stride * Num);
		((NextBlock*)p)->next_ = heap_.next_;
		heap_.next_ = (NextBlock*)p;
	}

	void DeallocateAll() noexcept {
		for(size_t i = 0; i < Num - 1; ++i){
			((NextBlock*)&buffer_[i * Stride])->next_ = (NextBlock*)&buffer_[(i + 1) * Stride];
		}
		((NextBlock*)&buffer_[(Num - 1) * Stride])->next_ = nullptr;
		heap_.next_ = (NextBlock*)buffer_;
	}

public:
	FixedAllocator(const FixedAllocator&) = delete;
	FixedAllocator(FixedAllocator&&) = delete;
	FixedAllocator& operator = (const FixedAllocator&) = delete;
	FixedAllocator& operator = (FixedAllocator&&) = delete;

private:
	struct NextBlock {
		NextBlock *next_;
	};
	byte buffer_[Stride * Num];
	NextBlock heap_;
};

} // namespace gdv

#endif
