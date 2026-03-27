#include <string>
#include <iostream>
#include <vector>

class Pizza
{
protected:
    std::string name;
    std::string dough;
    std::string sauce;
    std::vector<std::string> toppings;

public:
    virtual ~Pizza() {}

    virtual void prepare()
    {
        std::cout << "Preparing " << name << std::endl;
        std::cout << "Tossing dough..." << std::endl;
        std::cout << "Adding sauce..." << std::endl;
        std::cout << "Adding toppings:" << std::endl;
        for (const auto &t : toppings)
        {
            std::cout << " " << t << std::endl;
        }
    }

    virtual void bake()
    {
        std::cout << "Bake for 25 minutes at 350" << std::endl;
    }

    virtual void cut()
    {
        std::cout << "Cutting the pizza into diagonal slices" << std::endl;
    }

    virtual void box()
    {
        std::cout << "Place pizza in official PizzaStore box" << std::endl;
    }

    std::string getName()
    {
        return name;
    }
};

class NYStyleCheesePizza : public Pizza
{
public:
    NYStyleCheesePizza()
    {
        name = "NY Style Sauce and Cheese Pizza";
        dough = "Thin Crust Dough";
        sauce = "Marinara Sauce";
        toppings.push_back("Grated Reggiano Cheese");
    }
};

class NYStyleVeggiePizza : public Pizza
{
public:
    NYStyleVeggiePizza()
    {
        name = "NY Style Veggie Pizza";
        dough = "Thin Crust Dough";
        sauce = "Marinara Sauce";
        toppings.push_back("Garlic");
        toppings.push_back("Onion");
        toppings.push_back("Mushrooms");
    }
};

class NYStyleClamPizza : public Pizza
{
public:
    NYStyleClamPizza()
    {
        name = "NY Style Clam Pizza";
        dough = "Thin Crust Dough";
        sauce = "Marinara Sauce";
        toppings.push_back("Fresh Clams");
    }
};

class NYStylePepperoniPizza : public Pizza
{
public:
    NYStylePepperoniPizza()
    {
        name = "NY Style Pepperoni Pizza";
        dough = "Thin Crust Dough";
        sauce = "Marinara Sauce";
        toppings.push_back("Sliced Pepperoni");
    }
};

class ChicagoStyleCheesePizza : public Pizza
{
public:
    ChicagoStyleCheesePizza()
    {
        name = "Chicago Style Deep Dish Cheese Pizza";
        dough = "Extra Thick Crust Dough";
        sauce = "Plum Tomato Sauce";
        toppings.push_back("Shredded Mozzarella Cheese");
    }

    void cut() override
    {
        std::cout << "Cutting the pizza into square slices" << std::endl;
    }
};

class ChicagoStyleVeggiePizza : public Pizza
{
public:
    ChicagoStyleVeggiePizza()
    {
        name = "Chicago Style Veggie Pizza";
        dough = "Extra Thick Crust Dough";
        sauce = "Plum Tomato Sauce";
        toppings.push_back("Black Olives");
        toppings.push_back("Spinach");
    }

    void cut() override
    {
        std::cout << "Cutting the pizza into square slices" << std::endl;
    }
};

class ChicagoStyleClamPizza : public Pizza
{
public:
    ChicagoStyleClamPizza()
    {
        name = "Chicago Style Clam Pizza";
        dough = "Extra Thick Crust Dough";
        sauce = "Plum Tomato Sauce";
        toppings.push_back("Frozen Clams");
    }

    void cut() override
    {
        std::cout << "Cutting the pizza into square slices" << std::endl;
    }
};

class ChicagoStylePepperoniPizza : public Pizza
{
public:
    ChicagoStylePepperoniPizza()
    {
        name = "Chicago Style Pepperoni Pizza";
        dough = "Extra Thick Crust Dough";
        sauce = "Plum Tomato Sauce";
        toppings.push_back("Sliced Pepperoni");
    }

    void cut() override
    {
        std::cout << "Cutting the pizza into square slices" << std::endl;
    }
};

class PizzaStore
{
public:
    virtual ~PizzaStore() {}

    Pizza *orderPizza(const std::string &type)
    {
        Pizza *pizza = createPizza(type);

        if (!pizza)
        {
            std::cout << "Invalid pizza type" << std::endl;
            return nullptr;
        }

        pizza->prepare();
        pizza->bake();
        pizza->cut();
        pizza->box();

        return pizza;
    }

protected:
    virtual Pizza *createPizza(const std::string &type) = 0;
};

class NYPizzaStore : public PizzaStore
{
protected:
    Pizza *createPizza(const std::string &item) override
    {
        if (item == "cheese")
            return new NYStyleCheesePizza();
        else if (item == "veggie")
            return new NYStyleVeggiePizza();
        else if (item == "clam")
            return new NYStyleClamPizza();
        else if (item == "pepperoni")
            return new NYStylePepperoniPizza();
        else
            return nullptr;
    }
};

class ChicagoPizzaStore : public PizzaStore
{
protected:
    Pizza *createPizza(const std::string &item) override
    {
        if (item == "cheese")
            return new ChicagoStyleCheesePizza();
        else if (item == "veggie")
            return new ChicagoStyleVeggiePizza();
        else if (item == "clam")
            return new ChicagoStyleClamPizza();
        else if (item == "pepperoni")
            return new ChicagoStylePepperoniPizza();
        else
            return nullptr;
    }
};

int main()
{
    PizzaStore *nyStore = new NYPizzaStore();
    PizzaStore *chicagoStore = new ChicagoPizzaStore();

    std::string types[] = {"cheese", "veggie", "clam", "pepperoni"};

    std::cout << "[NY PIZZAS]" << std::endl;
    for (const auto &type : types)
    {
        Pizza *pizza = nyStore->orderPizza(type);
        if (pizza)
            std::cout << "Ordered: " << pizza->getName() << std::endl;
        std::cout << std::endl;
    }

    std::cout << "[CHICAGO PIZZAS]" << std::endl;
    for (const auto &type : types)
    {
        Pizza *pizza = chicagoStore->orderPizza(type);
        if (pizza)
            std::cout << "Ordered: " << pizza->getName() << std::endl;
        std::cout << std::endl;
    }

    delete nyStore;
    delete chicagoStore;

    return 0;
}