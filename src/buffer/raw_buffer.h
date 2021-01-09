#ifndef RAW_BUFFER_H
#define RAW_BUFFER_H
#include "ferror.h"
#include <stdint.h>
namespace fth
{

    enum raw_buffer_result
    {
        NO_ERROR = FEATHER_SUCCESS, // everything
        NOT_VALID_SIZE,             // create_buffer()
        NOT_VALID_NEW_SIZE,         // increase_buffer()
        BUFFER_ALREADY_FREE,        // delete_buffer()
        BUFFER_NOT_ALLOCATED,       // increase_buffer()
        BUFFER_ALREADY_ALLOCATED,   // create_buffer()
    };

    using cbuffer = void *;
    using buffer_size_t = uint64_t;
    class raw_buffer
    {
    public:
        raw_buffer() = default;
        raw_buffer(buffer_size_t size);

        ferror create(buffer_size_t size);       // malloc
        ferror destroy();                        // free
        ferror increase(buffer_size_t new_size); // realloc

        buffer_size_t get_buffer_size() const
        {
            return buffer_size;
        }

        // warning: can return nullptr
        cbuffer get() const
        {
            return raw;
        }
        operator cbuffer() const
        {
            return get();
        }

    protected:
        raw_buffer_result last_error;
        cbuffer raw = nullptr;
        bool is_null = true;
        bool is_allocated = false;
        buffer_size_t buffer_size = 0;
    };
} // namespace fth

#endif // RAW_BUFFER_H
