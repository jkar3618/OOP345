//*****************************************************************************
//<assessment name : Workshop - #3>
//  Full Name : Taehwa Hong
//  Student ID# : 132546227
//	Email : thong14@myseneca.ca
//	Section : OOP345 NDD
//	Authenticity Declaration :
//I declare this submission is the result of my own work and has not been
//shared with any other student or 3rd party content provider.This submitted
//piece of work is entirely of my own creation.
//* ****************************************************************************
#ifndef SENECA_COLLECTION_H
#define SENECA_COLLECTION_H
#include <string>
#include <vector>
#include "mediaItem.h"

namespace seneca
{

    class Collection
    {
        std::string m_name;
        std::vector<MediaItem*> m_item;
        void(*m_observer)(const Collection&, const MediaItem&);

    public:
        Collection(const std::string& name);
        ~Collection();

        Collection(const Collection& src) = delete;
        Collection& operator=(const Collection& src) = delete;
        Collection(Collection&& src) = delete;
        Collection& operator=(Collection&& src) = delete;

        const std::string& name() const;
        size_t size() const;
        void setObserver(void (*observer)(const Collection&, const MediaItem&));
        Collection& operator+=(MediaItem* item);
        MediaItem* operator[](size_t idx) const;
        MediaItem* operator[](const std::string& title) const;
        void removeQuotes();
        void sort(const std::string& field);

        friend std::ostream& operator<<(std::ostream& out, const Collection& collection);
    };
}

#endif
