#pragma once
class Device {
public:
    Device() = default;
    Device(const char* make);
    Device(const Device& other);
    virtual ~Device();
    Device& operator=(const Device& other);

    virtual void print() const = 0;
    virtual int getPerformance() const = 0;
    virtual Device* clone() const = 0;

private:
    void setStr(const char* str);
    void clear();
protected:
    char* make = nullptr;
};
