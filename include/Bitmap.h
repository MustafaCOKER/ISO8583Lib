#ifndef BITMAP_H
#define BITMAP_H

#include <array>

class Bitmap
{
    public:
        Bitmap();
        ~Bitmap() = default;

        void set(int index);
        void unset(int index);
        bool get(int index) const;
        void flip(int index);
        std::string toHex( void ) const;
        void clear(void);
        void printBits() const;
    private:
        std::array<unsigned char, 8> _bitmap;
};

#endif // BITMAP_H
