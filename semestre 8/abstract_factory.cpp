#include <iostream>
#include <string>
#include <memory>

class Dough
{
public:
    virtual std::string toString() = 0;
    virtual ~Dough() {}
};
class Sauce
{
public:
    virtual std::string toString() = 0;
    virtual ~Sauce() {}
};
class Cheese
{
public:
    virtual std::string toString() = 0;
    virtual ~Cheese() {}
};
class Clams
{
public:
    virtual std::string toString() = 0;
    virtual ~Clams() {}
};

class ThinCrustDough : public Dough
{
public:
    std::string toString() override { return "Thin Crust Dough"; }
};
class ThickCrustDough : public Dough
{
public:
    std::string toString() override { return "Thick Crust Dough"; }
};

class MarinaraSauce : public Sauce
{
public:
    std::string toString() override { return "Marinara Sauce"; }
};
class PlumTomatoSauce : public Sauce
{
public:
    std::string toString() override { return "Plum Tomato Sauce"; }
};

class ReggianoCheese : public Cheese
{
public:
    std::string toString() override { return "Reggiano Cheese"; }
};
class MozzarellaCheese : public Cheese
{
public:
    std::string toString() override { return "Mozzarella Cheese"; }
};

class FreshClams : public Clams
{
public:
    std::string toString() override { return "Fresh Clams"; }
};
class FrozenClams : public Clams
{
public:
    std::string toString() override { return "Frozen Clams"; }
};

class PizzaIngredientFactory
{
public:
    virtual std::unique_ptr<Dough> createDough() = 0;
    virtual std::unique_ptr<Sauce> createSauce() = 0;
    virtual std::unique_ptr<Cheese> createCheese() = 0;
    virtual std::unique_ptr<Clams> createClam() = 0;
    virtual ~PizzaIngredientFactory() {}
};

class NYPizzaIngredientFactory : public PizzaIngredientFactory
{
public:
    std::unique_ptr<Dough> createDough() override { return std::make_unique<ThinCrustDough>(); }
    std::unique_ptr<Sauce> createSauce() override { return std::make_unique<MarinaraSauce>(); }
    std::unique_ptr<Cheese> createCheese() override { return std::make_unique<ReggianoCheese>(); }
    std::unique_ptr<Clams> createClam() override { return std::make_unique<FreshClams>(); }
};

class ChicagoPizzaIngredientFactory : public PizzaIngredientFactory
{
public:
    std::unique_ptr<Dough> createDough() override { return std::make_unique<ThickCrustDough>(); }
    std::unique_ptr<Sauce> createSauce() override { return std::make_unique<PlumTomatoSauce>(); }
    std::unique_ptr<Cheese> createCheese() override { return std::make_unique<MozzarellaCheese>(); }
    std::unique_ptr<Clams> createClam() override { return std::make_unique<FrozenClams>(); }
};

class Pizza
{
protected:
    std::string name;

public:
    virtual void prepare() = 0;

    virtual void bake() { std::cout << "Bake for 25 minutes at 350\n"; }
    virtual void cut() { std::cout << "Cutting the pizza into diagonal slices\n"; }
    virtual void box() { std::cout << "Place pizza in official PizzaStore box\n"; }

    void setName(const std::string &n) { name = n; }
    std::string getName() { return name; }

    virtual ~Pizza() {}
};

class CheesePizza : public Pizza
{
private:
    PizzaIngredientFactory *ingredientFactory;
    std::unique_ptr<Dough> dough;
    std::unique_ptr<Sauce> sauce;
    std::unique_ptr<Cheese> cheese;

public:
    CheesePizza(PizzaIngredientFactory *factory) : ingredientFactory(factory) {}

    void prepare() override
    {
        std::cout << "Preparing " << name << std::endl;
        dough = ingredientFactory->createDough();
        std::cout << "Adding dough: " << dough->toString() << std::endl;

        sauce = ingredientFactory->createSauce();
        std::cout << "Adding sauce: " << sauce->toString() << std::endl;

        cheese = ingredientFactory->createCheese();
        std::cout << "Adding cheese: " << cheese->toString() << std::endl;
    }
};

class ClamPizza : public Pizza
{
private:
    PizzaIngredientFactory *ingredientFactory;
    std::unique_ptr<Dough> dough;
    std::unique_ptr<Sauce> sauce;
    std::unique_ptr<Cheese> cheese;
    std::unique_ptr<Clams> clam;

public:
    ClamPizza(PizzaIngredientFactory *factory) : ingredientFactory(factory) {}

    void prepare() override
    {
        std::cout << "Preparing " << name << std::endl;

        dough = ingredientFactory->createDough();
        std::cout << "Adding dough: " << dough->toString() << std::endl;

        sauce = ingredientFactory->createSauce();
        std::cout << "Adding sauce: " << sauce->toString() << std::endl;

        cheese = ingredientFactory->createCheese();
        std::cout << "Adding cheese: " << cheese->toString() << std::endl;

        clam = ingredientFactory->createClam();
        std::cout << "Adding clams: " << clam->toString() << std::endl;
    }
};

