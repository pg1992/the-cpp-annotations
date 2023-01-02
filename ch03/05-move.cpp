/*!
 * \brief There are 2 types of data: Data and Data2.  Data has 2 types of init:
 * from raw string, or from another Data object.  Data2 has 3 types of init:
 * the same from Data, and another that takes a temporary (rvalue reference).
 *
 * If the object is temporary, there is no need to create another memory.
 * Just changing the pointers is enough (saves on strdup calls).
 */

#include <iostream>
#include <cstring>

int strdup_calls = 0;

struct Data
{
    char *text;

    /*!
     * \brief Initializes an object with given "txt".
     */
    void init(char const *txt) {
        std::cout << "duplicating string in Data.init(char const*)\n";
        strdup_calls++;
        text = strdup(txt);
    }

    /*!
     * \brief Copies the "text" member from another object.
     */
    void init(Data const &other) {
        std::cout << "duplicating string in Data.init(Data const&)\n";
        strdup_calls++;
        text = strdup(other.text);
    }
};

/*!
 * \brief Creates temporary object initialized with "text".
 */
Data dataFactory(char const *text)
{
    std::cout << "Creating and initializing temp object\n";

    Data d;
    d.init(text);

    return d;
}

struct Data2
{
    char *text;

    /*!
     * \brief Initializes an object with given "txt".
     */
    void init(char const *txt) {
        std::cout << "duplicating string in Data2.init(char const*)\n";
        strdup_calls++;
        text = strdup(txt);
    }

    /*!
     * \brief Copies the "text" member from another object.
     */
    void init(Data2 const &other) {
        std::cout << "duplicating string in Data2.init(Data2 const&)\n";
        strdup_calls++;
        text = strdup(other.text);
    }

    /*!
     * \brief Initializes "text" by pointing to the "text" member of temporary object.
     */
    void init(Data2 &&other) {
        std::cout << "changing pointer in Data2.init(Data const&)\n";
        text = other.text;
        other.text = 0;
    }
};

/*!
 * \brief Creates temporary object initialized with "text".
 */
Data2 dataFactory2(char const *text)
{
    std::cout << "Creating and initializing temp object\n";

    Data2 d;
    d.init(text);

    return d;
}

int main()
{
    Data d1;

    // Create a temp object and initializes d1 with it.
    d1.init(dataFactory("object"));

    std::cout << "strdup was called " << strdup_calls << " times.\n\n";

    strdup_calls = 0;

    Data2 d2;
    d2.init(dataFactory2("object"));
    std::cout << "strdup was called " << strdup_calls << " times.\n";

    return 0;
}
