#ifndef IS_SAME_H
#define IS_SAME_H
#include "ftypes.h"
#include "type/integral_constant.h"
#include "type/remove.h"
namespace fth
{
    template <class T1, class T2>
    class is_same : public false_type
    {
    };

    template <class T1>
    class is_same<T1, T1> : public true_type
    {
    };

    template <class T>
    class is_nullptr : public is_same<nullptr_t, remove_const_volatile<T>>
    {
    };
} // namespace fth
#endif // IS_SAME_H
