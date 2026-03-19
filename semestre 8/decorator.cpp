#include <iostream>
#include <string>

class Beverage
{
protected:
    std::string description = "Bebida desconocida";

public:
    virtual std::string getDescription()
    {
        return description;
    }
    virtual double cost() = 0;
};

class CondimentDecorator : public Beverage
{
public:
    virtual std::string getDescription() = 0;
};

class Espresso : public Beverage
{
public:
    Espresso()
    {
        description = "Espresso";
    }
    double cost()
    {
        return 1.99;
    }
};

class HouseBlend : public Beverage
{
public:
    HouseBlend()
    {
        description = "House Blend Coffee";
    }
    double cost()
    {
        return .89;
    }
};

class DarkRoast : public Beverage
{
public:
    DarkRoast()
    {
        description = "Dark Roast Coffee";
    }
    double cost()
    {
        return .99;
    }
};

class Decaf : public Beverage
{
public:
    Decaf()
    {
        description = "Decaf Coffee";
    }
    double cost()
    {
        return 1.05;
    }
};

class Mocha : public CondimentDecorator
{
private:
    Beverage *beverage;

public:
    Mocha(Beverage *beverage)
    {
        this->beverage = beverage;
    }
    std::string getDescription()
    {
        return beverage->getDescription() + ", Mocha";
    }
    double cost()
    {
        return .20 + beverage->cost();
    }
};

class Whip : public CondimentDecorator
{
private:
    Beverage *beverage;

public:
    Whip(Beverage *beverage)
    {
        this->beverage = beverage;
    }
    std::string getDescription()
    {
        return beverage->getDescription() + ", Whip";
    }
    double cost()
    {
        return .10 + beverage->cost();
    }
};

class Soy : public CondimentDecorator
{
private:
    Beverage *beverage;

public:
    Soy(Beverage *beverage)
    {
        this->beverage = beverage;
    }
    std::string getDescription()
    {
        return beverage->getDescription() + ", Soy";
    }
    double cost()
    {
        return .15 + beverage->cost();
    }
};

class SteamedMilk : public CondimentDecorator
{
private:
    Beverage *beverage;

public:
    SteamedMilk(Beverage *beverage)
    {
        this->beverage = beverage;
    }
    std::string getDescription()
    {
        return beverage->getDescription() + ", Steamed Milk";
    }
    double cost()
    {
        return .10 + beverage->cost();
    }
};

void printOrder(Beverage *beverage)
{
    std::cout << beverage->getDescription() << ": $" << beverage->cost() << std::endl;
}

int main()
{
    Beverage *beverage = new Espresso();
    printOrder(beverage);

    Beverage *beverage2 = new DarkRoast();
    beverage2 = new Mocha(beverage2);
    beverage2 = new Mocha(beverage2);
    beverage2 = new Whip(beverage2);
    printOrder(beverage2);

    Beverage *beverage3 = new HouseBlend();
    beverage3 = new Soy(beverage3);
    beverage3 = new Mocha(beverage3);
    beverage3 = new Whip(beverage3);
    printOrder(beverage3);
}