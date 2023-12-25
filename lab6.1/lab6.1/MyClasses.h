#include <iostream>
#include <string>

class Computer {
public:
    Computer(const Computer& other) {
        setModel(other.model);
        setOwner(other.owner);
    }
    char* getModel() {
        return model;
    }
    char* getOwner() {
        return owner;
    }
    void setModel(const char* newModel) {
        strncpy_s(model, newModel, 79);
        model[79] = '\0';
    }
    void setOwner(const char* newOwner) {
        strncpy_s(owner, newOwner, 79);
        owner[79] = '\0';
    }
    Computer(const char* model, const char* owner) {
        setModel(model);
        setOwner(owner);
    }
    virtual int getType() {
        return type;
    }
    virtual std::string createSaveString() {
        return std::string(model) + "\n" + owner + "\n";
    }
    virtual std::string createPrintString() {
        return "Model: " + std::string(model) + "\n" + "Owner: " + std::string(owner) + '\n';
    }
    Computer() {

    };
private:
    char model[80];
    char owner[80];
    const int type = 1;
};

class Desktop : public Computer {
public:
    char* getBox() {
        return box;
    }
    Desktop(const Desktop& other) : Computer(other) {
        setBox(other.box);
    }
    void setBox(const char* newBox) {
        strncpy_s(box, newBox, 79);
        box[79] = '\0';
    }
    Desktop(const char* model, const char* owner, const char* box) : Computer(model, owner) {
        setBox(box);
    }
    virtual std::string createSaveString() override {
        return Computer::createSaveString() + box + '\n';
    }
    virtual std::string createPrintString() override {
        return Computer::createPrintString() + "box: " + box + '\n';
    }
    virtual int getType() {
        return type;
    }
    Desktop() {

    };
private:
    char box[80];
    const int type = 2;
};

class Portable : public Computer {
public:
    int getPower() {
        return power;
    }
    Portable(const Portable& other) : Computer(other) {
        setPower(other.power);
        setScreensize(other.screensize);
    }
    void setPower(int newPower) {
        power = newPower;
    }
    double getScreensize() {
        return screensize;
    }
    void setScreensize(double newScreensize) {
        screensize = newScreensize;
    }
    Portable(const char* model, const char* owner, int power, double screensize) : Computer(model, owner) {
        setPower(power);
        setScreensize(screensize);
    }
    virtual std::string createSaveString() override {
        return Computer::createSaveString() + std::to_string(power) + "\n" + std::to_string(screensize) + '\n';
    }
    virtual std::string createPrintString() override {
        return Computer::createPrintString() + "power: " + std::to_string(power) + '\n' + "scrensize: " + std::to_string(screensize) + '\n';
    }
    virtual int getType() {
        return type;
    }
    Portable() {

    };
private:
    int power;
    double screensize;
    const int type = 3;
};

class Monoblock : public Desktop {
public:
    double getScreensize() {
        return screensize;
    }
    Monoblock(const Monoblock& other) : Desktop(other) {
        setScreensize(other.screensize);
    }
    void setScreensize(double newScreensize) {
        screensize = newScreensize;
    }
    Monoblock(const char* model, const char* owner, const char* box, double screensize) : Desktop(model, owner, box) {
        setScreensize(screensize);
    }
    virtual std::string createSaveString() override {
        return Desktop::createSaveString() + std::to_string(screensize) + '\n';
    }
    virtual std::string createPrintString() override {
        return Desktop::createPrintString() + "scrensize: " + std::to_string(screensize) + '\n';
    }
    virtual int getType() {
        return type;
    }
    Monoblock() {

    };
private:
    double screensize;
    const int type = 4;
};

class Laptop : public Portable {
public:
    int getCountOfKeys() {
        return countOfKeys;
    }
    void setCountOfKeys(int newCountOfKeys) {
        countOfKeys = newCountOfKeys;
    }
    Laptop(const Laptop& other) : Portable(other) {
        setCountOfKeys(other.countOfKeys);
    }
    Laptop(const char* model, const char* owner, int power, double screensize, int countOfKeys) : Portable(model, owner, power, screensize) {
        setCountOfKeys(countOfKeys);
    }
    virtual std::string createSaveString() override {
        return Portable::createSaveString() + std::to_string(countOfKeys) + '\n';
    }
   virtual std::string createPrintString() override {
        return Portable::createPrintString() + "Count Of keys: " + std::to_string(countOfKeys) + '\n';
    }
    virtual int getType() {
        return type;
    }
    Laptop() {

    };
private:
    int countOfKeys;
    const int type = 5;
};

class Tablet : public Portable {
public:
    char* getModem() {
        return modem;
    }
    void setModem(const char* newModem) {
        strncpy_s(modem, newModem, 79);
        modem[79] = '\0';
    }
    Tablet(const char* model, const char* owner, int power, double screensize, const char* modem) : Portable(model, owner, power, screensize) {
        setModem(modem);
    }
    virtual std::string createSaveString() override {
        return Portable::createSaveString() + modem + '\n';
    }
    virtual std::string createPrintString() override {
        return Portable::createPrintString() + "modem: "+ modem  + '\n';
    }
    Tablet(const Tablet& other) : Portable(other) {
        setModem(other.modem);
    }
    virtual int getType() {
        return type;
    }
    Tablet() {

    };
private:
    char modem[80];
    const int type = 6;
};
