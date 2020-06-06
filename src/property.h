#ifndef CPP_PROPERTY_H
#define CPP_PROPERTY_H

namespace {
    template<typename T>
    using PGetter = T (*)(const T&);

    template<typename T>
    using PSetter = T (*)(T&, const T& value);
}

template<typename T, PGetter<T> getter = nullptr, PSetter<T> setter = nullptr>
class Property {

    public:

        template<typename... Args>
        Property(Args... args): _inner(args...), _get(getter), _set(setter) {}

        // operator=(const T& value) const {
        //     if(_get != nullptr)
        //         return _get(_inner);
        //     return _inner;
        // }
        T get() const {
            if(_get != nullptr)
                return _get(_inner);
            return _inner;
        }

        T set(const T& value) {
            if(_set != nullptr)
                return _set(_inner, value);
            return _inner = value;
        }

        operator T() const {
            return get();
        }

    private:
        T _inner;
        PGetter<T> _get;
        PSetter<T> _set;
};



#endif // CPP_PROPERTY_H