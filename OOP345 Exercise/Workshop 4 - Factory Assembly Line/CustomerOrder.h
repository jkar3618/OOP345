#ifndef CUSTOMERORDER_H
#define CUSTOMERORDER_H

#include <iostream>
#include <string>
#include <vector>
#include "Station.h"

namespace seneca
{
    class CustomerOrder {
    private:
        struct Item {
            std::string m_itemName;
            size_t m_serialNumber{ 0 };
            bool m_isFilled{ false };

            Item(const std::string& src) : m_itemName(src) {}
        };

        std::string m_name;          // Customer's name
        std::string m_product;       // Product being assembled
        size_t m_cntItem{ 0 };       // Number of items in the order
        Item** m_lstItem{ nullptr }; // Dynamically allocated array of items
        static size_t m_widthField;  // Maximum width for item name

    public:
        CustomerOrder(const std::string& record);
        CustomerOrder(const CustomerOrder&) = delete; 
        CustomerOrder& operator=(const CustomerOrder&) = delete; 
        CustomerOrder(CustomerOrder&&) noexcept;
        CustomerOrder& operator=(CustomerOrder&&) noexcept;
        ~CustomerOrder();

        bool isOrderFilled() const;
        bool isItemFilled(const std::string& itemName) const;
        void fillItem(Station& station, std::ostream& os);
        void display(std::ostream& os) const;

        static void setWidthField(size_t width);
        static size_t getWidthField();
    };
}


#endif // CUSTOMERORDER_H
