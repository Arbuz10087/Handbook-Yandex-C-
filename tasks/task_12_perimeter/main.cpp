class Figure {

    public:

    virtual int Perimeter() const = 0;
    virtual ~Figure() = default;
};

class Triangle : public Figure {
    private:
    int a_;
    int b_;
    int c_;

    public:

    Triangle(const int a,const int b, const int c) 
    : a_(a), b_(b), c_(c) {
    }

    int Perimeter() const override{
        return a_+b_+c_;
    }

};

class Rectangle : public Figure {
    private:
    int a_;
    int b_;

    public:

    Rectangle(const int a, const int b) 
    : a_(a), b_(b) {}

    int Perimeter() const override {
        return 2*(a_+b_);
    }


};