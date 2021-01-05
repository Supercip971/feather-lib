#ifndef RAW_BUFFER_H
#define RAW_BUFFER_H
#include <stdint.h>
#include "ferror.h"
namespace fth {

    enum raw_buffer_result{
        NO_ERROR = FEATHER_SUCCESS, // everything
        NOT_VALID_SIZE,             // create_buffer()
        NOT_VALID_NEW_SIZE,         // increase_buffer()
        BUFFER_ALREADY_FREE,        // delete_buffer()
        BUFFER_NOT_ALLOCATED,        // increase_buffer()
        BUFFER_ALREADY_ALLOCATED,   // create_buffer()
    };

    typedef void* cbuffer;
    typedef uint64_t buffer_size_t;
    class raw_buffer
    {
    public:

        raw_buffer() = default;
        raw_buffer(buffer_size_t size);
        raw_buffer_result create_buffer(buffer_size_t size);
        raw_buffer_result delete_buffer();
        buffer_size_t get_buffer_size() const {
            return buffer_size;
        }
        raw_buffer_result increase_buffer(buffer_size_t new_size);

        // warning: can return nullptr
        cbuffer get() const {
            return raw;
        }
        operator cbuffer() const{
            return get();
        }

    protected:
        raw_buffer_result last_error;
        cbuffer raw = nullptr;
        bool is_null = true;
        bool is_allocated = false;
        buffer_size_t buffer_size = 0;
    };
}

#endif // RAW_BUFFER_H
