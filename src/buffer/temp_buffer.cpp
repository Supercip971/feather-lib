#include "temp_buffer.h"
namespace fth
{

    temp_buffer::temp_buffer(buffer_size_t size)
    {
        raw.create(size);
    }
    ferror temp_buffer::destroy()
    {
        return raw.destroy();
    }
} // namespace fth
