

// The Five Special Member Functions

// Destructor
// ~ClassName();
// Releases the resource.

// Copy Constructor
// ClassName(const ClassName &other);
// Creates a deep copy of the resource.

// Copy Assignment Operator
// ClassName &operator=(const ClassName &other);
// Replaces existing resource with a copy.

// Move Constructor
// ClassName(ClassName &&other) noexcept;
// Takes ownership of the resource from a temporary object.

// Move Assignment Operator
// ClassName &operator=(ClassName &&other) noexcept;
// Replaces resource by stealing from another object.

// Why is it needed?
// Because default - generated functions do shallow copies.

// Example problem:
// class Bad
// {
//   int *data;
//   public:
//   Bad(int v) { data = new int(v); }
// };

// Compiler - generated copy constructor will copy data pointer → double delete when both objects are destroyed create the error.

#include <iostream>
using namespace std;

class Buffer
{
    int *data;

public:
    // 1. Constructor
    Buffer(int v = 0) : data(new int(v)) {}

    // 2. Destructor
    ~Buffer()
    {
        delete data;
    }

    // 3. Copy constructor
    Buffer(const Buffer &other)
    {
        data = new int(*other.data);
    }

    // 4. Copy assignment
    Buffer &operator=(const Buffer &other)
    {
        if (this != &other)
        {
            delete data;
            data = new int(*other.data);
        }
        return *this;
    }

    // 5. Move constructor
    Buffer(Buffer &&other) noexcept
    {
        data = other.data;
        other.data = nullptr;
    }

    // 6. Move assignment
    Buffer &operator=(Buffer &&other) noexcept
    {
        if (this != &other)
        {
            delete data;
            data = other.data;
            other.data = nullptr;
        }
        return *this;
    }
};
