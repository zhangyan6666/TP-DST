//
// Created by HAI YAN ZHANG on 2023/3/23.
//

#ifndef IP_DST_POINT_GUARD_H
#define IP_DST_POINT_GUARD_H

class PointGuard {
public:
    explicit PointGuard(T* v) : _v(v), _ref(v) {}
    ~PointGuard() {
        if (NULL != _v) {
            delete _v;
            _ref = NULL;
        }
    }
private:
    T* _v;
    T*& _ref;
};

#endif //IP_DST_POINT_GUARD_H
