
#include <iostream> 
#include <memory>
#include <string>


class ConstExp : public Expression {
private:
   
   int x_;

   public: 

   ConstExp(int x) : x_(x) {}

   int Evaluate() const override {
      return x_;
   }

   std::string ToString() const override {
       return std::to_string(x_);
   }

};


class SumExp : public Expression {
    private:
    std::shared_ptr<Expression> left_;
    std::shared_ptr<Expression> right_;

    public:

    SumExp(const ExpressionPtr& left, const ExpressionPtr& right) 
    : left_(left), right_(right) {}

    std::string ToString() const override {
       return left_->ToString() +" + " + right_->ToString();
    }

    int Evaluate() const override {
        return left_->Evaluate() + right_->Evaluate();
    }

};


class ProductExp : public Expression {
    private:
    std::shared_ptr<Expression> left_;
    std::shared_ptr<Expression> right_;

    public:

    ProductExp(const ExpressionPtr& left, const ExpressionPtr& right) 
    : left_(left), right_(right) {}

    int Evaluate() const override {
        return left_->Evaluate()*right_->Evaluate();
    }

    std::string ToString() const override {
        std::string l, r;
        auto sumLeft = std::dynamic_pointer_cast<SumExp>(left_);
        auto sumRight = std::dynamic_pointer_cast<SumExp>(right_);
        if (sumLeft != nullptr) {
            l = "(" + left_->ToString() + ")";
        } else {
            l = left_->ToString();
        }
        if (sumRight != nullptr) {
            r = "(" + right_->ToString()+ ")";
        } else {
            r = right_->ToString();
        }
        return l + " * " + r;
    }
};


std::shared_ptr<Expression> Const (int x) { 
    return std::make_shared<ConstExp>(x);
}

std::shared_ptr<Expression> Sum (const ExpressionPtr& x, const ExpressionPtr& y) {
    return std::make_shared<SumExp>(x, y);
}

std::shared_ptr<Expression> Product (const ExpressionPtr& x, const ExpressionPtr& y) {
    return std::make_shared<ProductExp>(x, y);
}