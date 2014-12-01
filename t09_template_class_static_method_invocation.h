#include <iostream>

template <class T>
class t9_template_class_static_method_invocation
{
public:
    t9_template_class_static_method_invocation (void)
    {
        
    }
    virtual ~t9_template_class_static_method_invocation ()
    {
        
    }
    static std::string test_fn(void);

};

template <class T>
std::string t9_template_class_static_method_invocation<T>::test_fn(void)
{
    return "In the static function\n";
}

