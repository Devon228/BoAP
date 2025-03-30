#include <iostream>

class Expression
{
    public:
        Expression()
        {

        }
        virtual ~Expression()
        {

        }

        virtual double evaluate() = 0;
};

class Number : public Expression
{
    public:
        explicit Number(double value)
        {
            this->value = value;
        }
        ~Number() override
        {

        }

        double evaluate() override
        {
            return value;
        }

    private:
        double value;
};

class BinaryOperation : public Expression
{
    public:
        BinaryOperation(Expression* left_value, char operation, Expression* right_value)
        {
            this->left_value = left_value;
            if (operation == '+' || operation == '-' || operation == '*' || operation == '/')
                this->operation = operation;
            else
            {
                std::cout << "Incorrect opration changed to '+'!";
                this->operation = '+';
            }
            this->right_value = right_value;
        }
        ~BinaryOperation() override
        {
            delete left_value;
            delete right_value;
        }

        double evaluate() override
        {
            switch (operation)
            {
                case '+':
                return left_value->evaluate() + right_value->evaluate();
                case '-':
                    return left_value->evaluate() - right_value->evaluate();
                case '*':
                    return left_value->evaluate() * right_value->evaluate();
                case '/':
                    if (right_value->evaluate() == 0)
                    {
                        std::cout << "Error!";
                        return 0;
                    }
                    else
                        return left_value->evaluate() / right_value->evaluate();
            }

            return 0;
        }

    private:
        Expression *left_value, *right_value;
        char operation;
};

bool check_equals(Expression const* left, Expression const* right)
{
    return *(double*)left == *(double*)right;
}

int main()
{
    // сначала создаём объекты для подвыражения 4.5 * 5
    Expression* num = new Number(4.5);
    Expression* sube = new BinaryOperation(num, '*', new Number(5));
    // потом используем его в выражении для +
    Expression* expr = new BinaryOperation(new Number(3), '+', sube);
    // вычисляем и выводим результат: 25.5
    std::cout << expr->evaluate() << std::endl;
    // тут освобождаются *все* выделенные объекты
    // (например, sube будет правым операндом expr, поэтому его удалять не нужно)
    std::cout << check_equals(sube, expr) << " " << check_equals(sube, num) << " " << check_equals(expr, num) << std::endl;
    delete expr;
    return 0;
}
