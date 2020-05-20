#include <cassert>
#include <iostream>

class Pyramid {
    public:
        //Initializer list
        Pyramid(int length, int width, int height) : length_(length), width_(width), height_(height) {
            Validate();
        }

        //Define getter/mutator functions once outside or once inside class
        //Accessor/Get function allows you to receive information
        int getLength() const { return length_; }
        int getWidth() const { return width_; }
        int getHeight() const { return height_; }

        //Mutator/Set function allows you to change information
        void setLength(int length){
            length_ = length;
            Validate();
        };

        void setWidth(int width){
            width_ = width;
            Validate();
        };

        void setHeight(int height){
            height_ = height;
            Validate();
        };

        float Volume() const {
            return getLength() * getWidth() * getHeight() / 3.0; 
        };

    private:
        //trailing underscore convention to remind us that it is private variable 
        int length_;
        int width_;
        int height_;
        void Validate() {
            if (length_ <= 0 || width_ <= 0 || height_ <= 0)
            throw std::invalid_argument("negative dimension");
        }
};

int main(){
    Pyramid pyramid(1, 2, 3);
    // assert(pyramid.getLength() == 1);
    // assert(pyramid.getWidth() == 2);
    // assert(pyramid.getHeight() == 3);
    std::cout << "The pyramid length is " << pyramid.getLength() << std::endl;
    std::cout << "The pyramid width is " << pyramid.getWidth() << std::endl;
    std::cout << "The pyramid height is " << pyramid.getHeight() << std::endl;
    std::cout << "The pyramid volume is " << pyramid.Volume() << std::endl ;

    bool caught{false};
    try {
        Pyramid invalid(-1, 2, 3);
    } catch (...) {
        caught = true;
    }
    assert(caught);
}