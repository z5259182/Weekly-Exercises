#include <iostream>
#include <string>

class Staff {
public:
    Staff() : mName{}, mAge{0}, mPhoneNum{}, mTitle{}, mID{0}{
        std::cout << "An empty staff profile is created.\n";
    }; //default constructor
    Staff (std::string name, int age, std::string phoneNum, std::string title, int ID)
        : mName{name}, mAge{age}, mPhoneNum{phoneNum}, mTitle{title}, mID{ID}
    {
            std::cout << name << "'s staff profile is created.\n";
    };//overloaded constructor
    
    std::string getName() const;
    int getID() const;
    int getAge() const;
    std::string getPhoneNum() const;
    std::string getTitle() const;

    void setName(std::string name);
    void setID(int ID);
    void setAge(int age);
    void setPhoneNum(std::string phoneNum);
    void setTitle(std::string title);
    
private:
    std::string mName;
    int mAge;
    std::string mPhoneNum;
    std::string mTitle;
    int mID;
};

std::string Staff::getName() const{
    std::cout << "The staff's name is " << mName << ".\n";
    return mName;
}

int Staff::getID() const{
    std::cout << mName << "'s staff ID is " << mID << ".\n";
    return mID;
}

int Staff::getAge() const {
    std::cout << mName << "'s age is " << mAge << ".\n";
    return mAge;
}

std::string Staff::getPhoneNum() const{
    std::cout << mName << "'s phone number is " << mPhoneNum << ".\n";
    return mPhoneNum;
}

std::string Staff::getTitle() const{
    std::cout << mName << "'s title is " << mTitle << ".\n";
    return mTitle;
}

void Staff::setName(std::string name){
    std::cout << mName << "'s name is set to be " << name << ".\n";
    mName = name;
}

void Staff::setID(int ID){
    std::cout << mName << "'s staff ID is set to be " << ID << ".\n";
    mID = ID;
}
void Staff::setAge(int age){
    std::cout << mName << "'s age is set to be " << age << ".\n";
    mAge = age;
}

void Staff::setPhoneNum(std::string phoneNum){
    std::cout << mName << "'s phone number is set to be " << phoneNum << ".\n";
    mPhoneNum = phoneNum;
}
void Staff::setTitle(std::string title){
    std::cout << mName << "'s title is set to be " << title << ".\n";
    mTitle = title;
}

int main () {
    Staff staff("Calvin", 23, "0401234567", "Head Demo", 1234567);
    staff.getName();
    return 0;
}