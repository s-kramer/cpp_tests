#include <iostream>
#include <vector>
#include <ostream>
#include <algorithm>
#include <boost/bind.hpp>
#include <string>
#include <boost/ref.hpp>
#include <memory>

template <typename T>
void draw(const T& obj, std::ostream& stream, int position)
{
    stream << std::string(" ", position) << obj  << '\n';
}

class object_t
{
public:
    template <typename T>
    object_t (const T& rhs) : self(new modelDrawable<T>(rhs)) {};

    friend void draw(const object_t& obj, std::ostream& stream, int position)
    {
        // stream << std::string(" ", position) << obj << '\n';
        obj.self->draw(stream, position);
    }

private:
    class concept_t
    {
    public:
        virtual ~concept_t() {};
        virtual void draw(std::ostream&, int) const = 0;
    };

    template <typename T>
    class modelDrawable : public concept_t
    {
    public:
        explicit modelDrawable (T rhs) : value(rhs) {};
        void draw(std::ostream& stream, int position) const
        {
            ::draw(value, stream, position);
        }
    private:
        T value;
    };

private:
    std::unique_ptr<concept_t> self;
};

typedef std::vector<object_t> document_t;

void draw (const document_t& doc, std::ostream& stream, int position)
{
    stream << "<document>" << '\n';
    std::for_each(doc.begin(), doc.end(), [&](const object_t& obj) { draw(obj, stream, position + 2); });
    stream << "</document>" << '\n';
}

class myClass
{ };

void draw(const myClass&, std::ostream& stream, int position)
{
    stream << std::string(" ", position) << "myClass" << '\n';
}

int main()
{
    document_t doc;
    doc.push_back(1);
    doc.push_back(2);
    doc.push_back(myClass());
    doc.push_back(4);

    draw(doc, std::cout, 0);

    return 0;
}
