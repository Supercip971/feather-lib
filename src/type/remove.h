#ifndef REMOVE_H
#define REMOVE_H
namespace fth {
    template<class T> struct remove_const_volatile                   { typedef T type; };
    template<class T> struct remove_const_volatile<const T>          { typedef T type; };
    template<class T> struct remove_const_volatile<volatile T>       { typedef T type; };
    template<class T> struct remove_const_volatile<const volatile T> { typedef T type; };
    #ifdef USE_STD_CV
    using remove_cv = remove_const_volatile;

    #endif

    template<class T> struct remove_const                { typedef T type; };
    template<class T> struct remove_const<const T>       { typedef T type; };

    template<class T> struct remove_volatile             { typedef T type; };
    template<class T> struct remove_volatile<volatile T> { typedef T type; };

    template<class T> struct remove_pointer              {typedef T type ;};
    template<class T> struct remove_pointer<T*>          {typedef T type ;};

}
#endif // REMOVE_H
