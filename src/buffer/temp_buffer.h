#ifndef TEMP_BUFFER_H
#define TEMP_BUFFER_H
#include "raw_buffer.h"
namespace fth {

    class temp_buffer
    {
        raw_buffer raw;
    public:
        ferror destroy();
        temp_buffer(buffer_size_t size);
        ~temp_buffer(){destroy();};
        cbuffer get()const {return raw.get();};
    };
}

#endif // TEMP_BUFFER_H
