#ifndef _API_TYPES_TYPES_HPP_
#define _API_TYPES_TYPES_HPP_


namespace ezEngine {

    struct Vector2d {
        Vector2d() {}
        Vector2d(const int x, const int y) : x(x), y(y) {}
        int x; 
        int y;
        Vector2d operator+(const Vector2d& other)
        {
            Vector2d v(*this);
            v.x += other.x;
            v.y += other.y;
            return v;
        }
        Vector2d operator-(const Vector2d& other)
        {
            Vector2d v(*this);
            v.x -= other.x;
            v.y -= other.y;
            return v;
        }
        Vector2d operator*(const Vector2d& other)
        {
            Vector2d v(*this);
            v.x *= other.x;
            v.y *= other.y;
            return v;
        }
        Vector2d operator*(const float value)
        {
            Vector2d v(*this);
            v.x *= value;
            v.y *= value;
            return v;
        }
        Vector2d operator/(const Vector2d& other)
        {
            Vector2d v(*this);
            v.x /= other.x;
            v.y /= other.y;
            return v;
        }
        Vector2d operator/(const float rhs)
        {
            Vector2d v(*this);
            v.x /= rhs;
            v.y /= rhs;
            return v;
        }
        bool operator==(const Vector2d& other)
        {
            Vector2d v(*this);
            return (v.x == other.x && v.y == other.y);
        }
        bool operator==(const int rhs)
        {
            Vector2d v(*this);
            return (v.x == rhs && v.y == rhs);
        }
    };


    struct Rectangle {
        Rectangle() {}
        Rectangle(const int x, const int y, const int w, const int h) : x(x), y(y), w(w), h(h) {}
        int x;
        int y;
        int w;
        int h;
        Rectangle operator*(const float multiplier)
        {
            Rectangle r(*this);
            auto center = r.GetCenter();
            r.w *= multiplier;
            r.h *= multiplier;
            r.x = center.x - r.w/2;
            r.y = center.y - r.h/2;
            return r;
        }
        Rectangle operator/(const float divisor)
        {
            Rectangle r(*this);
            auto center = r.GetCenter();
            r.w /= divisor;
            r.h /= divisor;
            r.x = center.x - r.w/2;
            r.y = center.y - r.h/2;
            return r;
        }
        Rectangle operator+(const int addend)
        {
            Rectangle r(*this);
            auto center = r.GetCenter();
            r.w += addend;
            r.h += addend;
            r.x = center.x - r.w/2;
            r.y = center.y - r.h/2;
            return r;
        }
        Rectangle operator-(const int subtrahend)
        {
            Rectangle r(*this);
            auto center = r.GetCenter();
            r.w -= subtrahend;
            r.h -= subtrahend;
            r.x = center.x - r.w/2;
            r.y = center.y - r.h/2;
            return r;
        }
        Vector2d GetCenter()
        {
            Vector2d center;
            Rectangle r(*this);
            center.x = r.x + r.w/2.0;
            center.y = r.y + r.h/2.0;
            return center;
        }
    };

    struct Color {
        Color() {}
        Color(const int r, const int g, const int b, const int a) : r(r), g(g), b(b), a(a) {}
        unsigned char r;
        unsigned char g;
        unsigned char b;
        unsigned char a;
    };




}


#endif