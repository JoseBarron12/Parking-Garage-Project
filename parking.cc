//***************************************************************************
//
// Jose Barron
// Z02013735
// Fall 2023 CSCI 340 - PE1 Data Struct Algorithm Analysis
// Assignment 05: This program is intended to simulate a parking garage
// that holds a single lane of up to 10 cars. The program uses the car and 
// garage classes to accomplish it.
// Due Date: 10/02/23
// I certify that this is my own work and where appropriate an extension
// of the starter code provided for the assignment.
//
//***************************************************************************

#include<iostream>
#include<deque>
#include<string>
#include<stack>
#include<fstream>


void get_input_vals(const std::string &line, char &xact_type, std::string &license)
{
    std::string info = line;
    xact_type = line[0];
    info.erase(info.length() - 1,1);
    license = info.substr(2);
}

class car
{
public:
    car(int id, const std::string &license) : id(id), license(license) {}

    /// Call this to increment the number of times the car has been moved.
    void move() { ++num_moves;}

    /// @return the number of times that the car has been moved.
    int get_num_moves() const { return num_moves;}
	
    /// @return A reference to the license for this car.
    const std::string &get_license() const {return license;}

    /**
    * Overload the << so this can print itself as:
    *    Car X with license plate "Y"
    ******************************************************************/
    friend std::ostream& operator<<(std::ostream& lhs, const car& rhs)
    {
        lhs << "Car " << rhs.id << " with license plate " << '"' << rhs.license << '"';
        return lhs;
    }

private:
    int id;                 ///< The ID number for this car (assigned by the garage)
    std::string license;    ///< license plate of this car.
    int num_moves = {0};    ///< how many times the car was moved within the garage.
};

class garage
{
public:
        garage(size_t limit = 10) : parking_lot_limit(limit) {}

        /// @param license The license of the car that has arrived.                                                           
        void arrival(const std::string &license)
        {
            car filler(next_car_id,license);
            std::cout << filler; 
            if ( parking_lot.size() == parking_lot_limit)
            {
                std::cout << " has arrived.\n";
                std::cout << "    But the garage is full!\n\n";
            }
            else 
            {
                std::cout << " has arrived.\n\n";
                parking_lot.push_back(filler);
                ++next_car_id;
            }
        }

        /// @param license The license of the car that has departed.                                                          
        void departure(const std::string &license)
        {
            bool found = false;
            int location;
            for(std::deque<car>::size_type i = 0; i != parking_lot.size(); ++i)
            {
                if ( parking_lot[i].get_license() == license)
                {
                    found = true;
                    location = i;
                }
            }
            if ( ! found)
            {
                std::cout << "No car with license plate " << '"' << license << '"';
                std::cout << " is in the garage.";
            }
            else
            {
                std::stack<car> filler;
                int i = 0;
                while( i < location)
                {
                    parking_lot[i].move();
                    filler.push(parking_lot[i]);
                    ++i;
                }
                for (int j = 0; j < i; ++j)
                {
                    parking_lot.pop_front();
                }
                std::cout << parking_lot[0];
                std::cout << " has departed,\n"<< "    car was moved "<< parking_lot[0].get_num_moves() + 1;
                if (parking_lot[0].get_num_moves() + 1 == 1)
                {
                    std::cout   << " time ";
                }
                else
                {
                    std::cout   << " times ";
                }
                std::cout << "in the garage.\n\n";
                parking_lot.pop_front();
                while(!filler.empty())
                {
                    parking_lot.push_front(filler.top());
                    filler.pop();
                } 
            }
        }

private:
        int next_car_id = { 1 };
        std::deque<car> parking_lot;
        size_t parking_lot_limit;
};

int main()
{
    garage Garage;
    std::string info;
    std::string license;
    char indicator;
    while(std::getline(std::cin,info))
    {
        get_input_vals(info,indicator,license);
        if (indicator == 'A')
        {
           Garage.arrival(license);
        }
        else if (indicator == 'D')
        {
            Garage.departure(license);
        }
        else
        {
            std::cout << "'" << info[0] << "'" << ": invalid action!\n\n";
        }

    }
    
    return 0;
}
