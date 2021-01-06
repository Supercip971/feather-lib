#include "raw_buffer.h"
#include <stdio.h>
#include <stdlib.h>
namespace fth {

    raw_buffer::raw_buffer(buffer_size_t size) : raw_buffer()
    {
        is_allocated = false;
        create(size);
    }

    ferror raw_buffer::create(buffer_size_t size){

        if(size == 0){
            return feather_error("not valid buffer size", raw_buffer_result::NOT_VALID_SIZE);
        }else if(is_allocated){
            return feather_error("buffer already allocated", raw_buffer_result::BUFFER_ALREADY_ALLOCATED);
        }else{
            raw = malloc(size);
            if(raw == nullptr){
                return feather_error("malloc can't allocate buffer", raw_buffer_result::BUFFER_NOT_ALLOCATED);
            }else{
                is_allocated = true;
                buffer_size = size;
            }
        }
        return feather_noerror;
    }

    ferror raw_buffer::destroy(){
        if(!is_allocated){
            return feather_error("buffer is already free", raw_buffer_result::BUFFER_ALREADY_FREE);
        }else{
            free(raw);
            buffer_size = 0;
        }
        return feather_noerror;
    }

    ferror raw_buffer::increase(buffer_size_t new_size){
        if(new_size <= buffer_size){
            return feather_noerror;
        }else if(!is_allocated){
            return feather_error("buffer not allocated while calling increase_buffer()", raw_buffer_result::BUFFER_NOT_ALLOCATED);
        }else{
            raw = realloc(raw,new_size);
            if(raw == nullptr){
                return feather_error("realloc can't reallocate buffer", raw_buffer_result::BUFFER_NOT_ALLOCATED);
            }else{
                is_allocated = true;
                buffer_size = new_size;
            }
        }
        return feather_noerror;
    }
}
