#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <numeric>
#include <list>

using namespace std;

enum class BookGenre {
	Fiction, NonFiction, Mystery, ScienceFiction
};

struct Book {
	std::string title;
	BookGenre genre;
	std::string author;
	double price{};
};

/*

Create a function named compileReadingList that receives a library of Books as the parameter (std::vector)
and returns a list of Books.
This function performs the following tasks:

1. Print to the screen the number of books in the library written by "Agatha Christie" or "Arthur Conan Doyle".

2. Sort the library of books based on their genre in the order of Fiction, NonFiction, Mystery, ScienceFiction.

3. Create a list of Books, the reading list (which will be the return value of this function),
	that contains only Fiction and Mystery genres where the price is less than 20 dollars.

4. Add to the reading list the first ScienceFiction book in the library.

5. Calculate the total price of all the Books in the reading list and print it to the screen.

***Do not use manual loops!***

***Do not use the same algorithm more than once!***

*/

list<Book> comileReadingList(vector<Book>& b)
{
	int cnt = count_if(b.begin(), b.end(), [](Book& b) {
		return b.author = "Agatha Christie" || b.author == "Arthur Conan Doyle";
		});

	cout << cnt;

	sort(b.begin(), b.end(), [](Book& b1, Book& b2) {
		return b1.genre < b2.genre;
		});

	list<Book> newList;

	auto itr = copy_if(b.begin(), b.end(), back_inserter(newList), [](Book& b) {
		return (b.genre == BookGenre::Fiction || b.genre == BookGenre::Mystery) && b.price < 20;
		});

	auto sf = find_if(b.begin(), b.end(), [](const Book& b) {
		return b.genre == BookGenre::ScienceFiction;
		});

	newList.push_front(*sf);

	double totalPrice = accumulate(b.begin(), b.end(), 0.0, [](double total, const Book& b) {
		return total + b.price;
		});

	
}















//std::list<Book> compileReadingList(std::vector<Book>& b)
//{
//	int cnt = std::count_if(b.begin(), b.end(), [](const Book& b) {
//		return b.author == "Agatha Christie" || b.author == "Arthur Conan Doyle";
//		});
//
//
//	std::sort(b.begin(), b.end(), [](const Book& b1, const Book& b2) {
//		return b1.genre < b2.genre;
//		});
//
//	std::list<Book> newList;
//	
//	std::copy_if(b.begin(), b.end(), std::back_inserter(newList), [](const Book& b) {
//		return (b.genre == BookGenre::Fiction || b.genre == BookGenre::Mystery) && b.price < 20;
//		});
//
//	auto itr = std::find_if(b.begin(), b.end(), [](const Book& b) {
//		return b.genre == BookGenre::ScienceFiction;
//		});
//
//	newList.push_front(*itr);
//
//	double itr = std::accumulate(newList.begin(), newList.end(), 0.0, [](double total, const Book& b) {
//		return total + b.price;
//		});
//
//}