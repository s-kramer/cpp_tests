#include <iostream>/*{{{*/
#include <vector>
#include <ostream>
#include <algorithm>
#include <boost/bind.hpp>
#include <string>
#include <boost/ref.hpp>
#include <memory>/*}}}*/

template <typename T>
void draw(const T& obj, std::ostream& stream, int position)
{ stream << std::string(" ", position) << obj  << '\n'; }

class object_t
{
    public:
        template <typename T>
        object_t (T rhs) : self(new modelDrawable<T>(rhs)) {};

        friend void draw(const object_t& obj, std::ostream& stream, int position)
        { obj.self->draw_(stream, position); }

    private:
        struct concept_t
        {
            virtual ~concept_t() {};
            virtual void draw_(std::ostream&, int) const = 0;
        };

        template <typename T>
        struct modelDrawable : concept_t
        {
            modelDrawable (T rhs) : value(rhs) {};
            void draw_(std::ostream& stream, int position) const override
            { draw(value, stream, position); }

            T value;
        };

        std::unique_ptr<concept_t> self;
};

typedef std::vector<object_t> document_t;

void draw (const document_t& doc, std::ostream& stream, int position)
{
    stream << "<document>" << '\n';
    std::for_each(doc.begin(), doc.end(), [&](const object_t& obj) { draw(obj, stream, position + 2); });
    stream << "</document>" << '\n';
}

class myClass {};

void draw(const myClass&, std::ostream& stream, int position)
    // template <>
    // void draw<myClass>(const myClass&, std::ostream& stream, int position)
{
    stream << std::string(" ", position) << "myClass" << '\n';
}

int main()
{
    document_t doc;
    doc.push_back(object_t(1));
    doc.push_back(object_t(2));
    doc.push_back(object_t(myClass()));
    doc.push_back(object_t(4));

    draw(doc, std::cout, 0);

    return 0;
}
