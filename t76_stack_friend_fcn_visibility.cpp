#include <boost/smart_ptr.hpp>
#include <iostream>
#include <ostream>

template <typename T> void draw(const T &t, std::ostream &out) {
    std::cout << "Template version" << '\n';
    out << t << '\n';
}

class object_t {
  public:
    template <typename T> explicit object_t(T rhs) : self(new model<T>(rhs)){};

    friend void draw(const object_t &obj, std::ostream &out) { obj.self->draw(out); }

  private:
    struct concept_t {
        virtual ~concept_t(){};
        virtual void draw(std::ostream &) const = 0;
    };

    template <typename T> struct model : concept_t {
        model(T rhs) : data(rhs){};
        void draw(std::ostream &out) const {
            using ::draw;
            draw(data, out);
        }

        T data;
    };

    boost::scoped_ptr<concept_t> self;
};

class MyClass {};

void draw(const MyClass &, std::ostream &out) {
    std::cout << "MyClass version" << '\n';
    out << "MyClass" << '\n';
}

int main() {
    object_t first(1);
    draw(first, std::cout);

    const object_t second((MyClass()));
    draw(second, std::cout);

    return 0;
}