class VeggiePizza : public Pizza
{
private:
    PizzaIngredientFactory *ingredientFactory;
    std::unique_ptr<Dough> dough;
    std::unique_ptr<Sauce> sauce;
    std::unique_ptr<Cheese> cheese;

public:
    VeggiePizza(PizzaIngredientFactory *factory) : ingredientFactory(factory) {}

    void prepare() override
    {
        std::cout << "Preparing " << name << std::endl;

        dough = ingredientFactory->createDough();
        std::cout << "Adding dough: " << dough->toString() << std::endl;

        sauce = ingredientFactory->createSauce();
        std::cout << "Adding sauce: " << sauce->toString() << std::endl;

        cheese = ingredientFactory->createCheese();
        std::cout << "Adding cheese: " << cheese->toString() << std::endl;

        std::cout << "Adding veggies: assorted vegetables" << std::endl;
    }
};

class PepperoniPizza : public Pizza
{
private:
    PizzaIngredientFactory *ingredientFactory;
    std::unique_ptr<Dough> dough;
    std::unique_ptr<Sauce> sauce;
    std::unique_ptr<Cheese> cheese;

public:
    PepperoniPizza(PizzaIngredientFactory *factory) : ingredientFactory(factory) {}

    void prepare() override
    {
        std::cout << "Preparing " << name << std::endl;

        dough = ingredientFactory->createDough();
        std::cout << "Adding dough: " << dough->toString() << std::endl;

        sauce = ingredientFactory->createSauce();
        std::cout << "Adding sauce: " << sauce->toString() << std::endl;

        cheese = ingredientFactory->createCheese();
        std::cout << "Adding cheese: " << cheese->toString() << std::endl;

        std::cout << "Adding pepperoni slices" << std::endl;
    }
};

class PizzaStore
{
public:
    virtual std::unique_ptr<Pizza> createPizza(const std::string &type) = 0;

    std::unique_ptr<Pizza> orderPizza(const std::string &type)
    {
        auto pizza = createPizza(type);
        if (!pizza)
            return nullptr;

        pizza->prepare();
        pizza->bake();
        pizza->cut();
        pizza->box();

        return pizza;
    }

    virtual ~PizzaStore() {}
};

class NYPizzaStore : public PizzaStore
{
public:
    std::unique_ptr<Pizza> createPizza(const std::string &item) override
    {
        PizzaIngredientFactory *factory = new NYPizzaIngredientFactory();
        Pizza *pizza = nullptr;

        if (item == "cheese")
        {
            pizza = new CheesePizza(factory);
            pizza->setName("New York Style Cheese Pizza");
        }
        else if (item == "clam")
        {
            pizza = new ClamPizza(factory);
            pizza->setName("New York Style Clam Pizza");
        }
        else if (item == "veggie")
        {
            pizza = new VeggiePizza(factory);
            pizza->setName("New York Style Veggie Pizza");
        }
        else if (item == "pepperoni")
        {
            pizza = new PepperoniPizza(factory);
            pizza->setName("New York Style Pepperoni Pizza");
        }

        return std::unique_ptr<Pizza>(pizza);
    }
};

class ChicagoPizzaStore : public PizzaStore
{
public:
    std::unique_ptr<Pizza> createPizza(const std::string &item) override
    {
        PizzaIngredientFactory *factory = new ChicagoPizzaIngredientFactory();
        Pizza *pizza = nullptr;

        if (item == "cheese")
        {
            pizza = new CheesePizza(factory);
            pizza->setName("Chicago Style Cheese Pizza");
        }
        else if (item == "clam")
        {
            pizza = new ClamPizza(factory);
            pizza->setName("Chicago Style Clam Pizza");
        }
        else if (item == "veggie")
        {
            pizza = new VeggiePizza(factory);
            pizza->setName("Chicago Style Veggie Pizza");
        }
        else if (item == "pepperoni")
        {
            pizza = new PepperoniPizza(factory);
            pizza->setName("Chicago Style Pepperoni Pizza");
        }

        return std::unique_ptr<Pizza>(pizza);
    }
};

int main()
{
    std::unique_ptr<PizzaStore> nyStore = std::make_unique<NYPizzaStore>();
    std::unique_ptr<PizzaStore> chicagoStore = std::make_unique<ChicagoPizzaStore>();

    std::string types[] = {"cheese", "clam", "veggie", "pepperoni"};

    std::cout << "[NY PIZZAS]" << std::endl;
    for (const auto &type : types)
    {
        auto pizza = nyStore->orderPizza(type);
        if (pizza)
            std::cout << "Ordered: " << pizza->getName() << std::endl;
        std::cout << std::endl;
    }

    std::cout << "[CHICAGO PIZZAS]" << std::endl;
    for (const auto &type : types)
    {
        auto pizza = chicagoStore->orderPizza(type);
        if (pizza)
            std::cout << "Ordered: " << pizza->getName() << std::endl;
        std::cout << std::endl;
    }

    return 0;
}