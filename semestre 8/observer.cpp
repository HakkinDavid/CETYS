#include <iostream>
#include <list>
#include <array>
#include <vector>

class Observer;

class Subject
{
public:
    virtual void registerObserver(Observer *o) = 0;
    virtual void removeObserver(Observer *o) = 0;
    virtual void notifyObservers() = 0;
};

class Observer
{
public:
    virtual void update(float temp, float humidity, float pressure) = 0;
};

class DisplayElement
{
public:
    virtual void display() = 0;
};

class WeatherData : public Subject
{
private:
    std::list<Observer *> observers;
    float temperature;
    float humidity;
    float pressure;

public:
    WeatherData()
    {
        observers = std::list<Observer *>();
    }
    void registerObserver(Observer *o)
    {
        observers.push_back(o);
    }
    void removeObserver(Observer *o)
    {
        observers.remove(o);
    }
    void notifyObservers()
    {
        for (auto i : observers)
        {
            i->update(temperature, humidity, pressure);
        }
    }

    void measurementsChanged()
    {
        notifyObservers();
    }

    void setMeasurements(float temperature, float humidity, float pressure)
    {
        this->temperature = temperature;
        this->humidity = humidity;
        this->pressure = pressure;
        measurementsChanged();
    }
};

class CurrentConditionsDisplay : public Observer, public DisplayElement
{
private:
    float temperature;
    float humidity;
    Subject *weatherData;

public:
    CurrentConditionsDisplay(Subject *weatherData)
    {
        this->weatherData = weatherData;
        weatherData->registerObserver(this);
    }

    void update(float temperature, float humidity, float pressure)
    {
        this->temperature = temperature;
        this->humidity = humidity;
        display();
    }

    void display()
    {
        std::cout << "Condiciones actuales: " << temperature << " grados Farenheit y " << humidity << "% de humedad" << std::endl;
    }
};

class StatisticsDisplay : public Observer, public DisplayElement
{
private:
    std::vector<float> temperatureVector;
    float avg = -1, max = -INFINITY, min = INFINITY;
    Subject *weatherData;

public:
    StatisticsDisplay(Subject *weatherData)
    {
        this->weatherData = weatherData;
        weatherData->registerObserver(this);
    }

    void update(float temperature, float humidity, float pressure)
    {
        this->temperatureVector.push_back(temperature);
        avg = 0;
        for (auto i : temperatureVector)
        {
            avg += i;
            if (max < i)
                max = i;
            if (min > i)
                min = i;
        }
        avg /= temperatureVector.size();
        display();
    }

    void display()
    {
        std::cout << "Promedio/Máximo/Mínimo de temperatura = " << avg << "/" << max << "/" << min << std::endl;
    }
};

class ForecastDisplay : public Observer, public DisplayElement
{
private:
    float temperature = 0, humidity = 0, pressure = 0;
    int messageIndex = 0;
    std::array<std::string, 10> messages = {
        "Todo bien.",
        "Un poco de frío.",
        "Un poco de calor.",
        "Un poco de presión",
        "Un poco menos de presión.",
        "Parece que va a llover.",
        "El cielo se está nublando.",
        "Ay, mamá. Me estoy mojando.",
        "Qué calor.",
        "Bendito frío."};
    Subject *weatherData;

public:
    ForecastDisplay(Subject *weatherData)
    {
        this->weatherData = weatherData;
        weatherData->registerObserver(this);
    }

    void update(float temperature, float humidity, float pressure)
    {
        if (temperature > this->temperature)
        {
            messageIndex = 2;
            if (temperature > this->temperature * 1.3)
            {
                messageIndex = 8;
            }
        }
        else if (temperature < this->temperature)
        {
            messageIndex = 1;
            if (temperature < this->temperature * 0.6)
            {
                messageIndex = 9;
            }
        }
        else if (humidity > this->humidity)
        {
            messageIndex = 5;
            if (humidity > this->humidity * 1.01)
            {
                messageIndex = 6;
            }
            if (humidity > this->humidity * 1.1)
            {
                messageIndex = 7;
            }
        }
        else if (pressure > this->pressure)
        {
            messageIndex = 3;
        }
        else if (pressure < this->pressure)
        {
            messageIndex = 3;
        }
        else
        {
            messageIndex = 0;
        }
        this->temperature = temperature;
        this->humidity = humidity;
        this->pressure = pressure;
        display();
    }

    void display()
    {
        std::cout << "Pronóstico: " << messages[messageIndex] << std::endl;
    }
};

class HeatIndexDisplay : public Observer, public DisplayElement
{
private:
    float heatIndex;
    Subject *weatherData;

public:
    HeatIndexDisplay(Subject *weatherData)
    {
        this->weatherData = weatherData;
        weatherData->registerObserver(this);
    }

    void update(float temperature, float humidity, float pressure)
    {
        heatIndex = 16.923 + 1.85212e-1 * temperature + 5.37941 * humidity - 1.00254e-1 * temperature * humidity + 9.41695e-3 * temperature * temperature + 7.28898e-3 * humidity * humidity + 3.45372e-4 * temperature * temperature * humidity - 8.14971e-4 * temperature * humidity * humidity + 1.02102e-5 * temperature * temperature * humidity * humidity - 3.8646e-5 * temperature * temperature * temperature + 2.91583e-5 * humidity * humidity * humidity + 1.42721e-6 * temperature * temperature * temperature * humidity + 1.97483e-7 * temperature * humidity * humidity * humidity - 2.18429e-8 * temperature * temperature * temperature * humidity * humidity + 8.43296e-10 * temperature * temperature * humidity * humidity * humidity - 4.81975e-11 * temperature * temperature * temperature * humidity * humidity * humidity;
        display();
    }

    void display()
    {
        std::cout << "La sensación térmica es de " << heatIndex << " grados Farenheit" << std::endl;
    }
};

int main()
{
    WeatherData *weatherData = new WeatherData();
    CurrentConditionsDisplay *currentDisplay = new CurrentConditionsDisplay(weatherData);
    StatisticsDisplay *statisticsDisplay = new StatisticsDisplay(weatherData);
    ForecastDisplay *forecastDisplay = new ForecastDisplay(weatherData);
    HeatIndexDisplay *heatIndexDisplay = new HeatIndexDisplay(weatherData);

    weatherData->setMeasurements(80, 65, 30.4f);
    weatherData->setMeasurements(82, 70, 29.2f);
    weatherData->setMeasurements(78, 75, 29.2f);
    weatherData->setMeasurements(78, 75.06, 29.2f);
    weatherData->setMeasurements(78, 77, 29.2f);
    weatherData->setMeasurements(78, 77.02, 29.2f);
    weatherData->setMeasurements(78, 92, 29.2f);
}