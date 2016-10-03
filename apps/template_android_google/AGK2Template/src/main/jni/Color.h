#ifndef COLOR_H
#define COLOR_H


class Color
{
    public:
        Color();
        Color(unsigned long);
        Color(float r, float g, float b);
        virtual ~Color();
    protected:
    private:
        float r;
        float g;
        float b;
};

#endif // COLOR_H
