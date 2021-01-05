#include "raw_buffer.h"
#include <stdio.h>
#include <stdlib.h>
namespace fth {

    raw_buffer::raw_buffer(buffer_size_t size) : raw_buffer()
    {
        is_allocated = false;
        create_buffer(size);
    }

    raw_buffer_result raw_buffer::create_buffer(buffer_size_t size){

        if(size == 0){
            fprintf(stderr, "error: can't create a raw buffer with size: %x \n", size);
            return raw_buffer_result::NOT_VALID_SIZE;
        }else if(is_allocated){
            fprintf(stderr, "error: buffer already allocated \n");
            return raw_buffer_result::BUFFER_ALREADY_ALLOCATED;
        }else{

            raw = malloc(size);
            if(raw == nullptr){
                fprintf(stderr, "error: can't allocate buffer with size: %x \n", size);
                return raw_buffer_result::BUFFER_NOT_ALLOCATED;
            }else{
                is_allocated = true;
                buffer_size = size;
            }
        }
    }
}
