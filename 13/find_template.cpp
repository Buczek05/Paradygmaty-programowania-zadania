#include <iostream>

#pragma once

template <class T, class Key>
T *Find(const T* p_begin, const T* p_end, const Key& k){
    if (p_begin >= p_end){
        return NULL;
    }

    for (const T* p_tmp = p_begin; p_tmp != p_end; p_tmp++){
        if (*p_tmp == k)
            return const_cast<T*>(p_tmp);
    }
    return NULL;
}