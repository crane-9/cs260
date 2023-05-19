#ifndef IN_CLASS_HASH
#define IN_CLASS_HASH

#include <string>

using std::string;


class Hashtable {
    private:
        int capacity;
        int size;
        string *values;

        int hash(string input);

    public:
        Hashtable(int initCapacity = 16);
        ~Hashtable(); // deleted OR leaves scope?

        string access(int position);
        int add(string newKey); // status code return
        string find(string key);
        string remove(string key);
};

#endif
